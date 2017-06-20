/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: BarleyField class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "BarleyField.hpp"
using std::cout;
using std::endl;
using std::string;

BarleyField::BarleyField(Player* playerIn): Space("Barley Field", playerIn, 6) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (harvest barley).
 ***************/
void BarleyField::special()
{
    bool hasBarley = false;
    
    if (player->searchBackpack("Barley"))
    {
        cout << "You already have some barley in your backpack! No need for more." << endl;
        hasBarley = true;
    }
    
    if (hasBarley == false)
    {
        player->addToBackpack("Barley"); //add barley to backpack
        //cout << "You harvested some barley! It is now in your backpack." << endl;
    }
    
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void BarleyField::displayMenu()
{
    cout << "Current Location: Barley Field" << endl;
    cout << "1.) Harvest barley" << endl;
    cout << "2.) Head towards the back door of the brewing room" << endl;
    cout << "3.) Jump over the fence to the hops field" << endl;
    cout << "4.) Take a long walk around to the front door of the tasting room" << endl;
    cout << "5.) Climb to the top of the fence between the fields to have a look around" << endl;
    cout << "6.) View contents of backpack" << endl;
}