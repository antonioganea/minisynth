#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ui/BayanKeyboard.hpp>
#include <VirtualController.hpp>
#include <cmath>
#include <ui/Knob.hpp>

#include <SoundSynth.h>
#include <ui/Button.hpp>

#include <ui/UIFactory.hpp>
#include <ui/ElementManager.hpp>

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "Minisynth");
    window.setKeyRepeatEnabled(false);
    BayanKeyboard * keyboard = UIFactory::createBayanKeyboard();

    VirtualController* vc = VirtualController::getInstance();

    Knob * durationKnob = UIFactory::createKnob("Duration", 30, 150);

    ElementManager emanager;
    emanager.add(durationKnob);

    SoundSynth synth;

    OscillatorType oscType;

    Button * button1 = UIFactory::createButton("Sine", 200, 200);
    button1->onClick([&](){oscType=Sine;});
    emanager.add(button1);

    Button * button2 = UIFactory::createButton("Square", 200, 240);
    button2->onClick([&](){oscType=Square;});
    emanager.add(button2);

    Button * button3 = UIFactory::createButton("Saw", 200, 280);
    button3->onClick([&](){oscType=Sawtooth;});
    emanager.add(button3);

    Button * button4 = UIFactory::createButton("Triangle", 200, 320);
    button4->onClick([&](){oscType=Triangle;});
    emanager.add(button4);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed){
                int key = vc->getInputOrder(event.key.code);
                //cout << event.key.code << " " << key << endl;
                try{
                    keyboard->press(key);
                    //synth->play(440.f);
                    synth.playNote(key, oscType);
                }catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }
            }

            if (event.type == sf::Event::KeyReleased){
                int key = vc->getInputOrder(event.key.code);
                //cout << event.key.code << " " << key << endl;

                try{
                    keyboard->release(key);
                }catch(std::exception& ex){
                    std::cout << ex.what() << std::endl;
                }

            }
            emanager.onInteract(event);
        }

        window.clear();
        window.draw(*keyboard);
        window.draw(emanager);
        window.display();
    }

    return 0;
}