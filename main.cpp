/***************
 Name: Chris Brackett
 Date: 5/29/16
 Description: CS162 Final Project: Quest for Beer
 ***************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "BrewingRoom.hpp"
#include "Window.hpp"
#include "Outside.hpp"
#include "BarleyField.hpp"
#include "HopsField.hpp"
#include "FenceTop.hpp"
#include "SupplyRoom.hpp"
#include "SupplyRoomDrawer.hpp"
#include "SupplyRoomCabinet.hpp"
#include "TastingRoom.hpp"
#include "Tunnel.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() //main function to run program
{
    Player* player = new Player; //create player

    Space* brewingRoom = new BrewingRoom(player); //create spaces for initial layout of game
    Space* window = new Window(player);
    Space* outside = new Outside(player);
    Space* barleyField = new BarleyField(player);
    Space* hopsField = new HopsField(player);
    Space* fenceTop = new FenceTop(player);
    Space* supplyRoom = new SupplyRoom(player);
    Space* supplyRoomDrawer = new SupplyRoomDrawer(player);
    Space* supplyRoomCabinet = new SupplyRoomCabinet(player);
    Space* tastingRoom = new TastingRoom(player);
    Space* tunnel = 0; //create pointer for tunnel
    
    brewingRoom->setPointers(outside, tastingRoom, supplyRoom, window); //set pointers for each space
    window->setPointers(brewingRoom);
    outside->setPointers(brewingRoom, tastingRoom, hopsField, barleyField);
    barleyField->setPointers(outside, hopsField, tastingRoom, fenceTop);
    hopsField->setPointers(outside, barleyField, tastingRoom, fenceTop);
    fenceTop->setPointers(barleyField, hopsField);
    supplyRoom->setPointers(brewingRoom, tastingRoom, supplyRoomCabinet, supplyRoomDrawer);
    supplyRoomDrawer->setPointers(supplyRoom);
    supplyRoomCabinet->setPointers(supplyRoom);
    tastingRoom->setPointers(supplyRoom, brewingRoom, hopsField, barleyField);
    
    Space* currentSpace = brewingRoom; //set initial location of player to brewingRoom
    
    bool gameOver = false; //set bool value for determining when game ends
    bool spacesChanged = false; //set bool value for determining if spaces have changed (tunnel added)
    
    cout << "Welcome to Quest for Beer! Your goal is to serve a beer. Don't let your ingredients or your beer go bad!" << endl; //explain basic premise of game to player
    cout << "Hint for grader: Take a look in the suppply room drawer." << endl;
    
    while (gameOver == false) // while the game isn't over
    {
        cout << endl; //add a blank line
        currentSpace->displayMenu(); //display the menu of the current space
        cout << endl; //add a blank line
        
        int menuChoice; //declare menuChoice as integer
        cin >> menuChoice; //get menuChoice from user
        int options = currentSpace->getMenuOptions(); //set options equal to number of menu options of the current space
        while (menuChoice < 1 || menuChoice > options || cin.fail()) //input validation
        {
            cout << "Invalid option selected. Please choose again." << endl;
            cin.clear(); //reset cin state
            cin.ignore(); //ignore previously entered input
            cin >> menuChoice; //get new input from user
        }
        
        if (menuChoice == 1) //if option 1 was selected (special function/action)
        {
            currentSpace->special(); //run the special function of the current location
            if (static_cast<TastingRoom*>(tastingRoom)->getBeerServed() == true) //if beer has been served (game won)
                gameOver = true; //the game is now over (player won)
        }
        else if (menuChoice < options) //if option to move to another space was selected
        {
            if (currentSpace->getPointer(menuChoice-1)) //if valid pointer
            {
                currentSpace = currentSpace->getPointer(menuChoice-1); //update currentSpace pointer
                player->addCounter(); //increment moves counter of player
            }
            else //if no valid pointer
                cout << "You can't go that way! It's not safe after the earthquake!" << endl;
        }
        else //if view backpack option was selected
            player->displayBackpack(); //display the backpack contents
        
        
        
        if (player->getCounter() > 40) //if the player has made too many moves
        {
            if (brewingRoom->getActionComplete() == false) //if beer has not been brewed yet
                cout << "Your ingredients have gone bad! You'll have to try again if you want to finish your quest!" << endl;
            else //if beer has been brewed already
                cout << "You took too long to serve your beer and it became oxidized! You'll have to try again if you want to finish your quest!" << endl;
            
            gameOver = true; //the game is now over (player lost)
        }
        
        
        
        if (spacesChanged == false) //if the tunnel has not been created yet
        {
            if (player->searchBackpack("Hops") && player->searchBackpack("Barley")) // if player has both hops and barley
            {
                cout << endl; //add a blank line
                cout << "The ground shakes beneath your feet! The ground comes out from under you and you feel yourself falling. You hit the ground. Everything is dark and the air is still." << endl;
                
                tunnel = new Tunnel(player); //create tunnel space
                tunnel->setPointers(supplyRoomCabinet); //set pointers for tunnel
                
                currentSpace = tunnel; //set current space to tunnel
                
                tastingRoom->setPointers(supplyRoom, brewingRoom); //update pointers and menuOptions for spaces connected to spaces being deleted
                tastingRoom->setMenuOptions(4);
                outside->setPointers(brewingRoom, tastingRoom);
                outside->setMenuOptions(4);
                
                delete barleyField; //delete spaces destroyed in earthquake
                delete hopsField;
                delete fenceTop;
                
                spacesChanged = true; //update spacesChanged bool
            }
        }
    }

    delete player; //free memory allocated to player and remaining spaces
    delete brewingRoom;
    delete outside;
    delete window;
    delete supplyRoom;
    delete supplyRoomDrawer;
    delete supplyRoomCabinet;
    delete tastingRoom;
    delete tunnel;
    
    return 0; //end of program
}