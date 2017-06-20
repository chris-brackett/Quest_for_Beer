#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

#include "Space.hpp"
using std::string;

class Outside:public Space
{
private:
    
public:
    Outside(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif