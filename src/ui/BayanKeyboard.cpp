#include <ui/BayanKeyboard.hpp>

void BayanKeyboard::press(int button){
    buttons[button]->press();
}

void BayanKeyboard::release(int button){
    buttons[button]->release();
}

BayanKeyboard::BayanKeyboard(){
    const int columns = 3;
    const int rows = 10;
    for ( int j = 0; j < rows; j++ ){
        for ( int i = 0;i < columns; i++ ){
            BayanButton * newButton = new BayanButton();
            newButton->setPosition( j*35+ (!!(i&1))*15, (2-i)*30 );
            buttons.push_back(newButton);
        }
    }
}

void BayanKeyboard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for ( std::vector<BayanButton*>::const_iterator it = buttons.begin(); it != buttons.end(); it++ ){
        target.draw(**it);
    }
}