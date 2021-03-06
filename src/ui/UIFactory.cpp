#include "UIFactory.hpp"

Button* UIFactory::createButton( std::string str, int x, int y ){
    Button * button = new Button();
    button->setTitle(str);
    button->setPosition(x, y);
    return button;
}

Knob* UIFactory::createKnob(std::string str, int x, int y){
    Knob * knob = new Knob();
    knob->setPosition(x,y);
    knob->setTitle(str);
    return knob;
}

std::unique_ptr<BayanKeyboard> UIFactory::createBayanKeyboard(){
    return std::make_unique<BayanKeyboard>();
}