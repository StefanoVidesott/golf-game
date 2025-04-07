#include "application.hpp"

Application::Application() {
    this->init();
}

Application::~Application() {
    delete window;
}

void Application::init() {
    ResourceManager::init();
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Improved SFML App");

    // TODO Load settings from a config file
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(true);
}

void Application::loadScene(Scene* scene) {
    sceneManager.queueScene(scene);
}

void Application::handleEvents() {
    std::optional<sf::Event> event;
    while (event = this->window->pollEvent()){
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }

        Scene* scene = sceneManager.getCurrentScene();
        if (scene) {
            scene->handleEvents(event);
        }
    }
}

void Application::fixedUpdate() {
    Scene* scene = sceneManager.getCurrentScene();
    if (scene) scene->fixedUpdate(fixedStep);
}

void Application::update(float deltaTime) {
    Scene* scene = sceneManager.getCurrentScene();
    if (scene) {
        scene->earlyUpdate(deltaTime);
        scene->update(deltaTime);
        scene->lateUpdate(deltaTime);
    }
}

void Application::render() {
    window->clear();
    Scene* scene = sceneManager.getCurrentScene();
    if (scene) scene->render(window);
    window->display();
}

void Application::run() {
    while (window->isOpen()) {
        float deltaTime = deltaClock.restart().asSeconds();
        if (deltaTime > 0.25f) deltaTime = 0.25f; // spike guard
        accumulator += deltaTime;

        handleEvents();

        while (accumulator >= fixedStep) {
            fixedUpdate();
            accumulator -= fixedStep;
        }

        update(deltaTime);
        render();
        sceneManager.updateCurrentSceneInit();
    }
}
