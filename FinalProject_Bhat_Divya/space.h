#pragma once

#include "utils.h"
#include "player.h"

#include <iostream>
#include <stdio.h>

using namespace std;

class Space {
    // Pointers to the neighbouing spaces
    //   nullptr      nullptr      nullptr     nullptr       nullptr      nullptr
    //     ^            ^            ^            ^             ^            ^
    //     |            |            |            |             |            |
    //  --------     --------     --------     --------     --------     --------
    // | Level1 |-> | Level2 | ->| Level3 |-> | Level4 |-> | Level5 |-> | Level6 |  
    //  --------     --------     --------     --------     --------     --------
    //     |            |            |            |             |            |
    //     ^            ^            ^            ^             ^            ^
    //   nullptr      nullptr      nullptr     nullptr       nullptr      nullptr
    // 
    // Each space will have pointer to next space initialized, rest all the pointers are nullptr
    // Each space would represent a level in this program.
    Space *left;
    Space *right;
    Space *top;
    Space *bottom;

    // Board will be square, so board_row and board_col
    // will be initialized to board_size
    int board_size;

    // Multi-dimentional vector to represent the board
    vector<vector<char>> board;

    // Object trackers
    int bullet_count;
    int guard_count;
    bool unlocked_key;
    bool keyfound;

    // Step count for each level. Initialized by the derived classes
    // This represents the Timer
    int step_count;

    // Variable to keep information about the level
    string level;

    // Misc variables to hold the state of each step
    string previous_step;

    // Variable to hold game completion status
    bool game_end;
    bool level_complete;

    public:
    // Player is initialized by game class. This Space class holds
    // the reference to that player
    Player *player;

    // Object representation in the Board
    char bullet = 'B';
    char guard = 'G';
    char key = 'K'; 
    char door = '#';
    char playerchar = '@';
    char blank = '.';

    // Constructors and destructors
    Space();
    Space(Player *p, string level, int bullet_count,
           int guard_count, int step_count);
    virtual ~Space() {}

    // getters
    int getBulletCount() { return bullet_count; }
    int getGuardCount() { return guard_count; }
    int getStepCount() { return step_count; }
    bool getKeyFound() { return keyfound; }
    bool gameEnd() { return game_end; }
    bool levelComplete() { return level_complete; }
    string getPreviousStep() { return previous_step; }
    string getLevel() { return level; }
    Space* nextLevel() { return right; }

    // setters
    void setBulletCount(int value) { bullet_count = value; }
    void setGuardCount(int value) { guard_count = value; }
    void setKeyFound(bool value) { keyfound = value; }
    void setBoardValue(int r, int c, char value) { board[r][c] = value; }
    void setPreviousStep(string value) { previous_step = value; }
    void setGameEnd() { game_end = true; }
    void setLevelComplete() { level_complete = true; }
    void setStepCount(int value) { step_count = value; }
    void setNextLevel(Space *s) { right = s; }

    // reset functions
    void resetPreviousStep() { previous_step = ""; }
    void resetStepCount() { step_count = 150; }
    void resetEndGame() { game_end = false; }
    void resetValue(int i, int j) { board[i][j] = blank; board[0][0] = '@';}
    void appendPreviousStep(string value) { previous_step += "\n" + value; }

    // Display helpers
    void printBoard(string level_info);
    void printEndGameBoard(std::string reason);
    void printGameWon();

    // Helper functions to get the board ready
    void placeOnBoard(int count, char object);
    void placePlayerOnBoard();
    void placeBulletOnBoard();
    void placeGuardOnBoard();
    void placeExitOnBoard();
    void placeKeyOnBoard();
    void clearLocation(int i, int j);
    void clearScreen();

    // Identifiers
    bool isBulletLocation(int i, int j);
    bool isGuardLocation(int i, int j);
    bool isKeyLocation(int i, int j);
    bool isExitLocation(int i, int j);
    bool isObjectLocation(int row, int col, char object);
    bool isOccupied(int i, int j);

    // Player actions
    string getDirection();
    bool performAction(bool key);
    void postAction();
    void takeBullets();
    bool killGuards(bool key);
    bool openTheDoor();
    void takeKey();

    // Virtual functions
    virtual void prepareBoard();

    // Pure virtual functions
    virtual bool performStepAction() = 0;
    virtual void performPostStepAction() = 0; 
    virtual void intro() = 0;
    virtual void printBoard() = 0;

    // validate functions
    bool postValidate();
};