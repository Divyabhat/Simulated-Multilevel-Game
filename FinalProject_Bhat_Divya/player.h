#pragma once

#include "utils.h"

#include <iostream>

class Player {
    // Bullet count. This will persist across the levels
    int bullet_count;

    // Players current location
    int row;
    int col;

    // Players old location
    int old_row;
    int old_col;

    // Provision to calculate points scored by the player
    // across all the rounds
    int points;

    public:
    // Constructor
    Player();
    Player(int bullet_count);

    // Destructor
    ~Player() {} 

    // getters
    int getBulletCount() { return bullet_count; }
    int getRow() { return row; }
    int getCol() { return col; }
    int getOldRow() { return old_row; }
    int getOldCol() { return old_col; }

    // setters
    void setBulletCount(int value) { bullet_count = value; }
    void setRow(int value) { row = value; }
    void setCol(int value) { col = value; }
    void setOldRow(int value) { old_row = value; }
    void setOldCol(int value) { old_col = value; }

    // Player modifiers
    void movePlayerUp(int);
    void movePlayerLeft(int);
    void movePlayerRight(int);
    void movePlayerDown(int);

    // reset
    void reset();
};