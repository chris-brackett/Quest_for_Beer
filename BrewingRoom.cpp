/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: BrewingRoom class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "BrewingRoom.hpp"
using std::cout;
using std::endl;
using std::string;

BrewingRoom::BrewingRoom(Player* playerIn): Space("Brewing Room", playerIn, 6) //default constructor
{
    beerTransferred = false;
}

/****************
 special: This function performs the special "move" of the space (brew the beer).
 ***************/
void BrewingRoom::special()
{
    if (actionComplete == false) //if beer has not been brewed yet
    {
        bool hasBarley = false;
        bool hasHops = false;
        bool hasYeast = false;
        
        for (int i = 0; i < 3; i++) //check for all 3 items
        {
            if (player->searchBackpack("Barley"))
                hasBarley = true;
            if (player->searchBackpack("Hops"))
                hasHops = true;
            if (player->searchBackpack("Yeast"))
                hasYeast = true;
        }
        
        if (hasBarley && hasHops && hasYeast) //if player has all three ingredients
        {
            cout << "You empty your backpack of barley, hops, and yeast to brew some beer! It ferments instantly! You now have some beer in your backpack! You need to get it ready to serve - maybe there is a keg around here somewhere to put it in." << endl;
            cout << endl; //add a blank line
            
            player->removeFromBackpack("Barley"); //remove items from player's backpack
            player->removeFromBackpack("Hops");
            player->removeFromBackpack("Yeast");
            
            player->addToBackpack("Beer"); //add Beer to backpack
            actionComplete = true; //set brewing action to complete/true
        }
        else
            cout << "You don't have all of the ingredients to brew a beer! Come back with some barley, hops, and yeast!" << endl;
    }
    else //if beer has already been brewed
    {
        if (player->searchBackpack("Keg of Beer")) //for if player selects special option again after they have the keg of beer
            cout << "You've already got a keg full of beer. No need to transfer any more. Time to serve the beer!" << endl;
        
        bool hasKeg = false;
        bool hasBeer = false;
    
        if (player->searchBackpack("Keg"))
            hasKeg = true;
        if (player->searchBackpack("Beer"))
            hasBeer = true;
        
        if (hasKeg && hasBeer) //if player has keg and beer
        {
            cout << "You transfer the beer to a keg. Time to hook this up and serve some beer!" << endl;
            
            player->removeFromBackpack("Keg"); //remove and add items
            player->removeFromBackpack("Beer");
            player->addToBackpack("Keg of Beer");
            
            beerTransferred = true;
        }
        else if (beerTransferred == false) //if player does not have keg and beer (but beer has already been brewed and transferred)
            cout << "You've brewed the beer, but now you need a keg to put it in! I think we have some in the supply room..." << endl;
    }
    
}

/****************
 displayMenu: This function displays the menu for the room and gives options to the player.
 ***************/
void BrewingRoom::displayMenu()
{
    cout << "Current Location: Brewing Room" << endl;
    
    if (actionComplete == false) //if beer has not been brewed
        cout << "1.) Brew beer" << endl;
    else //if beer has been brewed
        cout << "1.) Transfer beer to keg" << endl;
    
    cout << "2.) Go outside through the back door" << endl;
    cout << "3.) Go into the tasting room" << endl;
    cout << "4.) Go into the supply room" << endl;
    cout << "5.) Go to the window" << endl;
    cout << "6.) View contents of backpack" << endl;
}