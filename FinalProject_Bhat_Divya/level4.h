#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level4 of the game
// Number of Bullet refill location: 2
// Number of guards: 7
// Number if Mines: 3
// Steps limit for game completion: 150
class Level4: public Space {
    int mine_count = 3;
    char mine = 'X';

    public:
    Level4(Player *p):Space(p, std::string("level4"), 2, 7, 150){}

    //getters
    int getMineCount() { return mine_count; }

    // Helper function to get the board ready
    void prepareBoard();
    void placeMineOnBoard();
    void printBoard() { Space::printBoard(string("")); }

    // Identifier
    bool isMineLocation(int i, int j);

    //setters
    void setMineCount(int value) { mine_count = value; }

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();
};