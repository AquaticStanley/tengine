#include "Dash.h"
#include "../Components/Player/Player.h"
#include <iostream>

void Dash::apply(PlayerPhysicsComponent* physics, World& world) {
    (void)world;
    using namespace AbilityConstants::Dash;

    // Prevent the player from changing direction
    physics->canMove_ = false;

    // Set velocity in current direction to a relatively high value
    if(framesLeft_ == ACTIVE_FRAMES) {
        speedToApply_ = sf::Vector2f{0.0, 0.0};

        if(physics->isIdle()) {
            if(physics->facingUp_) {
                speedToApply_.y += DASH_VELOCITY;
            } else if(physics->facingDown_) {
                speedToApply_.y -= DASH_VELOCITY;
            } else {
                // Dash in whatever direction we're facing
                if(physics->facingRight_) {
                    speedToApply_.x += DASH_VELOCITY;
                } else {
                    speedToApply_.x -= DASH_VELOCITY;
                }
            }
        } else {
            // Player is not idle
            if(physics->facingUp_) {
                speedToApply_.y += max_diagonal_velocity(DASH_VELOCITY);
                if(physics->facingRight_) {
                    speedToApply_.x += max_diagonal_velocity(DASH_VELOCITY);
                } else {
                    speedToApply_.x -= max_diagonal_velocity(DASH_VELOCITY);
                }
            } else if(physics->facingDown_) {
                speedToApply_.y -= max_diagonal_velocity(DASH_VELOCITY);
                if(physics->facingRight_) {
                    speedToApply_.x += max_diagonal_velocity(DASH_VELOCITY);
                } else {
                    speedToApply_.x -= max_diagonal_velocity(DASH_VELOCITY);
                }
            } else {
                // Player is moving perfectly side to side
                if(physics->facingRight_) {
                    speedToApply_.x += DASH_VELOCITY;
                } else {
                    speedToApply_.x -= DASH_VELOCITY;
                }
            }
        }
    }

    std::cout << "Setting to (" << speedToApply_.x << ", " << speedToApply_.y << ")" << std::endl;
    physics->velocity_ = speedToApply_;
    physics->acceleration_ = sf::Vector2f(0.0, 0.0);
    framesLeft_ -= 1;

    if(framesLeft_ == 0) {
        physics->canMove_ = true;

        // Set speed to same direction, but of magnitude equal to max walking speed.
        if(speedToApply_.x > 0) {
            physics->velocity_.x = CompConstants::Player::WALK_TOP_SPEED;
        } else if(speedToApply_.x < 0) {
            physics->velocity_.x = CompConstants::Player::WALK_TOP_SPEED * -1;
        }

        if(speedToApply_.y > 0) {
            physics->velocity_.y = CompConstants::Player::WALK_TOP_SPEED;
        } else if(speedToApply_.y < 0) {
            physics->velocity_.y = CompConstants::Player::WALK_TOP_SPEED * -1;
        }
    }
    return;
}
