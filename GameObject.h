#pragma once

#include "Interfaces/PhysicsComponent.h"
#include "Interfaces/InputComponent.h"
#include "Interfaces/GraphicsComponent.h"

class World;

class GameObject {
public:
  GameObject();

  GameObject(std::unique_ptr<PhysicsComponent> physics,
             std::unique_ptr<InputComponent> input,
             std::unique_ptr<GraphicsComponent> graphics)
  : physics_(std::move(physics))
  , input_(std::move(input))
  , graphics_(std::move(graphics))
  {}

public:
  std::unique_ptr<PhysicsComponent> physics_;
  std::unique_ptr<InputComponent> input_;
  std::unique_ptr<GraphicsComponent> graphics_;

  void updateInput() { input_->update(); }

  void updatePhysics(World& world) { physics_->update(world); }

  void updateGraphics(Graphics& graphics, double frameProgress) { graphics_->update(graphics, frameProgress); }
};
