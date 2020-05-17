#include <ui/ElementManager.hpp>

#include <SFML/Graphics.hpp>

ElementManager::ElementManager()
{
    //ctor
}

ElementManager::~ElementManager()
{
    //dtor
}

void ElementManager::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for( auto & drawable : drawables ){
        target.draw(*drawable);
    }
}

void ElementManager::onInteract(sf::Event event){
    for( auto & interactable : interactables ){
        interactable->onInteract(event);
    }
}