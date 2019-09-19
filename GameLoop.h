#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include "Util/Stopwatch.h"
#include "Graphics/Graphics.h"
#include "World.h"
#include "GameObjectFactory.h"

namespace GameLoop {
  void loop();

  std::vector<GameObject> getTestLevel();
}