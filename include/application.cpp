#include "application.hpp"

Application::Application()
{
    this->window = new sf::RenderWindow(sf::VideoMode({200, 200}), "SFML works!");
    this->currentScene = nullptr;
    this->scenes = std::queue<Scene*>();
}

Application::~Application()
{
    delete this->window;
    delete this->currentScene;
    while (!scenes.empty()) {
        delete scenes.front();
        scenes.pop();
    }
}

void Application::loadScene(Scene* scene) {
    this->scenes.push(scene);
    this->currentScene = scene;
}

void Application::dropScene(){
    if (!this->scenes.empty())
    {
        delete this->scenes.front();
        this->scenes.pop();
        this->currentScene = this->scenes.front();
    }
}

void Application::update()
{
    if (this->currentScene != nullptr) {
        this->currentScene->update();
    }
}

void Application::render()
{
    this->window->clear();
    if (this->currentScene != nullptr) {
        this->currentScene->render(this->window);
    }
    this->window->display();
}

void Application::handleEvents()
{
    while (std::optional<sf::Event> event = this->window->pollEvent())
    {
        if (event->is<sf::Event::Closed>()) {
            this->window->close();
        }
        if (this->currentScene != nullptr) {
            this->currentScene->handleEvents(&event);
        }
    }
}

void Application::run()
{
    while (this->window->isOpen())
    {
        this->handleEvents();
        this->update();
        this->render();
    }
}
