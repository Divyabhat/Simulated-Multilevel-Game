#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level5 of the game
// Number of Bullet refill location: 2
// Number of guards: 7
// Number of Ninja: 2
// Steps limit for game completion: 150
class Level5: public Space {
    int ninja_count = 2;
    char ninja = 'N';
    bool unlock_key = false;
    
    public:
    Level5(Player *p):Space(p, std::string("level5"), 2, 7, 150){}

    //getters
    int getNinjaCount() { return ninja_count; }

    // Helper function to get the board ready
    void prepareBoard();
    void placeNinjaOnBoard();
    void printBoard();

    // Identifier
    bool isNinjaLocation(int i, int j);

    //setters
    void setNinjaCount(int value) { ninja_count = value; }

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();

    // action
    bool killNinja();
};