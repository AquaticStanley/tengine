#pragma once

#include "../../World.h"

namespace CompConstants {
  namespace Camera {
    constexpr double MAX_CAMERA_SPEED = 3.0;
  }
}

class CameraPhysicsComponent : public PhysicsComponent {
private:
    PhysicsComponent* physicsToFollow_;

public:
    CameraPhysicsComponent(const std::unique_ptr<PhysicsComponent>& physicsToFollow)
    : PhysicsComponent(physicsToFollow->position_, physicsToFollow->hitbox_)
    , physicsToFollow_(physicsToFollow.get())
    {
        PhysicsComponent::canCollide_ = false;
    }

    virtual void update(World& world);
};

class CameraInputComponent : public InputComponent {
public:
    CameraInputComponent(const std::unique_ptr<PhysicsComponent>& physics) : InputComponent(physics) {}
    virtual void update() {}
};

class CameraGraphicsComponent : public GraphicsComponent {
public:
    CameraGraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : GraphicsComponent(physics) {}
    virtual void update(Graphics& graphics, double frameProgress) { (void)graphics; (void)frameProgress; }
};
