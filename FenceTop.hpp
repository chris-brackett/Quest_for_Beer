#ifndef FENCETOP_HPP
#define FENCETOP_HPP

#include "Space.hpp"
using std::string;

class FenceTop:public Space
{
private:
    
public:
    FenceTop(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif