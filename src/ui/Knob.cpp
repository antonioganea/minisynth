#include <ui/Knob.hpp>

#include <cmath>
#include <iostream>

#define INDICATOR_RADIUS 25.f

#define BAD_PI 3.14f

void Knob::click(){
    circle.setFillColor(sf::Color::Red);
}

void Knob::release(){
    circle.setFillColor(sf::Color::Blue);
}

void Knob::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(circle);
    target.draw(indicatorCircle);
}

void Knob::setPosition(float x, float y){
    circle.setPosition(x, y);
    setIndicator();
}

Knob::Knob(){
    percent = 0.f;

    circle.setFillColor(sf::Color(32,32,32));
    circle.setRadius(30.f);
    circle.setPointCount(25);
    circle.setOrigin(30.f,30.f);

    indicatorCircle.setFillColor(sf::Color(200,200,200));
    indicatorCircle.setRadius(5.f);
    indicatorCircle.setPointCount(25);
    indicatorCircle.setOrigin(5.f,5.f);
};

float Knob::percentToAngle(float percent) {
    float tau = BAD_PI * 2.f;
    float lowOpeningRatio = 1/6.f;
    float lowOpening = tau * lowOpeningRatio;
    return percent * tau / ( tau / (tau - lowOpening)) + BAD_PI/2 + lowOpening / 2.f;
}

void Knob::setIndicator() {
    sf::Vector2f position = circle.getPosition();

    float angle = percentToAngle(percent);

    position.x += INDICATOR_RADIUS * cos(angle);
    position.y += INDICATOR_RADIUS * sin(angle);

    indicatorCircle.setPosition(position);
}

void Knob::setPercent(float value) {
    if ( value > 1.f ) {
        percent = 1.f;
    } else if ( value < 0.f ) {
        percent = 0.f;
    } else {
        percent = value;
    }
    setIndicator();
}

float Knob::getPercent() const{
    return percent;
}

void Knob::onInteract(sf::Event event) {

    if ( event.type == sf::Event::MouseWheelScrolled ){
        float delta = 0.1f;
        //std::cout<<"HEY " << event.mouseWheelScroll.delta << std::endl;
        delta *= event.mouseWheelScroll.delta;
        setPercent(getPercent()+delta);
    }

    if ( event.type == sf::Event::KeyPressed ){
        setPercent(getPercent()+0.1f);
    }
}