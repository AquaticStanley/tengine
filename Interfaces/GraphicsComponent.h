#pragma once

#include "../Graphics/Graphics.h"
#include "PhysicsComponent.h"

class GraphicsComponent {
public:
  GraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : physics_(physics.get()) {}

  virtual ~GraphicsComponent() {}

  virtual void update(Graphics& graphics, double frameProgress) = 0;

  const sf::Vector2f& position() { return physics_->position_; }
  const sf::Vector2f& hitbox()   { return physics_->hitbox_; }
  const sf::Vector2f& velocity() { return physics_->velocity_; }

protected:
  const PhysicsComponent* physics_;
};
