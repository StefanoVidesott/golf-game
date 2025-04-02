#include <SFML/Graphics.hpp>

#pragma once

class Application{
    public:
        Application();
        ~Application();

        void run();

    private:
        sf::RenderWindow* window;
        std::optional<sf::Event> event;
        sf::CircleShape shape;

};
