#include "Player.h"

void PlayerInputComponent::update() {
    if(physics_->canMove_) {
        if(sf::Keyboard::isKeyPressed(key_right)) {
            if(physics_->isOnGround_) {
                physics_->setWalkingRight();
            } else {
                physics_->setFloatingRight();
            }
        } else if(sf::Keyboard::isKeyPressed(key_left)) {
            if(physics_->isOnGround_) {
                physics_->setWalkingLeft();
            } else {
                physics_->setFloatingLeft();
            }
        } else {
            physics_->clearLeftRight();
        }
    }

    if(!physics_->jumpIP_) {
        if(sf::Keyboard::isKeyPressed(key_space)) {
            if(physics_->isOnGround_) {
                physics_->jumping_ = true;
            }
        }
    } else {
        physics_->jumping_ = false;
        if(!sf::Keyboard::isKeyPressed(key_space)) {
            physics_->jumpIP_ = false;
        }
    }

    return;
}