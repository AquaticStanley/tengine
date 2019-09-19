#include "World.h"

void World::processInput() {
  for(auto& entity : entities_) {
    entity.updateInput();
  }
}

void World::updatePhysics() {
  // Update physics of each entity
  // for(auto& entity : entities_) {
  //   entity.updatePhysics(*this);
  // }

  // Remove dead entities
  // entities_.erase(std::remove_if(entities_.begin(), entities_.end(), 
  //   [](GameObject& o) { return o->metadata_->shouldBeRemoved_; }), entities_.end());
}

void World::render(double frameProgress, Graphics& graphics) {
  (void)frameProgress;
  (void)graphics;
}

// void World::addEntities(std::vector<GameObject> entities) {

// }