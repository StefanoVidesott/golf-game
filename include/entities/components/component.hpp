#pragma once
#include <SFML/Graphics.hpp>

class Component {
public:
    virtual ~Component() = default;
    virtual void update(float) {}
    virtual void render(sf::RenderWindow*) {}
};
