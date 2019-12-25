#pragma once

#include <vector>
#include "GameObject.h"
#include "ComponentConcepts/NormalPhysicsComponent.h"

namespace WorldConstants {
  // World Constants
  // Units/second
  const float WORLD_X_SPEED_LIMIT = 100.0;

  // Units/second
  const float WORLD_Y_SPEED_LIMIT = 100.0;

  // Units/second^2
  const float WORLD_GRAVITY_ACCELERATION = -0.350;
}

class PlayerPhysicsComponent;

class World {
public:
  World() {}
  World(std::vector<GameObject> entities) : entities_(std::move(entities)) {}

  void processInput();
  void updatePhysics();
  void render(double frameProgress, Graphics& graphics);

  void resolveNormalCollision(NormalPhysicsComponent* physics);

  // void resolvePlayerCollision(PlayerPhysicsComponent* physics);

  // Add generic resolveCollision for other things

  void addEntities(std::vector<GameObject>& entities);

  std::vector<GameObject> entities_;
};
