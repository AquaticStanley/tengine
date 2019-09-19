#include "GameObjectFactory.h"

namespace GOFactory {

GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox) {
    std::unique_ptr<MetaData> metadata = std::make_unique(MetaData(1));
    std::unique_ptr<PlatformPhysicsComponent> physics = std::make_unique(PlatformPhysicsComponent(position, hitbox));
    std::unique_ptr<PlatformInputComponent> input = std::make_unique(PlatformInputComponent(physics));
    std::unique_ptr<GraphicsComponent> graphics = std::make_unique(PlatformGraphicsComponent(physics));
    return GameObject(metadata, physics, input, graphics)
}

}
