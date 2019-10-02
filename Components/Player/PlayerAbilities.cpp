#include "PlayerAbilities.h"
#include "Player.h"

void PlayerAbilities::updateAbilityInputs() {
    // Check if any inputs are held down, and queue the ability to be used if so, setting it on cooldown appropriately
    // In other words, determine if we can use this ability and take care of "cleaning up" after it
}

void PlayerAbilities::applyActiveAbilities(World& world) {
    // Use pointer to the relevant physics component and the world to do what's necessary for this ability
}
