#pragma once

#include "PhysicsComponent.h"

class GameObject;

class InputComponent {
public:
  InputComponent(const std::unique_ptr<PhysicsComponent>& physics) : physics_(physics.get()) {}

  virtual ~InputComponent() {}

  virtual void update() = 0;

protected:
  PhysicsComponent* physics_;
};
