/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: TastingRoom class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "TastingRoom.hpp"
using std::cout;
using std::endl;
using std::string;

TastingRoom::TastingRoom(Player* playerIn): Space("Tasting Room", playerIn, 6) //default constructor
{
    beerServed = false;
}

/****************
 special: This function performs the special "move" of the space (hook up the keg, then serve the beer).
 ***************/
void TastingRoom::special()
{
    {
        if (actionComplete == false) //if keg is not hooked up
        {
            if (player->searchBackpack("Keg of Beer")) //if player has keg ready to hook up
            {
                actionComplete = true; //update keg status
                cout << "You hooked up the keg. Time to have a beer!" << endl;
                player->removeFromBackpack("Keg of Beer");
            }
            else //if keg is not hooked up and player does not have the keg
                cout << "You don't have a keg of beer to use yet!" << endl;
        }
        else //if the keg is hooked up and ready to serve
        {
            cout << "You pour a perfect pint of beer. Nicely done! Your quest is now complete!" << endl;
            beerServed = true;
        }
    }
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void TastingRoom::displayMenu()
{
    cout << "Current Location: Tasting Room" << endl;
    
    if (actionComplete == false) //if keg has not been hooked up
        cout << "1.) Hook up the keg" << endl;
    else //if keg is hooked up
        cout << "1.) Serve the beer" << endl;
    
    cout << "2.) Go to the supply room" << endl;
    cout << "3.) Go to the brewing room" << endl;
    
    if (menuOptions == 4) //backpack function moves up to 4 after earthquake
        cout << "4.) View contents of backpack" << endl;
    
    if (menuOptions == 6) //if earthquake hasn't happened yet (menuOptions is still 6)
    {
        cout << "4.) Take a long walk to the hops field" << endl;
        cout << "5.) Take a long walk to the barley field" << endl;
        cout << "6.) View contents of backpack" << endl;
    }
    else //if earthquake has happened
        cout << "You can't go back to the fields - they were destroyed in the earthquake!" << endl;
}

/****************
 getBeerServed: This function returns the status of beerSeved (indicates if game has been completed).
 ***************/
bool TastingRoom::getBeerServed()
{
    return beerServed;
}