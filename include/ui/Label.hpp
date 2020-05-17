#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Label : public sf::Drawable
{
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setTextSize();
    void setBackgroundRectangle();
    float maxWidth;
    bool rectangleVisible;
    public:
        Label();
        void setText(std::string str);
        void setPosition(float x, float y);
        void setMaxWidth(float width);
        float getMaxWidth() const;
        void setRectangleVisisble(bool state);
};

#endif // LABEL_HPP_INCLUDED
