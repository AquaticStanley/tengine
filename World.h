#pragma once

#include <vector>
#include "GameObject.h"

class World {
public:
  World() {}

  std::vector<GameObject> entities_;

  void processInput();

  void updatePhysics();
};
