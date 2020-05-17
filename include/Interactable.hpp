#ifndef INTERACTABLE_HPP_INCLUDED
#define INTERACTABLE_HPP_INCLUDED

#include <SFML/Window/Event.hpp>

class Interactable
{
    public:
        virtual void onInteract(sf::Event event) = 0;
};

#endif // INTERACTABLE_HPP_INCLUDED
