#include "World.h"

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

void World::addEntities(std::vector<GameObject>& entities) {
  for(auto& entity : entities) {
    entities_.emplace_back(std::move(entity));
  }
}