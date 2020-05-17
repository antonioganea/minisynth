#include <ui/Knob.hpp>

#include <Utils.hpp>

#include <cmath>

#define INDICATOR_RADIUS 25.f

void Knob::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(circle);
    target.draw(indicatorCircle);
    target.draw(nameLabel);
}

void Knob::setPosition(float x, float y){
    circle.setPosition(x, y);
    nameLabel.setPosition(x, y - 50);
    setIndicator();
}

Knob::Knob(){
    percent = 0.5f;

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
    float tau = M_PI * 2.f;
    float lowOpeningRatio = 1/6.f;
    float lowOpening = tau * lowOpeningRatio;
    return percent * tau / ( tau / (tau - lowOpening)) + M_PI/2 + lowOpening / 2.f;
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
        sf::Vector2f position = circle.getPosition();
        float radius = circle.getRadius();
        if ( utils::getDistance(event.mouseWheelScroll.x,event.mouseWheelScroll.y, position.x, position.y) < radius ) {
            float delta = 0.05f;
            delta *= event.mouseWheelScroll.delta;
            //setPercent(getPercent()+delta);
            (*this)+=delta;
        }
    }
}

void Knob::setTitle(std::string str) {
    nameLabel << str;
}

void Knob::operator+=(const float& val){
    float p;
    (*this)>>p;
    p+=val;
    (*this)<<p;
}

Knob& Knob::operator>>(float& percent){
    percent = getPercent();
}
void Knob::operator<<(const float& percent){
    setPercent(percent);
}