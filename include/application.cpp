#include "application.hpp"

Application::Application()
{
    this->window = new sf::RenderWindow(sf::VideoMode({200, 200}), "SFML works!");
    this->currentScene = nullptr;

    // this->loadScene(new TestScene);
}

Application::~Application()
{
    delete this->window;
}

void Application::loadScene(Scene* scene) {
    this->scenes.push(scene);
    this->currentScene = scene;
}

void Application::dropScene(){
    this->scenes.pop();

    Scene* dropped_scene = this->currentScene;
    this->currentScene = this->scenes.front();
}

void Application::run()
{
    while (this->window->isOpen())
    {
        while (this->event = this->window->pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                this->window->close();
            }
        }

        this->window->clear();
        if (this->currentScene != nullptr) {
            this->currentScene->render(this->window);
        }
        this->window->display();
    }
}