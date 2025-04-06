#pragma once

#include "scene.hpp"

class TestScene : public Scene {
public:
    TestScene();
    ~TestScene();

    void init() override;
    void update() override;
    void render(sf::RenderWindow*) override;
    void handleEvents(std::optional<sf::Event>*) override;

private:
    sf::CircleShape shape;

};