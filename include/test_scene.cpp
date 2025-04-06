#include "test_scene.hpp"

TestScene::TestScene() {
    this->init();
}

TestScene::~TestScene() {

}

void TestScene::init() {
    this->shape = sf::CircleShape(100.f);
    this->shape.setFillColor(sf::Color::Green);
}

void TestScene::update() {

}

void TestScene::render(sf::RenderWindow* window) {
    window->draw(this->shape);
}

void TestScene::handleEvents(std::optional<sf::Event>* event) {

}
