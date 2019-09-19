#pragma once

#include "PhysicsComponent.h"

class GraphicsComponent {
public:
  GraphicsComponent(const std::unique_ptr<PhysicsComponent> physics) : physics_(physics.get()) {}

  virtual void update() = 0;

private:
  const PhysicsComponent* physics_;
};
