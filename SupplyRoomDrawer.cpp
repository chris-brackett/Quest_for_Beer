/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: SupplyRoomDrawer class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "SupplyRoomDrawer.hpp"
using std::cout;
using std::endl;
using std::string;

SupplyRoomDrawer::SupplyRoomDrawer(Player* playerIn): Space("Supply Room Drawer", playerIn, 3) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (look at the recipe).
 ***************/
void SupplyRoomDrawer::special()
{
    cout << "It looks like there is a recipe in here! The recipe reads:" << endl;
    cout << "Step 1 - Gather hops, barley, and yeast." << endl;
    cout << "Step 2 - Brew the beer using the three ingredients." << endl;
    cout << "Step 3 - Transfer the beer to a keg." << endl;
    cout << "Step 4 - Serve the beer and enjoy!" << endl;
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void SupplyRoomDrawer::displayMenu()
{
    cout << "Current Location: Supply Room Drawer" << endl;
    cout << "1.) Read the paper in the drawer" << endl;
    cout << "2.) Go back to the supply room" << endl;
    cout << "3.) View contents of backpack" << endl;
}