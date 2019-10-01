#pragma once

#include <vector>
#include "GameObject.h"

namespace WorldConstants {
  // World Constants
  // Units/second
  const float WORLD_X_SPEED_LIMIT = 3.0;

  // Units/second
  const float WORLD_Y_SPEED_LIMIT = 7.0;

  // Units/second^2
  const float WORLD_GRAVITY_ACCELERATION = -0.05;
}

class World {
public:
  World() {}
  World(std::vector<GameObject> entities) : entities_(std::move(entities)) {}

  void processInput();
  void updatePhysics();
  void render(double frameProgress, Graphics& graphics);

  void addEntities(std::vector<GameObject>& entities);

  std::vector<GameObject> entities_;
};
