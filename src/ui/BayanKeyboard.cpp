#include <ui/BayanKeyboard.hpp>

template<typename... Args>
bool any(Args... args) { return (... || args); }

void BayanKeyboard::press(int button){
    if ( any(button > 30, button < 0) ) {
        KeyboardInputFailEx ex;
        throw ex;
    }
    buttons[button]->press();
}

void BayanKeyboard::release(int button){
    if ( any(button > 30, button < 0) ) {
        KeyboardInputFailEx ex;
        throw ex;
    }
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

BayanKeyboard::~BayanKeyboard(){
    for ( auto & button: buttons ){
        delete button;
    }
}

void BayanKeyboard::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for ( std::vector<BayanButton*>::const_iterator it = buttons.begin(); it != buttons.end(); it++ ){
        target.draw(**it);
    }
}