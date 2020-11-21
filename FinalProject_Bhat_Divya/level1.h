#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level1 of the game
// Number of Bullet refill location: 1
// Number of guards: 3
// Steps limit for game completion: 150
class Level1: public Space {
    public:
    Level1(Player *p):Space(p, std::string("level1"), 1, 3, 150){}

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();

    // Virtual functions in base class
    void printBoard() { Space::printBoard(string("")); }
};
