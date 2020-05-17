#include "UIFactory.hpp"

Button* UIFactory::createButton( std::string str, int x, int y ){
    Button * button = new Button();
    button->setTitle(str);
    button->setPosition(x, y);
    return button;
}