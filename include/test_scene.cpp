#include "test_scene.hpp"
#include <cmath>

TestScene::TestScene() {}
TestScene::~TestScene() {}

void TestScene::init() {
    shape.setRadius(40.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(sf::Vector2f(40.f, 40.f));
    shape.setPosition(sf::Vector2f(400.f, 300.f));
}

void TestScene::update(float deltaTime) {
    time += deltaTime;
    shape.setPosition(sf::Vector2f(400.f + std::sin(time * 2.f) * 100.f, 300.f));
}

void TestScene::render(sf::RenderWindow* window) {
    window->draw(shape);
}

void TestScene::handleEvents(const std::optional<sf::Event>& event) {
    // no input handling yet
}
