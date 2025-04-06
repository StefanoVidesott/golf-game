#pragma once

#include <SFML/Graphics.hpp>

class Scene {
public:
    Scene();
    virtual ~Scene();

    virtual void init();
    virtual void update();
    virtual void render(sf::RenderWindow*);
    virtual void handleEvents();
};
