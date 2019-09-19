#pragma once

#include "MetaData.h"
#include "PhysicsComponent.h"
#include "InputComponent.h"
#include "GraphicsComponent.h"

class GameObject {
public:
  GameObject();

public:
  MetaData* metadata_;
  PhysicsComponent* physics_;
  InputComponent* input_;
  GraphicsComponent* graphics_;
};
