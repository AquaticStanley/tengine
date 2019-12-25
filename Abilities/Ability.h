#pragma once

// #include "../Components/Player/Player.h"
#include "../World.h"

class PlayerPhysicsComponent;
class Ability {
public:
    Ability(const int activeFrames)
    : activeFrames_(activeFrames)
    , framesLeft_(0)
    {}

    virtual void reset() { framesLeft_ = activeFrames_; }
    virtual void apply(PlayerPhysicsComponent* physics_component, World& world) = 0;
    int activeFrames_;
    int framesLeft_;
};
