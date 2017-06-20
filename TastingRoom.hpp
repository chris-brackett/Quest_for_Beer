#ifndef TASTINGROOM_HPP
#define TASTINGROOM_HPP

#include "Space.hpp"
using std::string;

class TastingRoom:public Space
{
private:
    bool beerServed;
public:
    TastingRoom(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
    bool getBeerServed();
};

#endif