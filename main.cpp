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

    OscillatorType oscType;

    Button * button1 = new Button();
    button1->setTitle("Sine");
    button1->setPosition(200,200);
    button1->onClick([&](){oscType=Sine;});

    Button * button2 = new Button();
    button2->setTitle("Square");
    button2->setPosition(200,240);
    button2->onClick([&](){oscType=Square;});

    Button * button3 = new Button();
    button3->setTitle("Saw");
    button3->setPosition(200,280);
    button3->onClick([&](){oscType=Sawtooth;});

    Button * button4 = new Button();
    button4->setTitle("Triangle");
    button4->setPosition(200,320);
    button4->onClick([&](){oscType=Triangle;});



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
                    synth->playNote(key, oscType);
                }
            }

            if (event.type == sf::Event::KeyReleased){
                int key = vc->getInputOrder(event.key.code);
                //cout << event.key.code << " " << key << endl;
                if ( key != -1)
                    keyboard->release(key);
            }

            myKnob->onInteract(event);
            button1->onInteract(event);
            button2->onInteract(event);
            button3->onInteract(event);
            button4->onInteract(event);
        }

        window.clear();
        window.draw(*keyboard);
        window.draw(*myKnob);
        window.draw(*button1);
        window.draw(*button2);
        window.draw(*button3);
        window.draw(*button4);
        window.display();
    }

    return 0;
}