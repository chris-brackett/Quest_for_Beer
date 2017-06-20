/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: SupplyRoom class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "SupplyRoom.hpp"
using std::cout;
using std::endl;
using std::string;

SupplyRoom::SupplyRoom(Player* playerIn): Space("Supply Room", playerIn, 1) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (turn the lights on, then pick up the keg).
 ***************/
void SupplyRoom::special()
{
    if (actionComplete == false) //if lights are off
    {
        actionComplete = true; //update light status
        menuOptions = 6; //update number of menu options
        cout << "You turned the lights on. Now what would you like to do?" << endl;
    }
    else //if lights are on and picking up a keg
    {
        if (spacePtrs[0]->getActionComplete() == false) //if the beer has not been brewed
        {
            cout << "You should work on brewing a beer before getting the keg. You don't want to fill up your backpack with things you don't need yet!" << endl;
        }
        else //if the beer has been brewed
        {
            cout << "You grabbed a keg off the floor." << endl;
            player->addToBackpack("Keg");
        }
    }
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void SupplyRoom::displayMenu()
{
    cout << "Current Location: Supply Room" << endl;
    
    if (actionComplete == false) //if lights have not been turned on
        cout << "1.) Turn on the lights" << endl;
    else //if lights are already on
    {
        cout << "1.) Pick up a keg" << endl;
        cout << "2.) Go to the brewing room" << endl;
        cout << "3.) Go to the tasting room" << endl;
        cout << "4.) Open the cabinet" << endl;
        cout << "5.) Open the drawer" << endl;
        cout << "6.) View contents of backpack" << endl;
    }
}