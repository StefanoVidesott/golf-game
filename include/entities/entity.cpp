#include "entity.hpp"

Entity::Entity() {}
Entity::~Entity() {}

void Entity::update(float deltaTime) {
    for (auto& c : components) c->update(deltaTime);
}

void Entity::render(sf::RenderWindow* window) {
    for (auto& c : components) c->render(window);
}
