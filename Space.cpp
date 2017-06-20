/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: Space Base Class for Final Project
 ***************/

#include <iostream>
#include <stdlib.h>
#include "Space.hpp"

Space::Space(string nameIn, Player* playerIn, int menuOptionsIn) //default constructor
{
    for (int i = 0; i < 4; i++)
        spacePtrs[i] = 0; //initialize all pointers to null
    
    name = nameIn; //set name
    actionComplete = false; //initialize actionComplete to false
    player = playerIn; //set player pointer
    menuOptions = menuOptionsIn; //set number of menu options
}

/****************
 getSpaceName: This function returns the name of a space as a string.
 ***************/
string Space::getSpaceName()
{
    return name;
}

/****************
 getActionComplete: This function returns the status of actionComplete.
 ***************/
bool Space::getActionComplete()
{
    return actionComplete;
}

/****************
 getMenuOptions: This function returns the number of menu options for the space.
 ***************/
int Space::getMenuOptions()
{
    return menuOptions;
}

/****************
 setMenuOptions: This function sets the number of menu options for the space.
 ***************/
void Space::setMenuOptions(int menuOptionsIn)
{
    menuOptions = menuOptionsIn;
}

/****************
 getPointer: This function returns the pointer from spacePtrs corresponding to the interger passed to the function.
 ***************/
Space* Space::getPointer(int ptrNumber)
{
    return spacePtrs[ptrNumber-1];
}

/****************
 setPointers: This function sets the pointers for a given space.
 ***************/
void Space::setPointers(Space *ptr1, Space *ptr2, Space *ptr3, Space *ptr4)
{
    spacePtrs[0] = ptr1;
    spacePtrs[1] = ptr2;
    spacePtrs[2] = ptr3;
    spacePtrs[3] = ptr4;
}

void Space::setPointers(Space *ptr1, Space *ptr2, Space *ptr3)
{
    spacePtrs[0] = ptr1;
    spacePtrs[1] = ptr2;
    spacePtrs[2] = ptr3;
    spacePtrs[3] = 0;
}

void Space::setPointers(Space *ptr1, Space *ptr2)
{
    spacePtrs[0] = ptr1;
    spacePtrs[1] = ptr2;
    spacePtrs[2] = 0;
    spacePtrs[3] = 0;
}

void Space::setPointers(Space *ptr1)
{
    spacePtrs[0] = ptr1;
    spacePtrs[1] = 0;
    spacePtrs[2] = 0;
    spacePtrs[3] = 0;
}