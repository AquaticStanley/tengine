#pragma once

#include "PhysicsComponent.h"

class GraphicsComponent {
public:
  GraphicsComponent(const PhysicsComponent& physics) : physics_(physics) {}

  virtual void update() = 0;

private:
  const PhysicsComponent& physics_;
};
