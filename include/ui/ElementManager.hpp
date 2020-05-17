#ifndef ELEMENTMANAGER_INCLUDED_HPP
#define ELEMENTMANAGER_INCLUDED_HPP

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <Interactable.hpp>

class ElementManager : public sf::Drawable, public Interactable {
    std::vector<sf::Drawable*> drawables;
    std::vector<Interactable*> interactables;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    ElementManager();
    ~ElementManager();

    template<class T>
    void add(T element);
    void onInteract(sf::Event event);
};

template<class T>
void ElementManager::add (T element){
    sf::Drawable * dptr = dynamic_cast<sf::Drawable*>(element);
    if ( dptr != NULL ){
        drawables.push_back(dptr);
    }
    Interactable * iptr = dynamic_cast<Interactable*>(element);
    if ( iptr != NULL ){
        interactables.push_back(iptr);
    }
}

#endif // ELEMENTMANAGER_INCLUDED_HPP
