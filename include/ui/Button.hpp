#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED


#include <SFML/Graphics.hpp>
#include <Interactable.hpp>
#include <ui/Label.hpp>

#include <functional>

#include <string>

class Button : public sf::Drawable, public Interactable{
private:
    sf::RectangleShape shape;
    Label label;
    Label nameLabel;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::function<void()> cb;
public:
    Button();
    void setPosition(float x, float y);
    void onInteract(sf::Event event);
    void setTitle(std::string str);

    void onClick(std::function<void()>&& Callback);
};


#endif // BUTTON_HPP_INCLUDED