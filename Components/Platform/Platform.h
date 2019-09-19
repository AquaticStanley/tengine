#pragma once

#include "../..//World.h"

class PlatformPhysicsComponent : public PhysicsComponent {
public:
  PlatformPhysicsComponent(sf::Vector2f position, sf::Vector2f hitbox) : PhysicsComponent(position, hitbox) {}
  virtual void update(World& world) { (void)world; }
};

class PlatformInputComponent : public InputComponent {
public:
  PlatformInputComponent(const std::unique_ptr<PhysicsComponent>& physics) : InputComponent(physics) {}
  virtual void update() {}
};

class PlatformGraphicsComponent : public GraphicsComponent {
public:
  PlatformGraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : GraphicsComponent(physics) {}
  virtual void update(Graphics& graphics, double frameProgress) {
    (void)frameProgress;
    graphics.draw(GraphicsComponent::physics_->position_, GraphicsComponent::physics_->hitbox_, sf::Color::White);
    return;
  }
};
