#pragma once

#include "../Interfaces/PhysicsComponent.h"

class NormalPhysicsComponent : public PhysicsComponent {
public:
    NormalPhysicsComponent(const sf::Vector2f& position) : PhysicsComponent(position) {}
    NormalPhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox) : PhysicsComponent(position, hitbox) {}
    NormalPhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox,  const sf::Vector2f& velocity) : PhysicsComponent(position, hitbox, velocity) {}
    NormalPhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox,  const sf::Vector2f& velocity, const sf::Vector2f& acceleration) : PhysicsComponent(position, hitbox, velocity, acceleration) {}
    virtual void update(World& world) = 0;

    virtual ~NormalPhysicsComponent() {}

public:
    bool canMove_;
    bool isOnGround_;
};