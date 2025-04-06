#include "scene.hpp"

Scene::Scene() {}
Scene::~Scene() {}

void Scene::init() {}
void Scene::onEnter() {}
void Scene::onExit() {}
void Scene::handleEvents(const std::optional<sf::Event>&) {}
void Scene::earlyUpdate(float) {}
void Scene::fixedUpdate(float) {}
void Scene::update(float) {}
void Scene::lateUpdate(float) {}
void Scene::render(sf::RenderWindow*) {}
