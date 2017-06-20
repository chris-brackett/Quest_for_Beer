#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Backpack.hpp"

using std::string;

class Player
{
protected:
    Backpack* backpack;
    int counter;
    
public:
    Player();
    ~Player();
    int getCounter();
    void addCounter();
    void displayBackpack();
    void addToBackpack(string itemIn);
    void removeFromBackpack(string itemIn);
    bool searchBackpack(string itemIn);
    Backpack* getBackpack();
};

#endif