#include "Label.hpp"

Label::Label() {
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        // error...
    }
    text.setFont(font);
    setMaxWidth(60);
    setText("label");
}

void Label::setTextSize() {
    sf::FloatRect bounds = text.getGlobalBounds();
    if ( bounds.width > maxWidth ) {
        float scale = text.getScale().x;
        float targetScale = scale * static_cast<float>(maxWidth) / static_cast<float>(bounds.width);
        text.setScale(targetScale, targetScale);
    }
}

void Label::setMaxWidth(float width) {
    maxWidth = width;
}

float Label::getMaxWidth() const{
    return maxWidth;
}

void Label::setText(std::string str) {
    text.setString(str);
    setTextSize();
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2.f, bounds.height/2.f);
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(text);
}

void Label::setPosition(float x, float y){
    text.setPosition(x, y);
}
