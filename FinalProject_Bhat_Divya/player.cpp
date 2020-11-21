#include "player.h"

using namespace std;

// Player constructor
// Initialize Previous location, Current location
// & bullet count
Player::Player()
{
    row = 0;
    col = 0;
    bullet_count = 3;

    old_row = 0;
    old_col = 0;
}

// Player constructor
// Initialize Previous location, Current location
// & bullet count
Player::Player(int bullet_count)
{
    this->row = 0;
    this->col = 0;
    this->bullet_count = bullet_count;
}

// Move player one location up
void Player::movePlayerUp(int board_size)
{
    if (0 == row) {
        return;
    }
    row = row - 1;
}

// Move player one location left
void Player::movePlayerLeft(int board_size)
{
    if (0 == col) {
        return;
    }
    col = col - 1;
}

// Move player one location right
void Player::movePlayerRight(int board_size)
{
    if ((board_size - 1) == col) {
        return;
    }
    col = col + 1;
}

// Move player one location down
void Player::movePlayerDown(int board_size)
{
    if ((board_size - 1) == row) {
        return;
    }
    row = row + 1;
}

// Reset players location and add 3 bullets
// when moving to next level
void Player::reset()
{
    old_row = 0;
    old_col = 0;

    row = 0;
    col = 0;

    bullet_count += 3;
}