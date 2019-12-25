#pragma once

#include <unordered_map>
#include <cmath>

#include "../../ComponentConcepts/NormalPhysicsComponent.h"
#include "PlayerAbilities.h"
#include "../../World.h"

namespace CompConstants {
   namespace Player {
        constexpr int PLAYER_HEIGHT = 120;
        constexpr int PLAYER_WIDTH = 60;
        constexpr double WALK_ACCELERATION_GROUND = 1.50;
        constexpr double WALK_ACCELERATION_AIR = 1.50;
        constexpr double IDLE_X_ACCELERATION_GROUND = 1.0;
        constexpr double IDLE_X_ACCELERATION_AIR = 1.0;
        constexpr double JUMP_VELOCITY = 15.0;
        constexpr double WALK_TOP_SPEED = 10.0;
        constexpr double SOFT_CAP_DECELERATION = 0.30;
        const std::string STANDING_TEXTURE = "Assets/grillStandingSprite.png";

        enum class Inputs {Left, Right, Jump, Up, Down};
   }
}

class PlayerPhysicsComponent : public NormalPhysicsComponent {
public:
    PlayerPhysicsComponent(sf::Vector2f position, sf::Vector2f hitbox)
    : NormalPhysicsComponent(position, hitbox)
    , facingRight_(false)
    , walkingRight_(false)
    , walkingLeft_(false)
    , floatingRight_(false)
    , floatingLeft_(false)
    , jumpIP_(false)
    , jumping_(false)
    {}

    virtual void update(World& world);

public:
    bool facingRight_;
    bool walkingRight_;
    bool walkingLeft_;
    bool floatingRight_;
    bool floatingLeft_;
    bool jumpIP_;
    bool jumping_;
    bool facingUp_;
    bool facingDown_;

    PlayerAbilities abilities_;

public:
    // State mutation functions
    void setWalkingRight();
    void setWalkingLeft();
    void setFloatingRight();
    void setFloatingLeft();
    void setFacingUp();
    void setFacingDown();
    void clearUpDown();
    void clearLeftRight();
    bool isIdle();
};

class PlayerInputComponent : public InputComponent {
public:
    PlayerInputComponent(const std::unique_ptr<PhysicsComponent>& physics)
    : InputComponent(physics)
    , physics_(static_cast<PlayerPhysicsComponent*>(InputComponent::physics_))
    {
        controlMap_[CompConstants::Player::Inputs::Right] = sf::Keyboard::Key::Right;
        controlMap_[CompConstants::Player::Inputs::Left] = sf::Keyboard::Key::Left;
        controlMap_[CompConstants::Player::Inputs::Jump] = sf::Keyboard::Key::Space;
        controlMap_[CompConstants::Player::Inputs::Up] = sf::Keyboard::Key::Up;
        controlMap_[CompConstants::Player::Inputs::Down] = sf::Keyboard::Key::Down;
    }

    virtual void update();

private:
    PlayerPhysicsComponent* physics_;

    // Key bindings to reassign at will
    std::unordered_map<CompConstants::Player::Inputs, sf::Keyboard::Key> controlMap_;
};

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : GraphicsComponent(physics) {
        STANDING_TEXTURE = std::make_unique<sf::Texture>();
        STANDING_TEXTURE->loadFromFile(CompConstants::Player::STANDING_TEXTURE);
        STANDING_TEXTURE->setSmooth(true);
        STANDING_SPRITE.setTexture(*STANDING_TEXTURE);
        STANDING_SPRITE.scale(GraphicsComponent::hitbox().x / STANDING_SPRITE.getTextureRect().width, GraphicsComponent::hitbox().y / STANDING_SPRITE.getTextureRect().height);
        STANDING_SPRITE.setTextureRect(sf::IntRect(0, 0, CompConstants::Player::PLAYER_WIDTH, CompConstants::Player::PLAYER_HEIGHT));
        STANDING_SPRITE.setOrigin(0, GraphicsComponent::hitbox().y);
    }
    virtual void update(Graphics& graphics, double frameProgress);

private:
    std::unique_ptr<sf::Texture> STANDING_TEXTURE;
    sf::Sprite STANDING_SPRITE;
};
