/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: SupplyRoomCabinet class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "SupplyRoomCabinet.hpp"
using std::cout;
using std::endl;
using std::string;

SupplyRoomCabinet::SupplyRoomCabinet(Player* playerIn): Space("Supply Room Cabinet", playerIn, 3) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (pick up yeast).
 ***************/
void SupplyRoomCabinet::special()
{
    if (actionComplete == true) //if yeast has already been picked up
        cout << "You already grabbed the yeast. Not much else to see here..." << endl;
    else //if yeast has not been picked up yet
    {
        player->addToBackpack("Yeast"); //add yeast to backpack
        actionComplete = true;
    }
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void SupplyRoomCabinet::displayMenu()
{
    cout << "Current Location: Supply Room Cabinet" << endl;
    cout << "1.) Pick up yeast" << endl;
    cout << "2.) Close the cabinet and go to the supply room" << endl;
    cout << "3.) View contents of backpack" << endl;
}