#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Space.hpp"
using std::string;

class Window:public Space
{
private:
    
public:
    Window(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif