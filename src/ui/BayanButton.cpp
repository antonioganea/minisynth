#include <ui/BayanButton.hpp>

void BayanButton::press(){
    circle.setFillColor(sf::Color::Red);
}

void BayanButton::release(){
    circle.setFillColor(sf::Color::Blue);
}

void BayanButton::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(circle);
}

void BayanButton::setPosition(float x, float y){
    circle.setPosition(x, y);
}

BayanButton::BayanButton(bool isWhite){
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(15.f);
    circle.setPointCount(15);
};
