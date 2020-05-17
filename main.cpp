#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ui/BayanKeyboard.hpp>
#include <VirtualController.hpp>
#include <cmath>
#include <ui/Knob.hpp>

#include <SoundSynth.h>
#include <ui/Button.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "Minisynth");
    window.setKeyRepeatEnabled(false);
    BayanKeyboard * keyboard = new BayanKeyboard();

    VirtualController* vc = VirtualController::getInstance();

    Knob * myKnob = new Knob();
    myKnob->setPosition(30,150);
    myKnob->setTitle("Sustain");

    SoundSynth * synth = new SoundSynth();

    Button * button = new Button();
    button->setPosition(200,300);
    button->onClick([](){std::cout<<"Hello world"<<std::endl;});

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
                    //synth->play(440.f);
                    synth->playNote(key);
                }
            }

            if (event.type == sf::Event::KeyReleased){
                int key = vc->getInputOrder(event.key.code);
                //cout << event.key.code << " " << key << endl;
                if ( key != -1)
                    keyboard->release(key);
            }

            myKnob->onInteract(event);
            button->onInteract(event);
        }

        window.clear();
        window.draw(*keyboard);
        window.draw(*myKnob);
        window.draw(*button);
        window.display();
    }

    return 0;
}