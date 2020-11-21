#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level3 of the game
// Number of Bullet refill location: 1
// Number of guards: 6
// Number if Mines: 3 
// Steps limit for game completion: 150
class Level3: public Space {
    int mine_count = 3;
    char mine = 'X' ;

    public:
    Level3(Player *p):Space(p, std::string("level3"), 1, 6, 150){}

    //getters
    int getMineCount() { return mine_count; }

    //setters
    void setMineCount(int value) { mine_count = value; }

    // Helper function to get the board ready
    void prepareBoard();
    void placeMineOnBoard();
    void printBoard() { Space::printBoard(string("")); }

    // Identifier
    bool isMineLocation(int i, int j);

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();
};
