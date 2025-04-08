#include "sprite_component.hpp"

SpriteComponent::SpriteComponent(const sf::Texture& texture) : sprite(texture) {
}

void SpriteComponent::render(sf::RenderWindow* window) {
    window->draw(sprite);
}

sf::Sprite& SpriteComponent::getSprite() {
    return sprite;
}
