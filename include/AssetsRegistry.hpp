#ifndef ASSETSREGISTRY_H
#define ASSETSREGISTRY_H

#include <SFML/Graphics/Font.hpp>
#include <map>
#include <string>
#include <memory>

class AssetsRegistry
{
    static std::map<std::string,std::shared_ptr<sf::Font>> fonts;
    public:
        static std::shared_ptr<sf::Font> loadFont(std::string path);
};

#endif // ASSETSREGISTRY_H
