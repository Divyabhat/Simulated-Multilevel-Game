#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level2 of the game
// Number of Bullet refill location: 1
// Number of guards: 4
// Steps limit for game completion: 150
class Level2: public Space {
    public:
    Level2(Player *p):Space(p, std::string("level2"), 1, 4, 150){}

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();

    // Virtual functions in base class
    void printBoard() { Space::printBoard(string("")); }
};