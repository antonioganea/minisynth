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

    //template<class T>
    void add(sf::Drawable * element);
    void lalala();

    void onInteract(sf::Event event);
};

#endif // ELEMENTMANAGER_INCLUDED_HPP
