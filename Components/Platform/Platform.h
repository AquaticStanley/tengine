#pragma once

#include "../..//World.h"

class PlatformPhysicsComponent : public PhysicsComponent {
public:
  virtual void update(World& world);
};

class PlatformInputComponent : public InputComponent {
public:
  virtual void update();
};

class PlatformGraphicsComponent : public GraphicsComponent {
public:
  virtual void update();
};
