#ifndef SUPPLYROOM_HPP
#define SUPPLYROOM_HPP

#include "Space.hpp"
using std::string;

class SupplyRoom:public Space
{
private:
    
public:
    SupplyRoom(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif