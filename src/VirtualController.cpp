#include <VirtualController.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <cstring>
#include <ctype.h>

const char bayanOrder[] = "zswxdecfrvgtbhynjumki,lo.;p/'[";

const int inputOrder[30] = {
    sf::Keyboard::Z,
    sf::Keyboard::S,
    sf::Keyboard::W,

    sf::Keyboard::X,
    sf::Keyboard::D,
    sf::Keyboard::E,

    sf::Keyboard::C,
    sf::Keyboard::F,
    sf::Keyboard::R,

    sf::Keyboard::V,
    sf::Keyboard::G,
    sf::Keyboard::T,

    sf::Keyboard::B,
    sf::Keyboard::H,
    sf::Keyboard::Y,

    sf::Keyboard::N,
    sf::Keyboard::J,
    sf::Keyboard::U,

    sf::Keyboard::M,
    sf::Keyboard::K,
    sf::Keyboard::I,

    sf::Keyboard::Comma,
    sf::Keyboard::L,
    sf::Keyboard::O,

    sf::Keyboard::Period,
    sf::Keyboard::SemiColon,
    sf::Keyboard::P,

    sf::Keyboard::Slash,
    sf::Keyboard::Quote,
    sf::Keyboard::LBracket,
};

constexpr int inputs = sizeof(inputOrder) / sizeof(int);

int VirtualController::getOrder(char ch){
    char * location = strchr(bayanOrder, tolower(ch));
    if ( location == NULL ) return -1;
    return location-bayanOrder;
}

VirtualController::VirtualController() {

}
static constexpr VirtualController* instance = 0;
int VirtualController::getInputOrder(int key) {
    for ( int i = 0; i < 30; i++ ) {
        if ( inputOrder[i] == key ){
            return i;
        }
    }
    return -1;
}
VirtualController* VirtualController::getInstance() {
    return instance;
}
