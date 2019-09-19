#pragma once

#include "../Graphics/Graphics.h"
#include "PhysicsComponent.h"

class GraphicsComponent {
public:
  GraphicsComponent(const std::unique_ptr<PhysicsComponent>& physics) : physics_(physics.get()) {}

  virtual ~GraphicsComponent() {}

  virtual void update(Graphics& graphics, double frameProgress) = 0;

protected:
  const PhysicsComponent* physics_;
};
