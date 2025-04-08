#include "test_scene.hpp"
#include <cmath>
#include "components/sprite_component.hpp"

TestScene::TestScene() {}
TestScene::~TestScene() {}

void TestScene::init() {
    shape.setRadius(40.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(sf::Vector2f(40.f, 40.f));
    shape.setPosition(sf::Vector2f(400.f, 300.f));

    auto entity = std::make_unique<Entity>();
    auto& texture = ResourceManager::getTexture("assets/player.png");
    auto* sprite = entity->addComponent<SpriteComponent>(texture);
    sprite->getSprite().setPosition(sf::Vector2f(400.f, 300.f));

    entities.push_back(std::move(entity));

}

void TestScene::update(float deltaTime) {
    time += deltaTime;
    shape.setPosition(sf::Vector2f(400.f + std::sin(time * 2.f) * 100.f, 300.f));
    for (auto& entity : entities) entity->update(deltaTime);
}

void TestScene::render(sf::RenderWindow* window) {
    window->draw(shape);
    for (auto& entity : entities) entity->render(window);
}

void TestScene::handleEvents(const std::optional<sf::Event>& event) {
    // no input handling yet
}
