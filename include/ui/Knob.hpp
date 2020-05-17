#ifndef KNOB_HPP_INCLUDED
#define KNOB_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <Interactable.hpp>
#include <ui/Label.hpp>

#include <string>

class Knob : public sf::Drawable, public Interactable{
private:
    sf::CircleShape circle;
    sf::CircleShape indicatorCircle;
    Label nameLabel;
    bool state;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setIndicator();
    float percent;
    void setPercent(float value);
    float percentToAngle(float percent);
public:
    Knob();
    void setPosition(float x, float y);
    void click();
    void release();
    void mouseMoved();
    float getPercent() const;
    void onInteract(sf::Event event);
    void setTitle(std::string str);
};


#endif // KNOB_HPP_INCLUDED
