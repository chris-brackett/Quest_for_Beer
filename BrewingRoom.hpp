#ifndef BREWINGROOM_HPP
#define BREWINGROOM_HPP

#include "Space.hpp"
using std::string;

class BrewingRoom:public Space
{
private:
    bool beerTransferred;
public:
    BrewingRoom(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif