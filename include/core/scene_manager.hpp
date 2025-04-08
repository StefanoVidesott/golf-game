#pragma once
#include "../scenes/scene.hpp"
#include <queue>

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void queueScene(Scene* scene);
    void updateCurrentSceneInit();
    Scene* getCurrentScene();
    void dropCurrentScene();

private:
    Scene* currentScene = nullptr;
    Scene* nextScene = nullptr;
};
