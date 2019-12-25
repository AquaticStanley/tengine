#pragma once

#include <unordered_map>
#include "../../World.h"

// Ability includes
#include "../../Abilities/Ability.h"
#include "../../Abilities/Dash.h"

namespace CompConstants {
    namespace Player {
        enum class AbilityInputs { Ability1, Ability2, Ability3, Ability4 };
    }
}

class PlayerPhysicsComponent;

struct PlayerAbilityManager {
    PlayerAbilityManager(Ability* ability);
    bool complete_;
    bool physicsReady_;
    Ability* ability_;
};

class PlayerAbilities {
public:
    PlayerAbilities(PlayerPhysicsComponent* physics);

    void updateAbilityInputs();

    void applyActiveAbilities(World& world);

private:
    PlayerPhysicsComponent* physics_;

    std::unordered_map<CompConstants::Player::AbilityInputs, sf::Keyboard::Key> abilityKeybinds_;

    std::unordered_map<CompConstants::Player::AbilityInputs, PlayerAbilityManager> abilities_;

    // This class should have means to add and move abilities between keybinds eventually.
    void add_ability(CompConstants::Player::AbilityInputs input, Ability ability);
};
