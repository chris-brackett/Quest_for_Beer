#ifndef BARLEYFIELD_HPP
#define BARLEYFIELD_HPP

#include "Space.hpp"
using std::string;

class BarleyField:public Space
{
private:
    
public:
    BarleyField(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif