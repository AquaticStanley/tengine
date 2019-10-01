#include "Player.h"

void PlayerPhysicsComponent::update(World& world) {
    using namespace CompConstants::Player;

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
            if(isOnGround_) {
                PhysicsComponent::velocity_.x = std::max(PhysicsComponent::velocity_.x - IDLE_X_ACCELERATION_GROUND, 0.0);
            } else {
                PhysicsComponent::velocity_.x = std::max(PhysicsComponent::velocity_.x - IDLE_X_ACCELERATION_AIR, 0.0);
            }
        } else {
            if(isOnGround_) {
                PhysicsComponent::velocity_.x = std::min(PhysicsComponent::velocity_.x + IDLE_X_ACCELERATION_GROUND, 0.0);
            } else {
                PhysicsComponent::velocity_.x = std::min(PhysicsComponent::velocity_.x + IDLE_X_ACCELERATION_AIR, 0.0);
            }
        }
    }

    // Set player position due to velocity changes
    PhysicsComponent::position_ += PhysicsComponent::velocity_;

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

void PlayerPhysicsComponent::clearLeftRight() {
    walkingRight_ = false;
    walkingLeft_ = false;
    floatingRight_ = false;
    floatingLeft_ = false;
}

bool PlayerPhysicsComponent::isIdle() {
    return !(walkingRight_ || walkingLeft_ || floatingRight_ || floatingLeft_);
}
