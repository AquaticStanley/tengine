#include "Camera.h"

void CameraPhysicsComponent::update(World& world) {
    using namespace CompConstants::Camera;
    (void)world;

    PhysicsComponent::velocity_ = physicsToFollow_->position_ - PhysicsComponent::position_;

    if(PhysicsComponent::velocity_.x > MAX_CAMERA_SPEED) {
        PhysicsComponent::velocity_.x = MAX_CAMERA_SPEED;
    }

    if(PhysicsComponent::velocity_.x < (MAX_CAMERA_SPEED * -1)) {
        PhysicsComponent::velocity_.x = MAX_CAMERA_SPEED * -1;
    }

    if(PhysicsComponent::velocity_.y > MAX_CAMERA_SPEED) {
        PhysicsComponent::velocity_.y = MAX_CAMERA_SPEED;
    }

    if(PhysicsComponent::velocity_.y < (MAX_CAMERA_SPEED * -1)) {
        PhysicsComponent::velocity_.y = MAX_CAMERA_SPEED * -1;
    }

    PhysicsComponent::position_ += PhysicsComponent::velocity_;

    return;
}
