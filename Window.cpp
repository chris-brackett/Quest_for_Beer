/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Window class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Window.hpp"
using std::cout;
using std::endl;
using std::string;

Window::Window(Player* playerIn): Space("Brewing Room Window", playerIn, 3) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (look out the window).
 ***************/
void Window::special()
{
    bool hasBarley = false;
    bool hasHops = false;
    
    if (player->searchBackpack("Barley")) //check for barley and hops
        hasBarley = true;
    if (player->searchBackpack("Hops"))
        hasHops = true;
    
    if (hasBarley && hasHops) //if player has all ingredients from outside already
    {
        cout << "Looks like you don't need anything else from outside." << endl;
    }
    else //if a player still needs either barley or hops or both
        cout << "You see green and golden fields in the distance. Perhaps you should go outside!" << endl;
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void Window::displayMenu()
{
    cout << "Current Location: Brewing Room Window" << endl;
    cout << "1.) Look out the window" << endl;
    cout << "2.) Go back into the brewing room" << endl;
    cout << "3.) View contents of backpack" << endl;
}