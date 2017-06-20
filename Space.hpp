#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Player.hpp"
#include "Backpack.hpp"

using std::string;

class Space
{
protected:
    Space* spacePtrs[4];
    string name;
    bool actionComplete;
    Player* player;
    int menuOptions;
    
public:
    Space(string nameIn, Player* playerIn, int menuOptionsIn);
    string getSpaceName();
    virtual void special() = 0;
    virtual void displayMenu() = 0;
    void setPointers(Space* ptr1, Space* ptr2, Space* ptr3, Space* ptr4);
    void setPointers(Space* ptr1, Space* ptr2, Space* ptr3);
    void setPointers(Space* ptr1, Space* ptr2);
    void setPointers(Space* ptr1);
    Space* getPointer(int ptrNumber);
    bool getActionComplete();
    int getMenuOptions();
    void setMenuOptions(int menuOptionsIn);
};

#endif