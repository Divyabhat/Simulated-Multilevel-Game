#include "game.h"
#include "player.h"

using namespace std;


// Initialize the player and levels in the game
// The game is organized is such a way that, each level
// is inherited from "Space" abstract base class
//
//   nullptr      nullptr      nullptr     nullptr       nullptr      nullptr
//     ^            ^            ^            ^             ^            ^
//     |            |            |            |             |            |
//  --------     --------     --------     --------     --------     --------
// | Level1 |-> | Level2 | ->| Level3 |-> | Level4 |-> | Level5 |-> | Level6 |  
//  --------     --------     --------     --------     --------     --------
//     |            |            |            |             |            |
//   nullptr      nullptr      nullptr     nullptr       nullptr      nullptr
//
// Each space will have pointer to next space initialized, rest all the pointers are nullptr
// Each space would represent a level in this program.

void Game::initializeObjects()
{
    // Create the player
    player = new Player();

    // Create levels for the game
    level1 = new Level1(player);
    level2 = new Level2(player);
    level3 = new Level3(player);
    level4 = new Level4(player);
    level5 = new Level5(player);
    level6 = new Level6(player);

    // Set next levels;
    level1->setNextLevel(level2);
    level2->setNextLevel(level3);
    level3->setNextLevel(level4);
    level4->setNextLevel(level5);
    level5->setNextLevel(level6);

    // Begin with the first level
    level = level1;    
}

// Helper function to clear the screen
void Game::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

// Initialize the components needed for next level
bool Game::setNextLevel()
{
    // Print level complete
    clearScreen();
    cout << level->getLevel() << " complete!" << endl;

    // Move to next level. Since right space is the next
    // level, level is initialized to the level in the right
    level = level->nextLevel();

    // Check if this is the end of the game
    if (level == nullptr) {
        level->printGameWon();
        return false;
    }

    cout << "Next level begins in ";
    cout << flush;
    for (int i = 0; i < 3; i++) {
        cout << (3 - i) << " ";
        cout << flush;
        sleep(1);
    }

    level->intro();

    // Initialize the board for the next level
    level->prepareBoard();

    // Reset the players location and add 3 bullets
    // for the next round
    player->reset();

    return true;
}

// Game play sequence
// 1) Prepare the board
// 2) Print the board
// 3) Get user input for the players direction
// 4) Perform action after moving to new location
//    Example: Killing a guard, Picking up bullets, killing ninja, etc
// 5) Validate the current step
//    Example: Is game over, has player stepped on mine, are all levels complete
// 6) If level complete, then move to next level
// 7) Reduce step limit
void Game::playGame()
{
    bool ret = true;

    level->intro();
    level->prepareBoard();

    while(true) {
        level->printBoard();
        level->getDirection();

        ret = level->performStepAction();
        if (ret) {
            // Perform post completion step only if the step action
            // was successful
            level->performPostStepAction();
        }

        // Check if we need to end the game because of death of our
        // Hero
        if (!level->postValidate()) {
            if (wantToContinue(string("Do you want to try again by resuming?"))) {
                level->resetValue(player->getOldRow(), player->getOldCol());
                player->reset();
                level->resetStepCount();
                level->resetEndGame();
                continue;
            }
            return;
        }

        // Check if the game is completed
        ret = true;
        if (level->levelComplete()) {
            ret = setNextLevel();
        }

        if (!ret) {
            return;
        }

        // Decrement the step count
        level->setStepCount(level->getStepCount() - 1);
    }
}

// Destruct player and all levels
Game::~Game()
{
    delete player;
    delete level1;
    delete level2;
    delete level3;
    delete level4;
    delete level5;
    delete level6;
}

// This is the entry point for the game
void Game::start()
{
    initializeObjects();
    playGame();
}