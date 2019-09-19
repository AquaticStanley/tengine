#pragma once

#include "PhysicsComponent.h"

class GameObject;

class InputComponent {
public:
  InputComponent(const std::unique_ptr<PhysicsComponent>& physics) : physics_(physics.get()) {}

  virtual void update() = 0;

private:
  PhysicsComponent* physics_;
};
