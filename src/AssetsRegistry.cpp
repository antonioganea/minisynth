#include "AssetsRegistry.hpp"

#include <iostream>

std::map<std::string,sf::Font*> AssetsRegistry::fonts;

sf::Font* AssetsRegistry::loadFont(std::string path){
    std::cout << "[AssetRegistry] Requested font " << path;
    if ( AssetsRegistry::fonts.find(path) == AssetsRegistry::fonts.end() ){
        std::cout << " loading from file" << std::endl;
        sf::Font * font = new sf::Font();
        font->loadFromFile(path);
        AssetsRegistry::fonts.emplace(path,font);
        return font;
    }
    else {
        std::cout << " served from memory" << std::endl;
        return AssetsRegistry::fonts.at(path);
    }
}