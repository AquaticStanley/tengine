#pragma once

#include "../../World.h"

namespace CompConstants {
  namespace Player {
    constexpr int PLAYER_HEIGHT = 30;
    constexpr int PLAYER_WIDTH = 15;
    constexpr double WALK_ACCELERATION_GROUND = 0.30;
    constexpr double WALK_ACCELERATION_AIR = 0.30;
    constexpr double IDLE_X_ACCELERATION_GROUND = 0.25;
    constexpr double IDLE_X_ACCELERATION_AIR = 0.5;
    constexpr double JUMP_VELOCITY = 3.0;
    const std::string STANDING_TEXTURE = "../../Assets/grillStandingSprite.png";
  }
}

class PlayerPhysicsComponent : public PhysicsComponent {
public:
  PlayerPhysicsComponent(sf::Vector2f position, sf::Vector2f hitbox) : PhysicsComponent(position, hitbox) {}
  virtual void update(World& world);

public:
  bool canMove_;
  bool facingRight_;
  bool walkingRight_;
  bool walkingLeft_;
  bool floatingRight_;
  bool floatingLeft_;
  bool isOnGround_;
  bool jumpIP_;
  bool jumping_;

public:
  // State mutation functions
  void setWalkingRight();
  void setWalkingLeft();
  void setFloatingRight();
  void setFloatingLeft();
  void clearLeftRight();
  bool isIdle();
};

class PlayerInputComponent : public InputComponent {
public:
  PlayerInputComponent(const std::unique_ptr<PhysicsComponent>& physics)
  : InputComponent(physics)
  , physics_(static_cast<PlayerPhysicsComponent*>(InputComponent::physics_))
  , key_right(sf::Keyboard::Key::Right)
  , key_left(sf::Keyboard::Key::Left)
  , key_space(sf::Keyboard::Key::Space)
  {}

  virtual void update();

private:
  PlayerPhysicsComponent* physics_;

  // Key bindings to reassign at will
  sf::Keyboard::Key key_right;
  sf::Keyboard::Key key_left;
  sf::Keyboard::Key key_space;
};

class PlayerGraphicsComponent : public GraphicsComponent {
public:
  PlayerGraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : GraphicsComponent(physics) {
    STANDING_TEXTURE.loadFromFile(CompConstants::Player::STANDING_TEXTURE);
    STANDING_SPRITE.setTexture(STANDING_TEXTURE);
    STANDING_SPRITE.setTextureRect(sf::IntRect(0, 0, CompConstants::Player::PLAYER_WIDTH, CompConstants::Player::PLAYER_HEIGHT));
  }
  virtual void update(Graphics& graphics, double frameProgress);

private:
  sf::Texture STANDING_TEXTURE;
  sf::Sprite STANDING_SPRITE;
};
