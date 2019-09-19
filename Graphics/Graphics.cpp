#include "Graphics.h"

void Graphics::draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Color color) {
  sf::RectangleShape rectangle(hitbox);
  rectangle.setOrigin(0, rectangle.getSize().y);
  rectangle.setFillColor(color);

  //Translate position
  position = translatePosition(position);

  rectangle.setPosition(position);

  window_->draw(rectangle);
  return;
}

void Graphics::draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Sprite sprite) {
  sprite.setOrigin(0, hitbox.y);
  sf::Vector2f roundedPosition = sf::Vector2f(position.x - 0.5, position.y - 0.5);

  //Translate position
  translatePosition(roundedPosition);

  //Set Position
  sprite.setPosition(roundedPosition);

  //Scale if necessary
  sprite.scale(hitbox.x / sprite.getTextureRect().width, hitbox.y / sprite.getTextureRect().height);

  window_->draw(sprite);
  return;
}

sf::Vector2f Graphics::translatePosition(sf::Vector2f position) {
  return sf::Vector2f(position.x, window_->getSize().y - position.y);
}
