/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Backpack Class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Backpack.hpp"

using std::cout;
using std::endl;
using std::string;

Backpack::Backpack() //default constructor
{
    for (int i = 0; i < 3; i++)
        backpack[i] = "No Item"; //initialize backpack to be empty
}

/****************
 displayBackpack: This function displays the contents of the backpack.
 ***************/
void Backpack::displayBackpack()
{
    cout << "Backpack Contents:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "Item " << i+1 << ": " << backpack[i] << endl;
}

/****************
 addToBackpack: This function adds an item to the backpack.
 ***************/
void Backpack::addToBackpack(string itemIn)
{
    bool added = false;
    bool duplicate = false;
    bool backpackFull = false;
    
    int full = 0;
    
    for (int i = 0; i < 3; i++) //check if backpack is full
    {
        if (backpack[i] != "No Item")
            full = full + 1; //increment full
    }
    
    if (full == 3) //if the backpack is full
        backpackFull = true;
    
    for (int i = 0; i < 3; i++)
    {
        if (backpack[i] == itemIn) //checking for duplicates
        {
            cout << "This item is already in your backpack!" << endl;
            duplicate = true;
        }
        
        if (added == false && duplicate == false) //if item hasn't already been added and is not a duplicate
        {
            if (backpack[i] == "No Item") //if backpack slot is not already taken
            {
                backpack[i] = itemIn; //put new item in that slot
                added = true; //update bool value to indicate item has been added
                cout << itemIn << " successfully added to your backpack." << endl; //inform the user
            }
        }
    }
    
    if (backpackFull == true && duplicate == false) //if item did not get added because backpack is full
        cout << "Your backpack is already full! You can only carry up to 3 items." << endl;
}

/****************
 removeFromBackpack: This function removes an item from the backpack.
 ***************/
void Backpack::removeFromBackpack(string itemIn)
{
    for (int i = 0; i < 3; i++)
    {
        if (backpack[i] == itemIn)
        {
            cout << itemIn << " was removed from your backpack." << endl;
            backpack[i] = "No Item"; //clear slot in backpack
        }
    }
}

/****************
 searchBackpack: This function searches the backpack for an item and returns a bool value corresponding to if the item was found.
 ***************/
bool Backpack::searchBackpack(string itemIn)
{
    for (int i = 0; i < 3; i++)
    {
        if (backpack[i] == itemIn) //if item is found
        {
            return true;
        }
    }
    
    return false; //return false if item not found
}