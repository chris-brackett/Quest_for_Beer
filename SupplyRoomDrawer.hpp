#ifndef SUPPLYROOMDRAWER_HPP
#define SUPPLYROOMDRAWER_HPP

#include "Space.hpp"
using std::string;

class SupplyRoomDrawer:public Space
{
private:
    
public:
    SupplyRoomDrawer(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif