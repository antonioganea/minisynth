#include <ui/Button.hpp>

#include <iostream>

Button::Button()
{
    shape.setSize(sf::Vector2f(120,40));
    shape.setOrigin(60,10);
    shape.setFillColor(sf::Color(64,64,64));
    label << "button";
    label.setRectangleVisisble(false);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(shape);
    target.draw(label);
}

void Button::onInteract(sf::Event event) {
    if ( event.type == sf::Event::MouseButtonPressed ){
        if ( event.mouseButton.button == sf::Mouse::Left ){
            if ( shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) ) {
                shape.setFillColor(sf::Color(128,128,128));
                try{
                    cb();
                }
                catch(std::exception ex){
                    std::cout << "Bad function call on button" << std::endl;
                }
            }
        }
    }
    if ( event.type == sf::Event::MouseButtonReleased ) {
        if ( event.mouseButton.button == sf::Mouse::Left ){
            shape.setFillColor(sf::Color(64,64,64));
        }
    }
}

void Button::setPosition(float x, float y) {
    shape.setPosition(x, y);
    label.setPosition(x, y);
}

void Button::onClick(std::function<void()>&& Callback){
    cb = Callback;
}

void Button::setTitle(std::string str){
    label << str;
}