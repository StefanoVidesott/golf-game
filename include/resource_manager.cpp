#include "resource_manager.hpp"
#include <stdexcept>
#include <iostream>

std::unordered_map<std::string, std::unique_ptr<sf::Texture>> ResourceManager::textures;
std::unordered_map<std::string, std::unique_ptr<sf::Font>> ResourceManager::fonts;
std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> ResourceManager::soundBuffers;

void ResourceManager::init() {
    // (optional) pre-load core assets here
}

void ResourceManager::cleanup() {
    textures.clear();
    fonts.clear();
    soundBuffers.clear();
}

void ResourceManager::throwIfFileNotFound(bool success, const std::string& path) {
    if (!success) {
        throw std::runtime_error("Failed to load resource: " + path);
    }
}

sf::Texture& ResourceManager::getTexture(const std::string& path) {
    auto it = textures.find(path);
    if (it != textures.end()) return *it->second;

    auto texture = std::make_unique<sf::Texture>();
    throwIfFileNotFound(texture->loadFromFile(path), path);
    textures[path] = std::move(texture);
    return *textures[path];
}

sf::Font& ResourceManager::getFont(const std::string& path) {
    auto it = fonts.find(path);
    if (it != fonts.end()) return *it->second;

    auto font = std::make_unique<sf::Font>();
    throwIfFileNotFound(font->openFromFile(path), path);
    fonts[path] = std::move(font);
    return *fonts[path];
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& path) {
    auto it = soundBuffers.find(path);
    if (it != soundBuffers.end()) return *it->second;

    auto buffer = std::make_unique<sf::SoundBuffer>();
    throwIfFileNotFound(buffer->loadFromFile(path), path);
    soundBuffers[path] = std::move(buffer);
    return *soundBuffers[path];
}
