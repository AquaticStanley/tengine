#pragma once

#include "MetaData.h"
#include "Interfaces/PhysicsComponent.h"
#include "Interfaces/InputComponent.h"
#include "Interfaces/GraphicsComponent.h"

class GameObject {
public:
  GameObject();

public:
  MetaData* metadata_;

  PhysicsComponent* physics_;
  InputComponent* input_;
  GraphicsComponent* graphics_;
};
