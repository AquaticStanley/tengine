#include "Player.h"
#include <iostream>

void PlayerPhysicsComponent::update(World& world) {
    using namespace CompConstants::Player;

    if(NormalPhysicsComponent::canMove_) {
        // Modify horizontal movement
        if(std::abs(PlayerPhysicsComponent::velocity_.x) < WALK_TOP_SPEED) {
            if(walkingRight_) {
                PhysicsComponent::velocity_.x += WALK_ACCELERATION_GROUND;
            } else if(walkingLeft_) {
                PhysicsComponent::velocity_.x -= WALK_ACCELERATION_GROUND;
            } else if(floatingRight_) {
                PhysicsComponent::velocity_.x += WALK_ACCELERATION_AIR;
            } else if(floatingLeft_) {
                PhysicsComponent::velocity_.x -= WALK_ACCELERATION_AIR;
            } else if(isIdle()) {
                if(PlayerPhysicsComponent::velocity_.x > 0) {
                    if(NormalPhysicsComponent::isOnGround_) {
                        PhysicsComponent::velocity_.x = std::max(PhysicsComponent::velocity_.x - IDLE_X_ACCELERATION_GROUND, 0.0);
                    } else {
                        PhysicsComponent::velocity_.x = std::max(PhysicsComponent::velocity_.x - IDLE_X_ACCELERATION_AIR, 0.0);
                    }
                } else {
                    if(NormalPhysicsComponent::isOnGround_) {
                        PhysicsComponent::velocity_.x = std::min(PhysicsComponent::velocity_.x + IDLE_X_ACCELERATION_GROUND, 0.0);
                    } else {
                        PhysicsComponent::velocity_.x = std::min(PhysicsComponent::velocity_.x + IDLE_X_ACCELERATION_AIR, 0.0);
                    }
                }
            }
        } else {
            // Apply deceleration for soft movement speed cap
            if(PlayerPhysicsComponent::velocity_.x > 0) {
                PlayerPhysicsComponent::velocity_.x -= SOFT_CAP_DECELERATION;
            } else {
                PlayerPhysicsComponent::velocity_.x += SOFT_CAP_DECELERATION;
            }
        }

        // Modify vertical movement for jumping
        if(jumping_ && !jumpIP_) {
            if(NormalPhysicsComponent::isOnGround_) {
                PhysicsComponent::velocity_.y += JUMP_VELOCITY;
                NormalPhysicsComponent::isOnGround_ = false;
                jumpIP_ = true;
                jumping_ = false;
            } else if(slidingDownWall()) {
                if(facingRight_) {
                    PhysicsComponent::velocity_ = WALL_JUMP_VELOCITY_LEFT;
                } else {
                    PhysicsComponent::velocity_ = WALL_JUMP_VELOCITY_RIGHT;
                }
                NormalPhysicsComponent::isOnGround_ = false;
                jumping_ = false;
            }
        }
    }

    // Apply gravity acceleration
    if(NormalPhysicsComponent::isOnGround_) {
        PhysicsComponent::velocity_.y = 0;
    } else if(slidingDownWall()) {
        jumpIP_ = false;
        PhysicsComponent::velocity_.y += WALL_SLIDE_ACCELERATION;
        if(PlayerPhysicsComponent::velocity_.y < MAX_WALL_SLIDE_VELOCITY) {
            PlayerPhysicsComponent::velocity_.y = MAX_WALL_SLIDE_VELOCITY;
        }
    } else {
        jumpIP_ = true;
        PhysicsComponent::velocity_.y += WorldConstants::WORLD_GRAVITY_ACCELERATION;
    }

    if(PhysicsComponent::velocity_.y < TERMINAL_VELOCITY) {
        PhysicsComponent::velocity_.y = TERMINAL_VELOCITY;
    }

    // Cap movement speeds
    if(std::abs(PhysicsComponent::velocity_.x) >= WorldConstants::WORLD_X_SPEED_LIMIT) {
        if(PhysicsComponent::velocity_.x < 0) {
            PhysicsComponent::velocity_.x = WorldConstants::WORLD_X_SPEED_LIMIT * -1;
        } else {
            PhysicsComponent::velocity_.x = WorldConstants::WORLD_X_SPEED_LIMIT;
        }
    }

    if(std::abs(PhysicsComponent::velocity_.y) >= WorldConstants::WORLD_Y_SPEED_LIMIT) {
        if(PhysicsComponent::velocity_.y < 0) {
            PhysicsComponent::velocity_.y = WorldConstants::WORLD_Y_SPEED_LIMIT * -1;
        } else {
            PhysicsComponent::velocity_.y = WorldConstants::WORLD_Y_SPEED_LIMIT;
        }
    }

    // Apply player abilities as modifiers
    abilities_.applyActiveAbilities(this, world);

    // Set player position due to velocity changes
    PhysicsComponent::position_ += PhysicsComponent::velocity_;

    // Let world set several variables
    NormalPhysicsComponent::isOnGround_ = false;
    wallAdjacent_ = false;

    // Resolve world collision
    world.resolveNormalCollision(this);

    return;
}

void PlayerPhysicsComponent::setWalkingRight() {
    clearLeftRight();
    walkingRight_ = true;
    facingRight_ = true;
}

void PlayerPhysicsComponent::setWalkingLeft() {
    clearLeftRight();
    walkingLeft_ = true;
    facingRight_ = false;
}

void PlayerPhysicsComponent::setFloatingRight() {
    clearLeftRight();
    floatingRight_ = true;
    facingRight_ = true;
}

void PlayerPhysicsComponent::setFloatingLeft() {
    clearLeftRight();
    floatingLeft_ = true;
    facingRight_ = false;
}

void PlayerPhysicsComponent::setFacingUp() {
    facingUp_ = true;
    facingDown_ = false;
}

void PlayerPhysicsComponent::setFacingDown() {
    facingDown_ = true;
    facingUp_ = false;
}

void PlayerPhysicsComponent::clearUpDown() {
    facingUp_ = false;
    facingDown_ = false;
}

void PlayerPhysicsComponent::clearLeftRight() {
    walkingRight_ = false;
    walkingLeft_ = false;
    floatingRight_ = false;
    floatingLeft_ = false;
}

bool PlayerPhysicsComponent::isIdle() {
    return !(walkingRight_ || walkingLeft_ || floatingRight_ || floatingLeft_);
}

bool PlayerPhysicsComponent::slidingDownWall() {
    return wallAdjacent_ && !NormalPhysicsComponent::isOnGround_ && PhysicsComponent::velocity_.y < 0;
}
