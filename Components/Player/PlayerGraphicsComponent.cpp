#include "Player.h"

void PlayerGraphicsComponent::update(Graphics& graphics, double frameProgress) {
  sf::Vector2f predictedPosition = GraphicsComponent::position() + sf::Vector2f(GraphicsComponent::velocity().x * frameProgress, GraphicsComponent::velocity().y * frameProgress);
  graphics.draw(predictedPosition, STANDING_SPRITE);
  return;
}
