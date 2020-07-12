#include "PlayerAbilities.h"
#include <iostream>

PlayerAbilityManager::PlayerAbilityManager(Ability* ability)
// : complete_(true)
// , physicsReady_(false)
: ability_(ability) {}

bool PlayerAbilityManager::active() {
    return (ability_->framesLeft_ > 0);
}

void PlayerAbilityManager::reset() {
    ability_->reset();
}

PlayerAbilities::PlayerAbilities() {
    using namespace CompConstants::Player;
    // Set up keybinds (this should be configurable later on)
    abilityKeybinds_[AbilityInputs::Ability1] = sf::Keyboard::Key::A;
    abilityKeybinds_[AbilityInputs::Ability2] = sf::Keyboard::Key::S;
    abilityKeybinds_[AbilityInputs::Ability3] = sf::Keyboard::Key::D;
    abilityKeybinds_[AbilityInputs::Ability4] = sf::Keyboard::Key::F;
    
    // Slot in abilities
    abilities_.emplace(AbilityInputs::Ability1, PlayerAbilityManager(new Dash()));
    abilities_.emplace(AbilityInputs::Ability2, PlayerAbilityManager(new Dash()));
    abilities_.emplace(AbilityInputs::Ability3, PlayerAbilityManager(new Dash()));
    abilities_.emplace(AbilityInputs::Ability4, PlayerAbilityManager(new Dash()));
}

void PlayerAbilities::updateAbilityInputs() {
    // Check if any inputs are held down, and queue the ability to be used if so, setting it on cooldown appropriately
    // In other words, determine if we can use this ability and take care of "cleaning up" after it
    for(auto& [input, key] : abilityKeybinds_) {
        // Check if key is pressed
        if(sf::Keyboard::isKeyPressed(key)) {
            if(abilities_.at(input).key_released_) {
                // Activate ability and break
                std::cout << "Key pressed" << std::endl;
                abilities_.at(input).key_released_ = false;
                abilities_.at(input).reset();
            }
            break;
        } else {
            abilities_.at(input).key_released_ = true;
        }
    }
}

void PlayerAbilities::applyActiveAbilities(PlayerPhysicsComponent* physics, World& world) {
    // Use pointer to the relevant physics component and the world to do what's necessary for this ability
    for(auto& [input, ability_manager] : abilities_) {
        // Set to kick off or currently in progress
        if(ability_manager.active()) {
            ability_manager.ability_->apply(physics, world);
            std::cout << "Ability applied" << std::endl;
        }
    }
}

// void PlayerAbilities::add_ability(CompConstants::Player::AbilityInputs input, Ability ability) {
//     // abilityKeybinds_[input] = 
//     (void)input;
//     (void)ability;
// }