#pragma once

#include <SFML/System.hpp>

class PhysicsComponent {
public:
  PhysicsComponent(const sf::Vector2f& position) : PhysicsComponent(position, sf::Vector2f(0, 0), sf::Vector2f(0, 0)) {}
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f& velocity) : PhysicsComponent(position, velocity, sf::Vector2f(0, 0)) {}
  PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Vector2f& acceleration) : 
                   position_(position), velocity_(velocity), acceleration_(acceleration) {}

  virtual void update() = 0;

public:
  sf::Vector2f position_;
  sf::Vector2f velocity_;
  sf::Vector2f acceleration_;
};
