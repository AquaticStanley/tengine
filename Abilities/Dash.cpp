#include "Dash.h"
#include "../Components/Player/Player.h"
#include <iostream>

void Dash::apply(PlayerPhysicsComponent* physics, World& world) {
    (void)world;

    using namespace AbilityConstants::Dash;
    // Set velocity in current direction to a relatively high value
    sf::Vector2f velocity(0.0,0.0);

    if(physics->isIdle()) {
        if(physics->facingUp_) {
            velocity.y += DASH_VELOCITY;
        } else if(physics->facingDown_) {
            velocity.y -= DASH_VELOCITY;
        } else {
            // Dash in whatever direction we're facing
            if(physics->facingRight_) {
                velocity.x += DASH_VELOCITY;
            } else {
                velocity.x -= DASH_VELOCITY;
            }
        }
    } else {
        // Player is not idle
        if(physics->facingUp_) {
            velocity.y += max_diagonal_velocity(DASH_VELOCITY);
        } else if(physics->facingDown_) {
            velocity.y -= max_diagonal_velocity(DASH_VELOCITY);
        } else {
            // Player is moving perfectly side to side
            if(physics->facingRight_) {
                velocity.x += DASH_VELOCITY;
            } else {
                velocity.x -= DASH_VELOCITY;
            }
        }
    }

    std::cout << "Adding (" << velocity.x << ", " << velocity.y << ") to vel" << std::endl;
    physics->velocity_ = velocity;
    return;
}
