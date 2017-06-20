/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Player Class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Player.hpp"

using std::cout;
using std::endl;
using std::string;

Player::Player() //default constructor
{
    counter = 0; //initialize counter
    backpack = new Backpack; //create backpack
}

Player::~Player() //destructor
{
    delete backpack;
}

/****************
 getCounter: This function returns the counter for the player (number of moves made).
 ***************/
int Player::getCounter()
{
    return counter;
}

/****************
 addCounter: This function adds one to the counter for the player (number of moves made).
 ***************/
void Player::addCounter()
{
    counter = counter + 1; //increment counter
}

/****************
 displayBackpack: This function displays the contents of the backpack by accessing the backpack's function.
 ***************/
void Player::displayBackpack()
{
    backpack->displayBackpack();
}

/****************
 addToBackpack: This function adds an item to the backpack by accessing the backpack's function.
 ***************/
void Player::addToBackpack(string itemIn)
{
    backpack->addToBackpack(itemIn);
}

/****************
 removeFromBackpack: This function removes an item from the backpack by accessing the backpack's function.
 ***************/
void Player::removeFromBackpack(string itemIn)
{
    backpack->removeFromBackpack(itemIn);
}

/****************
 searchBackpack: This function searches the backpack by accessing the backpack's function.
 ***************/
bool Player::searchBackpack(string itemIn)
{
    return backpack->searchBackpack(itemIn);
}

/****************
 setCurrentSpace: This function sets the current space of the player.
 ***************
void Player::setCurrentSpace(Space *spaceIn)
{
    currentSpace = spaceIn;
}

/****************
 getCurrentSpace: This function returns the current space of the player.
 ***************
Space* Player::getCurrentSpace()
{
    return currentSpace;
}

/****************
 getBackpack: This function returns the current backpack of the player.
 ***************/
Backpack* Player::getBackpack()
{
    return backpack;
}