#pragma once
#include "component.hpp"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component {
public:
    SpriteComponent(const sf::Texture&);

    void render(sf::RenderWindow*) override;
    sf::Sprite& getSprite();

private:
    sf::Sprite sprite;
};
