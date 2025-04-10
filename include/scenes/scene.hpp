#pragma once

#include <SFML/Graphics.hpp>
#include "../core/resource_manager.hpp"
#include "../entities/entity.hpp"

class Scene {
public:
    Scene();
    virtual ~Scene();

    virtual void init();
    virtual void onEnter();
    virtual void onExit();
    virtual void handleEvents(const std::optional<sf::Event>&);
    virtual void earlyUpdate(float deltaTime);
    virtual void fixedUpdate(float fixedDeltaTime);
    virtual void update(float deltaTime);
    virtual void lateUpdate(float deltaTime);
    virtual void render(sf::RenderWindow*);

    bool isInitialized = false;
protected:
    std::vector<std::unique_ptr<Entity>> entities;
};
