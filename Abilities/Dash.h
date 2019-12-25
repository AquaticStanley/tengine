#pragma once

#include <cmath>
#include "Ability.h"

namespace AbilityConstants {
    namespace Dash {
        constexpr float DASH_VELOCITY = 5.0;
    }
}

class Dash : public Ability {
public:
    virtual void apply(PlayerPhysicsComponent* physics, World& world);

private:
    float max_diagonal_velocity(const float velocity) {
        return std::sqrt(velocity / 2);
    }
};
