#pragma once

#include "space.h"
#include "player.h"

#include <iostream>
#include <string>

using namespace std;

// Level6 of the game. Final Level.
// Number of Bullet refill location: 2
// Number of guards: 7
// Number of Boss: 1
// Steps limit for game completion: 150
class Level6: public Space {
    int boss_count = 1;
    char boss = 'C';
    bool unlock_key = false;
    
    public:
    Level6(Player *p):Space(p, std::string("level6"), 2, 7, 150){}

    //getters
    int getBossCount() { return boss_count; }

    // Helper function to get the board ready
    void prepareBoard();
    void placeBossOnBoard();
    void printBoard();

    // Identifier
    bool isBossLocation(int i, int j);

    //setters
    void setBossCount(int value) { boss_count = value; }

    // Pure virtual functions in base class;
    bool performStepAction();
    void performPostStepAction();
    void intro();

    // action
    bool killBoss();
};