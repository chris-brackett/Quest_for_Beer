/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Outside class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Outside.hpp"
using std::cout;
using std::endl;
using std::string;

Outside::Outside(Player* playerIn): Space("Outside", playerIn, 6) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (read the sign).
 ***************/
void Outside::special()
{
    bool hasBarley = false;
    bool hasHops = false;
    
    if (player->searchBackpack("Barley")) //check for barley and hops
        hasBarley = true;
    if (player->searchBackpack("Hops"))
        hasHops = true;
    
    cout << "The sign reads: fresh green hops to the left, ready to harvest golden barley to the right!" << endl;
    if (hasHops)
        cout << "You probably don't need any more hops though." << endl;
    if (hasBarley)
        cout << "I think you have enough barley already, no need to go back to the field." << endl;
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void Outside::displayMenu()
{
    cout << "Current Location: Outside Back Door of Brewing Room" << endl;
    cout << "1.) Read sign" << endl;
    cout << "2.) Go through the back door into the brewing room" << endl;
    cout << "3.) Take a long walk around to the front door of the tasting room" << endl;
    
    if (menuOptions == 4) //move backpack to option 4 after earthquake
        cout << "4.) View contents of backpack" << endl;
    
    if (menuOptions == 6) //only display these options before earthquake / when menuOptions is still 6
    {
    cout << "4.) Go left towards the green field" << endl;
    cout << "5.) Go right towards the golden field" << endl;
    cout << "6.) View contents of backpack" << endl;
    }
    else //if earthquake has happened
        cout << "You can't go back to the fields - they were destroyed in the earthquake!" << endl;
    
}