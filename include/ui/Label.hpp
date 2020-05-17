#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Label : public sf::Drawable
{
    sf::Font font;
    sf::Text text;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setTextSize();
    float maxWidth;
    public:
        Label();
        void setText(std::string str);
        void setPosition(float x, float y);
        void setMaxWidth(float width);
        float getMaxWidth() const;
};

#endif // LABEL_HPP_INCLUDED
