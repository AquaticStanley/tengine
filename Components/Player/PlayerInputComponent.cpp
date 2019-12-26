#include "Player.h"

void PlayerInputComponent::update() {
    using namespace CompConstants::Player;

    if(physics_->canMove_) {
        if(sf::Keyboard::isKeyPressed(controlMap_[Inputs::Right])) {
            if(physics_->isOnGround_) {
                physics_->setWalkingRight();
            } else {
                physics_->setFloatingRight();
            }
        } else if(sf::Keyboard::isKeyPressed(controlMap_[Inputs::Left])) {
            if(physics_->isOnGround_) {
                physics_->setWalkingLeft();
            } else {
                physics_->setFloatingLeft();
            }
        } else {
            physics_->clearLeftRight();
        }
        if(!physics_->jumpIP_) {
            if(sf::Keyboard::isKeyPressed(controlMap_[Inputs::Jump])) {
                if(physics_->isOnGround_ || physics_->slidingDownWall()) {
                    physics_->jumping_ = true;
                }
            }
        } else {
            physics_->jumping_ = false;
            if(!sf::Keyboard::isKeyPressed(controlMap_[Inputs::Jump])) {
                physics_->jumpIP_ = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(controlMap_[Inputs::Up])) {
            physics_->setFacingUp();
        } else if(sf::Keyboard::isKeyPressed(controlMap_[Inputs::Down])) {
            physics_->setFacingDown();
        } else {
            physics_->clearUpDown();
        }
    }

    // Take care of possible abilities
    physics_->abilities_.updateAbilityInputs();

    return;
}