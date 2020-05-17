#ifndef VIRTUALCONTROLLER_HPP_INCLUDED
#define VIRTUALCONTROLLER_HPP_INCLUDED

#include <SFML/Window/Keyboard.hpp>
#include <cstring>
#include <ctype.h>

#include <iostream>


class VirtualController {
    int getOrder(char ch);
    VirtualController();
    static constexpr VirtualController* instance = 0;
    public:
    int getInputOrder(int key);
    static VirtualController* getInstance();
};

#endif // VIRTUALCONTROLLER_HPP_INCLUDED
