#include "ElementManager.hpp"

#include <SFML/Graphics.hpp>

ElementManager::ElementManager()
{
    //ctor
}

ElementManager::~ElementManager()
{
    //dtor
}

/*
template<typename T>
void ElementManager::add(T element){
    sf::Drawable * ptr = dynamic_cast<sf::Drawable*>(element);
    if ( ptr != NULL ){
        drawables.push_back(ptr);
    }
}
*/

void ElementManager::add(sf::Drawable * element){
        drawables.push_back(element);

}

void ElementManager::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for( auto & drawable : drawables ){
        target.draw(*drawable);
    }
}

void ElementManager::onInteract(sf::Event event){

}