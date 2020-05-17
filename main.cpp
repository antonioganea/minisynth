#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ui/BayanKeyboard.hpp>
#include <VirtualController.hpp>
#include <cmath>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 200), "Minisynth");

    window.setKeyRepeatEnabled(false);

    BayanKeyboard * keyboard = new BayanKeyboard();

    VirtualController* vc = VirtualController::getInstance();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::KeyPressed){
                int key = vc->getInputOrder(event.key.code);
                cout << event.key.code << " " << key << endl;
                if ( key != -1){
                    keyboard->press(key);
                }
            }

            if (event.type == sf::Event::KeyReleased){
                int key = vc->getInputOrder(event.key.code);
                //cout << event.key.code << " " << key << endl;
                if ( key != -1)
                    keyboard->release(key);
            }


            /*
            if (event.type == sf::Event::TextEntered){
                cout << event.text.unicode << " " << getOrder(event.text.unicode) << endl;
            }
            */
        }

        window.clear();
        window.draw(*keyboard);
        window.display();
    }

    return 0;
}