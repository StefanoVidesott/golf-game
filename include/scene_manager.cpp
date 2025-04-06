#include "scene_manager.hpp"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {
    if (currentScene) delete currentScene;
    if (nextScene) delete nextScene;
}

void SceneManager::queueScene(Scene* scene) {
    nextScene = scene;
}

void SceneManager::dropCurrentScene() {
    if (currentScene) {
        currentScene->onExit();
        delete currentScene;
    }
    currentScene = nullptr;
}

void SceneManager::updateCurrentSceneInit() {
    if (nextScene) {
        if (currentScene) {
            currentScene->onExit();
            delete currentScene;
        }

        currentScene = nextScene;
        nextScene = nullptr;

        if (!currentScene->isInitialized) {
            currentScene->init();
            currentScene->isInitialized = true;
        }
        currentScene->onEnter();
    }
}

Scene* SceneManager::getCurrentScene() {
    return currentScene;
}
