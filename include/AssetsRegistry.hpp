#ifndef ASSETSREGISTRY_H
#define ASSETSREGISTRY_H

#include <SFML/Graphics/Font.hpp>
#include <map>
#include <string>

class AssetsRegistry
{
    static std::map<std::string,sf::Font*> fonts;
    public:
        static sf::Font* loadFont(std::string path);
};

#endif // ASSETSREGISTRY_H
