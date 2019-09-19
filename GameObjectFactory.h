#pragma once

#include <memory>

#include "GameObject.h"

// Entity dependencies
#include "Components/Platform/Platform.h"

namespace GOFactory {

  GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox);

}