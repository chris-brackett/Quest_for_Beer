#ifndef HOPSFIELD_HPP
#define HOPSFIELD_HPP

#include "Space.hpp"
using std::string;

class HopsField:public Space
{
private:
    
public:
    HopsField(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif