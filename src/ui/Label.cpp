#include <ui/Label.hpp>

#include <AssetsRegistry.hpp>

Label::Label() {
    text.setFont(*AssetsRegistry::loadFont("assets/arial.ttf"));
    setMaxWidth(60);
    (*this) << "label";
    //setBackgroundRectangle();
    rectangleVisible = true;
}

void Label::setBackgroundRectangle() {
    sf::FloatRect bounds = text.getGlobalBounds();
    constexpr float border = 3.f;
    rectangle.setSize(sf::Vector2f(bounds.width + border, bounds.height + border));
    sf::Vector2f origin = rectangle.getSize()/2.f;
    origin.y -= 5.f;
    rectangle.setOrigin(origin);
    rectangle.setFillColor(sf::Color(64,64,64));
}

void Label::setTextSize() {
    sf::FloatRect bounds = text.getGlobalBounds();
    if ( bounds.width > maxWidth ) {
        float scale = text.getScale().x;
        float targetScale = scale * static_cast<float>(maxWidth) / static_cast<float>(bounds.width);
        text.setScale(targetScale, targetScale);
    }
    setBackgroundRectangle();
}

void Label::setMaxWidth(float width) {
    maxWidth = width;
    setTextSize();
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
    if ( rectangleVisible )
        target.draw(rectangle);
    target.draw(text);
}

void Label::setPosition(float x, float y){
    text.setPosition(x, y);
    rectangle.setPosition(x, y);
}

void Label::setRectangleVisisble(bool state){
    rectangleVisible = state;
}

void Label::operator<<(const std::string& str){
    setText(str);
}