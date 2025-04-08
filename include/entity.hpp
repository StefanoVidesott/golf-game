#pragma once
#include <vector>
#include <memory>
#include "component.hpp"

class Entity {
public:
    Entity();
    ~Entity();

    void update(float);
    void render(sf::RenderWindow*);

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = component.get();
        components.push_back(std::move(component));
        return ptr;
    }

    template<typename T>
    T* getComponent()  {
        for (auto& c : components) {
            if (T* casted = dynamic_cast<T*>(c.get())) {
                return casted;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<Component>> components;
};
