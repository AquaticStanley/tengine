#include "GameObjectFactory.h"

namespace GOFactory {

GameObject createPlayer(sf::Vector2f position) {
    std::unique_ptr<PhysicsComponent> physics = std::make_unique<PlayerPhysicsComponent>(PlayerPhysicsComponent(position, sf::Vector2f(CompConstants::Player::PLAYER_WIDTH, CompConstants::Player::PLAYER_HEIGHT)));
    std::unique_ptr<InputComponent> input = std::make_unique<PlayerInputComponent>(PlayerInputComponent(physics));
    std::unique_ptr<GraphicsComponent> graphics = std::make_unique<PlayerGraphicsComponent>(PlayerGraphicsComponent(physics));
    return GameObject(std::move(physics), std::move(input), std::move(graphics));
}

GameObject createPlatform(sf::Vector2f position, sf::Vector2f hitbox) {
    std::unique_ptr<PhysicsComponent> physics = std::make_unique<PlatformPhysicsComponent>(PlatformPhysicsComponent(position, hitbox));
    std::unique_ptr<InputComponent> input = std::make_unique<PlatformInputComponent>(PlatformInputComponent(physics));
    std::unique_ptr<GraphicsComponent> graphics = std::make_unique<PlatformGraphicsComponent>(PlatformGraphicsComponent(physics));
    return GameObject(std::move(physics), std::move(input), std::move(graphics));
}

GameObject createCamera(const std::unique_ptr<PhysicsComponent>& physicsToFollow) {
    std::unique_ptr<PhysicsComponent> physics = std::make_unique<CameraPhysicsComponent>(CameraPhysicsComponent(physicsToFollow));
    std::unique_ptr<InputComponent> input = std::make_unique<CameraInputComponent>(CameraInputComponent(physics));
    std::unique_ptr<GraphicsComponent> graphics = std::make_unique<CameraGraphicsComponent>(CameraGraphicsComponent(physics));
    return GameObject(std::move(physics), std::move(input), std::move(graphics));
}


}
