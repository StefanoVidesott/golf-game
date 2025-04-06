#pragma once

#include "test_scene.hpp"
#include <queue>

class Application{
public:
    Application();
    ~Application();

    void run();
    void loadScene(Scene*);
    void dropScene();

private:
    sf::RenderWindow* window;

    std::queue<Scene*> scenes;
    Scene* currentScene;

    void update();
    void render();
    void handleEvents();
};
