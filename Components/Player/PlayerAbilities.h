#pragma once

#include <unordered_map>
#include "../../World.h"

namespace CompConstants {
    namespace Player {
        enum class AbilityInputs { Ability1, Ability2, Ability3, Ability4 };
    }
}

class PlayerPhysicsComponent;

class PlayerAbilities {
public:
    PlayerAbilities(PlayerPhysicsComponent* physics) : physics_(physics) {}

    void updateAbilityInputs();

    void applyActiveAbilities(World& world);

private:
    PlayerPhysicsComponent* physics_;

    std::unordered_map<CompConstants::Player::AbilityInputs, sf::Keyboard::Key> abilityKeybinds_;
};