#pragma once

#include <SFML/System.hpp>

class World;

class PhysicsComponent {
public:
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox = sf::Vector2f(0, 0),  const sf::Vector2f& velocity = sf::Vector2f(0, 0), const sf::Vector2f& acceleration = sf::Vector2f(0, 0)) : 
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
