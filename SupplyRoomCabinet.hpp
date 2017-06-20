#ifndef SUPPLYROOMCABINET_HPP
#define SUPPLYROOMCABINET_HPP

#include "Space.hpp"
using std::string;

class SupplyRoomCabinet:public Space
{
private:
    
public:
    SupplyRoomCabinet(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif