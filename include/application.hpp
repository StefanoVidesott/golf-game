#pragma once

#include "scene_manager.hpp"

class Application {
public:
    Application();
    ~Application();

    void run();
    void loadScene(Scene* scene);

private:
    sf::RenderWindow* window;
    SceneManager sceneManager;

    sf::Clock deltaClock;
    float fixedStep = 1.f / 60.f;
    float accumulator = 0.f;

    void handleEvents();
    void update(float deltaTime);
    void fixedUpdate();
    void render();
};
