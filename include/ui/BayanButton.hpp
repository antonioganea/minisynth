#ifndef BAYANBUTTON_HPP_INCLUDED
#define BAYANBUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class BayanButton : public sf::Drawable{
private:
    sf::CircleShape circle;
    bool state;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    BayanButton(bool isWhite = true);
    void setState(bool state);
    void setPosition(float x, float y);
    void press();
    void release();
};

#endif // BAYANBUTTON_HPP_INCLUDED
