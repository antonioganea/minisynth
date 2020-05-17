#include "AssetsRegistry.hpp"

#include <iostream>

std::map<std::string,std::shared_ptr<sf::Font>> AssetsRegistry::fonts;

std::shared_ptr<sf::Font> AssetsRegistry::loadFont(std::string path){
    std::cout << "[AssetRegistry] Requested font " << path;
    if ( AssetsRegistry::fonts.find(path) == AssetsRegistry::fonts.end() ){
        std::cout << " loading from file" << std::endl;
        std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
        font->loadFromFile(path);
        AssetsRegistry::fonts.emplace(path,font);
        return font;
    }
    else {
        std::cout << " served from memory" << std::endl;
        return AssetsRegistry::fonts.at(path);
    }
}