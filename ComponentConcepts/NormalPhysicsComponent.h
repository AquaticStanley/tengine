#pragma once

#include "../Interfaces/PhysicsComponent.h"

class NormalPhysicsComponent : public PhysicsComponent {
public:
    NormalPhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox = sf::Vector2f(0, 0),  const sf::Vector2f& velocity = sf::Vector2f(0, 0), const sf::Vector2f& acceleration = sf::Vector2f(0, 0))
    : PhysicsComponent(position, hitbox, velocity, acceleration)
    , canMove_(true)
    , isOnGround_(false)
    {}

    virtual void update(World& world) = 0;

    virtual ~NormalPhysicsComponent() {}

public:
    bool canMove_;
    bool isOnGround_;
};