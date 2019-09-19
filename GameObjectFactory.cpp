#include "GameObjectFactory.h"

namespace GOFactory {

// GameObject createPlayer(sf::Vector2f position) {
//     std::unique_ptr<MetaData> metadata = std::make_unique<MetaData>(MetaData(1));
//     std::unique_ptr<PhysicsComponent> physics = std::make_unique<PlayerPhysicsComponent>(PlayerPhysicsComponent(position, sf::Vector2f(CompConstants::Player::PLAYER_WIDTH, CompConstants::Player::PLAYER_HEIGHT)));
//     std::unique_ptr<InputComponent> input = std::make_unique<PlayerInputComponent>(PlayerInputComponent(physics));
//     std::unique_ptr<GraphicsComponent> graphics = std::make_unique<PlayerGraphicsComponent>(PlayerGraphicsComponent(physics));
//     return GameObject(std::move(metadata), std::move(physics), std::move(input), std::move(graphics));
// }

GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox) {
    std::unique_ptr<MetaData> metadata = std::make_unique<MetaData>(MetaData(1));
    std::unique_ptr<PhysicsComponent> physics = std::make_unique<PlatformPhysicsComponent>(PlatformPhysicsComponent(position, hitbox));
    std::unique_ptr<InputComponent> input = std::make_unique<PlatformInputComponent>(PlatformInputComponent(physics));
    std::unique_ptr<GraphicsComponent> graphics = std::make_unique<PlatformGraphicsComponent>(PlatformGraphicsComponent(physics));
    return GameObject(std::move(metadata), std::move(physics), std::move(input), std::move(graphics));
}

}
