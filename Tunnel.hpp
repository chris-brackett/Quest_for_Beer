#ifndef TUNNEL_HPP
#define TUNNEL_HPP

#include "Space.hpp"
using std::string;

class Tunnel:public Space
{
private:

public:
    Tunnel(Player* playerIn);
    virtual void special();
    virtual void displayMenu();
};

#endif