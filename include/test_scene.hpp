#pragma once
#include "scene.hpp"

class TestScene : public Scene {
public:
    TestScene();
    ~TestScene();

    void init() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow*) override;
    void handleEvents(const std::optional<sf::Event>&) override;

private:
    sf::CircleShape shape;
    float time = 0.f;
};
