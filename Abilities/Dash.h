#pragma once

#include <cmath>
#include "Ability.h"

namespace AbilityConstants {
    namespace Dash {
        constexpr float DASH_VELOCITY = 8.0;
        constexpr int ACTIVE_FRAMES = 10;
    }
}

class Dash : public Ability {
public:
    Dash() : Ability(AbilityConstants::Dash::ACTIVE_FRAMES) {}

    virtual void apply(PlayerPhysicsComponent* physics, World& world);
    sf::Vector2f speedToApply_;

private:
    float max_diagonal_velocity(const float velocity) {
        return std::sqrt((velocity * velocity) / 2);
    }
};
