/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: FenceTop class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "FenceTop.hpp"
using std::cout;
using std::endl;
using std::string;

FenceTop::FenceTop(Player* playerIn): Space("Top of Fence", playerIn, 6) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (harvest barley).
 ***************/
void FenceTop::special()
{
    cout << "From atop the fence, you see a field of hops and a field of barley on either side of you. In the distance, you see the back door to the brewing room." << endl;
    
    bool hasHops = false;
    bool hasBarley = false;
    
    if (player->searchBackpack("Barley")) //check for barley and hops
        hasBarley = true;
    if (player->searchBackpack("Hops"))
        hasHops = true;
    
    if (hasHops == false)
        cout << "There are hops down there! Those could be useful." << endl;
    if (hasBarley == false)
        cout << "There is barley down there! You need some of that!" << endl;
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void FenceTop::displayMenu()
{
    cout << "Current Location: Top of Fence Between Fields" << endl;
    cout << "1.) Take a look around from atop the fence" << endl;
    cout << "2.) Jump down into the barley field" << endl;
    cout << "3.) Jump down into the hops field" << endl;
    cout << "4.) View contents of backpack" << endl;
}