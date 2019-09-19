#pragma once

#include "MetaData.h"
#include "Interfaces/PhysicsComponent.h"
#include "Interfaces/InputComponent.h"
#include "Interfaces/GraphicsComponent.h"

class GameObject {
public:
  GameObject();

  GameObject(std::unique_ptr<MetaData> metadata,
             std::unique_ptr<PhysicsComponent> physics,
             std::unique_ptr<InputComponent> input,
             std::unique_ptr<GraphicsComponent> graphics)
  : metadata_(std::move(metadata))
  , physics_(std::move(physics))
  , input_(std::move(input))
  , graphics_(std::move(graphics))
  {}

public:
  std::unique_ptr<MetaData> metadata_;
  std::unique_ptr<PhysicsComponent> physics_;
  std::unique_ptr<InputComponent> input_;
  std::unique_ptr<GraphicsComponent> graphics_;
};
