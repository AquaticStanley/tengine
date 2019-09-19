#include "GameLoop.h"

void loop() {

}

std::vector<GameObject> getTestLevel() {
  std::vector<GameObject> gameObjects;

  sf::Vector2f floorPos(150, 250);
  sf::Vector2f floorHitbox(700, 5);
  gameObjects.emplace_back(GOFactory::createPlatform(floorPos, floorHitbox));


  return gameObjects;
}