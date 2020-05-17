#ifndef UIFACTORY_HPP
#define UIFACTORY_HPP

#include <ui/Button.hpp>
#include <ui/Knob.hpp>
#include <ui/BayanKeyboard.hpp>

#include <memory>

class UIFactory
{
    UIFactory();
public:
    static Button* createButton(std::string str, int x, int y);
    static Knob* createKnob(std::string str, int x, int y);
    static std::unique_ptr<BayanKeyboard> createBayanKeyboard();
};

#endif // UIFACTORY_HPP
