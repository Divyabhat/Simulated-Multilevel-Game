#pragma once

#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"

#include <unistd.h>

class Game {
    Space *level;
    Player *player;
    Level1 *level1;
    Level2 *level2;
    Level3 *level3;
    Level4 *level4;
    Level5 *level5;
    Level6 *level6;

    public:

    // Constructor and desctructor
    Game(){}
    ~Game();

    // Initialize
    void initializeObjects();

    // Game play
    void start();
    void playGame();

    // Helper functions
    bool setNextLevel();
    void clearScreen();
};