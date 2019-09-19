#pragma once

#include "PhysicsComponent.h"

class InputComponent {
public:
  InputComponent(PhysicsComponent& physics) : physics_(physics) {}

  virtual void update() = 0;

private:
  PhysicsComponent& physics_;
};
