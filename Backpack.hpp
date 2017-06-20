#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <string>
using std::string;

class Backpack
{
protected:
    string backpack[3];
    
public:
    Backpack();
    void displayBackpack();
    void addToBackpack(string itemIn);
    void removeFromBackpack(string itemIn);
    bool searchBackpack(string itemIn);
};

#endif