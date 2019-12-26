#include "World.h"
#include <iostream>
#include "Components/Player/Player.h"

void World::processInput() {
  for(auto& entity : entities_) {
    entity.updateInput();
  }
}

void World::updatePhysics() {
  // Update physics of each entity
  for(auto& entity : entities_) {
    entity.updatePhysics(*this);
  }

  // Remove dead entities
  entities_.erase(std::remove_if(entities_.begin(), entities_.end(),
    [](const GameObject& o) { return o.physics_->toBeRemoved_; }), entities_.end());
}

void World::render(double frameProgress, Graphics& graphics) {
  for(auto& entity : entities_) {
    entity.updateGraphics(graphics, frameProgress);
  }
}

void World::resolveNormalCollision(PlayerPhysicsComponent* physics) {
    sf::Vector2f previousPosition = physics->position_ - physics->velocity_;
    // physics->isOnGround_ = false;

    auto valueInRange = [](double value, double min, double max) {
        return (value >= min) && (value <= max);
    };

    // Check if space is occupied
    for(auto& entity : entities_) {
        if(entity.physics_->getID() != physics->getID() && entity.physics_->canCollide()) {
            bool same_x_level = valueInRange(entity.physics_->position_.x, physics->position_.x, physics->position_.x + physics->hitbox_.x + 1) ||
                                valueInRange(physics->position_.x, entity.physics_->position_.x, entity.physics_->position_.x + entity.physics_->hitbox_.x + 1);
        
            bool same_y_level = valueInRange(entity.physics_->position_.y, physics->position_.y, physics->position_.y + physics->hitbox_.y + 1) ||
                                valueInRange(physics->position_.y, entity.physics_->position_.y, entity.physics_->position_.y + entity.physics_->hitbox_.y + 1);
    
            if(same_x_level && same_y_level) {
                // Collision detected
                if(previousPosition.y > entity.physics_->position_.y + entity.physics_->hitbox_.y) {
                    // Was above object before collision

                    // Move up until no collision
                    physics->position_.y = entity.physics_->position_.y + entity.physics_->hitbox_.y + 1;

                    // Stop pushing into object
                    physics->velocity_.y = 0;
                } else if(previousPosition.y + physics->hitbox_.y < entity.physics_->position_.y) {
                    // Was below object before collision

                    // Move down until no collision
                    physics->position_.y = entity.physics_->position_.y - physics->hitbox_.y - 1;

                    // Stop pushing into object
                    physics->velocity_.y = 0;
                } else {
                    // Was same level as object before collision - horizontal collision
                    if(previousPosition.x > entity.physics_->position_.x + entity.physics_->hitbox_.x) {
                        // Was to the right of object before collision

                        // Move to the right until no collision
                        physics->position_.x = entity.physics_->position_.x + entity.physics_->hitbox_.x + 1;

                        // Stop pushing into object
                        physics->velocity_.x = 0;
                        if(!physics->facingRight_) {
                            physics->wallAdjacent_ = true;
                        }
                    } else if(previousPosition.x + physics->hitbox_.x < entity.physics_->position_.x) {
                        // Was to the left of object before collision

                        // Move to the left until no collision
                        physics->position_.x = entity.physics_->position_.x - physics->hitbox_.x - 1;

                        // Stop pushing into object
                        physics->velocity_.x = 0;
                        if(physics->facingRight_) {
                            physics->wallAdjacent_ = true;
                        }
                    }
                }
            }

            if(same_x_level && physics->position_.y == entity.physics_->position_.y + entity.physics_->hitbox_.y + 1) {
                // Object is on ground
                physics->isOnGround_ = true;
            }
        }
    }

    return;
}

void World::addEntities(std::vector<GameObject>& entities) {
  for(auto& entity : entities) {
    entities_.emplace_back(std::move(entity));
  }
}