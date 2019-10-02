#pragma once

#include <memory>

#include "GameObject.h"

// Entity dependencies
#include "Components/Player/Player.h"
#include "Components/Platform/Platform.h"
#include "Components/Camera/Camera.h"

namespace GOFactory {

    GameObject createPlayer(sf::Vector2f position);
    GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox);
    GameObject createCamera(const std::unique_ptr<PhysicsComponent>& physicsToFollow);

}