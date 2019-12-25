#pragma once

// #include "../Components/Player/Player.h"
#include "../World.h"

class PlayerPhysicsComponent;
class Ability {
public:
    virtual void apply(PlayerPhysicsComponent* physics_component, World& world) = 0;
};
