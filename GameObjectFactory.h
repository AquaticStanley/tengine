#pragma once

#include <memory>

#include "GameObject.h"

// Entity dependencies
#include "Components/Player/Player.h"
#include "Components/Platform/Platform.h"

namespace GOFactory {

  GameObject createPlayer(sf::Vector2f position);
  GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox);

}