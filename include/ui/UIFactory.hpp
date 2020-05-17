#ifndef UIFACTORY_HPP
#define UIFACTORY_HPP

#include <ui/Button.hpp>

class UIFactory
{
    UIFactory();
public:
    static Button* createButton( std::string str, int x, int y );
};

#endif // UIFACTORY_HPP
