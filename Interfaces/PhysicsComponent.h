#pragma once

#include <SFML/System.hpp>

class World;

class PhysicsComponent {
public:
  PhysicsComponent(const sf::Vector2f& position) : PhysicsComponent(position, sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(0, 0)) {}
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox) : PhysicsComponent(position, hitbox, sf::Vector2f(0, 0), sf::Vector2f(0, 0)) {}
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox,  const sf::Vector2f& velocity) : PhysicsComponent(position, hitbox, velocity, sf::Vector2f(0, 0)) {}
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox,  const sf::Vector2f& velocity, const sf::Vector2f& acceleration) : 
                   position_(position), hitbox_(hitbox), velocity_(velocity), acceleration_(acceleration), toBeRemoved_(false) {}

  virtual ~PhysicsComponent() {}

  virtual void update(World& world) = 0;

public:
  sf::Vector2f position_;
  sf::Vector2f hitbox_;
  sf::Vector2f velocity_;
  sf::Vector2f acceleration_;

  bool toBeRemoved_;
};
