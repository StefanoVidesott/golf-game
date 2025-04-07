#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class ResourceManager {
public:
    static void init();
    static void cleanup();

    static sf::Texture& getTexture(const std::string& path);
    static sf::Font& getFont(const std::string& path);
    static sf::SoundBuffer& getSoundBuffer(const std::string& path);

private:
    static std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
    static std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
    static std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> soundBuffers;

    static void throwIfFileNotFound(bool success, const std::string& path);
};
