#include "application.hpp"

Application::Application()
{
    this->window = new sf::RenderWindow(sf::VideoMode({200, 200}), "SFML works!");
    this->shape = sf::CircleShape(100.f);
}

Application::~Application()
{
    delete this->window;
}

void Application::run()
{
    shape.setFillColor(sf::Color::Green);

    while (this->window->isOpen())
    {
        while (this->event = this->window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window->close();
        }

        this->window->clear();
        this->window->draw(shape);
        this->window->display();
    }
}