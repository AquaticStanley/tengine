#pragma once

#include <vector>
#include "GameObject.h"

class World {
public:
  World() {}
  World(std::vector<GameObject> entities) : entities_(std::move(entities)) {}

  void processInput();
  void updatePhysics();
  void render(double frameProgress, Graphics& graphics);

  // void addEntities(std::vector<GameObject> entities);

  std::vector<GameObject> entities_;
};
