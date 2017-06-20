/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: HopsField class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "HopsField.hpp"
using std::cout;
using std::endl;
using std::string;

HopsField::HopsField(Player* playerIn): Space("Hops Field", playerIn, 6) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (harvest hops).
 ***************/
void HopsField::special()
{
    bool hasHops = false;
    
    if (player->searchBackpack("Hops"))
    {
        cout << "You already have some hops in your backpack! No need for more." << endl;
        hasHops = true;
    }
    
    if (hasHops == false)
    {
        player->addToBackpack("Hops"); //add hops to backpack
        //cout << "You harvested some hops! They are now in your backpack." << endl;
    }
    
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void HopsField::displayMenu()
{
    cout << "Current Location: Hops Field" << endl;
    cout << "1.) Harvest hops" << endl;
    cout << "2.) Head towards the back door of the brewing room" << endl;
    cout << "3.) Jump over the fence to the barley field" << endl;
    cout << "4.) Take a long walk around to the front door of the tasting room" << endl;
    cout << "5.) Climb to the top of the fence between the fields to have a look around" << endl;
    cout << "6.) View contents of backpack" << endl;
}