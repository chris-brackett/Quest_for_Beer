/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Tunnel class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Tunnel.hpp"
using std::cout;
using std::endl;
using std::string;

Tunnel::Tunnel(Player* playerIn): Space("Tunnel", playerIn, 1) //default constructor
{
}

/****************
 special: This function performs the special "move" of the space (hook up the keg, then serve the beer).
 ***************/
void Tunnel::special()
{
    {
        if (actionComplete == false) //if flashlight is off
        {
            cout << "You turned on your flashlight. You can see that you're in a tunnel. You've heard the legends of an old beer smuggling tunnel, but you never thought you would find it! It looks like there is only one way to go. Is that a trap door into the supply room cabinet?" << endl;
            menuOptions = 3; //update number of menu options
            actionComplete = true; //update action status
        }
        else //if the flashlight is on
        {
            cout << "You should probably leave your flashlight on so you can see..." << endl;
        }
    }
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void Tunnel::displayMenu()
{
    if (actionComplete == false) //if flashlight is off
    {
        cout << "Current Location: Unknown" << endl;
        cout << "1.) Turn on flashlight" << endl;
    }
    else //if flashlight is on
    {
        cout << "Current Location: Tunnel" << endl;
        cout << "1.) Turn off flashlight" << endl;
        cout << "2.) Continue forward through the tunnel" << endl;
        cout << "3.) View contents of backpack" << endl;
    }
}