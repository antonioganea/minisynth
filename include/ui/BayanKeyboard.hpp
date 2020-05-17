#ifndef BAYANKEYBOARD_HPP_INCLUDED
#define BAYANKEYBOARD_HPP_INCLUDED

#include <ui/BayanButton.hpp>
#include <vector>

class BayanKeyboard : public sf::Drawable{
private:
    std::vector<BayanButton*> buttons;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    BayanKeyboard();
    /*
    friend ostream & operator<<(ostream &os, const BayanKeyboard& p) {
        return os << "Hello";
    }
    */

    void press(int button);
    void release(int button);
};


#endif // BAYANKEYBOARD_HPP_INCLUDED
