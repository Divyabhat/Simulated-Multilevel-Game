#include "space.h"

#include <istream>

using namespace std;

// Default constructor
Space::Space()
{
    // Object trackers
    bullet_count = 0;
    guard_count = 0;
    keyfound = false;
    unlocked_key = false;

    // Board will be square, so board_row and board_col
    // will be initialized to board_size
    board_size = 0;

    // Multi-dimentional vector to represent the board
    vector<vector<char>> temp(board_size, vector<char>(board_size, blank));
    board = temp;


    // Variable to hold game completion status
    game_end = false;
    level_complete = false;

    // Player is initialized by game class. This Space class holds
    // the reference to that player
    player = nullptr;

    left = nullptr;
    right = nullptr;
    top = nullptr;
    bottom = nullptr;
}

// Constructor called from derived class
Space::Space(Player *p, // Player pointer
                string level, // Game level
                int bullet_count, // Number of guns to be placed on the board
                int guard_count, // Number of guards to be placed on the board
                int step_count) //Timer for the board
{
    // Object trackers
    this->bullet_count = bullet_count;
    this->guard_count = guard_count;
    this->keyfound = false;
    this->unlocked_key = false;

    // Board will be square, so board_row and board_col
    // will be initialized to board_size
    board_size = 15;

    // Multi-dimentional vector to represent the board
    vector<vector<char>> temp(board_size, vector<char>(board_size, blank));
    board = temp;

    // Player is initialized by game class. This Space class holds
    // the reference to that player
    this->player = p;

    // Variable to hold game completion status
    game_end = false;
    level_complete = false;
    this->level = level;
    this->step_count = step_count;

    // Space pointers 
    left = nullptr;
    right = nullptr;
    top = nullptr;
    bottom = nullptr;
}

// Prints the board
void Space::printBoard(std::string level_info)
{
    // Clears the screen
    clearScreen();

    // Display level banner
    cout << "\n######    " << level << "    #####" << endl;

    // Level objects representation
    cout << "player location(@), Gaurd(G), Bullets(B), Mines(X), Ninja(N), Boss(B), Exit Door(#)\n" << endl;

    // Object status
    cout << "Bullets left: " << player->getBulletCount() << endl;
    cout << "Guards left: " << guard_count << endl;
    cout << "Step count: " << step_count << endl;
    cout << level_info << endl;
    if (keyfound) {
        cout << "Key: You have picked up a key. You can now open the door." << endl;
    } else if (unlocked_key) {
        cout << "Key: You have unlocked a key! Pick that up to open the door." << endl;
    } else if (!unlocked_key) {
        cout << "Key: Kill all the enemies to unlock a key! Door currently locked." << endl;
    }

    // Status from previous round
    cout << "\nPrevious round:" << endl;
    cout << getPreviousStep() << endl;

    // reset previous step message
    resetPreviousStep();

    // Upper border
    cout << " ";
    for (int i = 0; i < (3 * board_size + 2); i++) {
        cout << "-";
    }
    cout << " " << endl;

    // Print board elements
    for (int i = 0; i < board_size; i++) {
        cout << "| ";
        for (int j = 0; j < board_size; j++) {
            cout << board[i][j] << "  ";
        }
        cout << " |";
        cout << endl;
    }

    // Lower border
    cout << " ";
    for (int i = 0; i < (3 * board_size + 2); i++) {
        cout << "-";
    }
    cout << " " << endl;
}

void Space::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

// Prints the game end banner with the reason
// Input:
//  @arg1: Game end reason string
void Space::printEndGameBoard(string reason)
{
    clearScreen();
    cout << "######### Game End! #########" << endl;
    cout << "######### " << reason << " #########" << endl;
}

// Prints the game won banner
// Input:
//  @arg1: Game end reason string
void Space::printGameWon()
{
    clearScreen();
    cout << "######### You win! #########" << endl;
    cout << "You have successfully defeated the Criminal. World is now a better place just because of you!" << endl;
}

// This is wrapper function to place object on board
// Input:
//  @arg1: Number of objects to place
//  @arg2: Object to be placed
void Space::placeOnBoard(int object_count, char object)
{
    int row;
    int col;
    int placecount = 0;
    while (placecount < object_count) {
        row = rand() % board_size;
        col = rand() % board_size;

        // Check if the random location is already filled with
        // object
        if (isOccupied(row, col)) {
            continue;
        }
        board[row][col] = object;
        placecount++;
    }
}

void Space::placePlayerOnBoard()
{
    board[0][0] = playerchar;
}

// Place Bullets on some random location
void Space::placeBulletOnBoard()
{
    placeOnBoard(bullet_count, bullet);
}

void Space::placeGuardOnBoard()
{
    placeOnBoard(guard_count, guard);
}

void Space::placeExitOnBoard()
{
    placeOnBoard(1, door);
}

void Space::placeKeyOnBoard()
{
    placeOnBoard(1, key);
    unlocked_key = true;
}

void Space::clearLocation(int row, int col)
{
    setBoardValue(row, col, blank);
}

// This function is called for every level
// to prepare the board
void Space::prepareBoard()
{
    keyfound = false;
    placePlayerOnBoard();
    placeBulletOnBoard();
    placeGuardOnBoard();
    placeExitOnBoard();
}

// This is a wrapper function to check if the
// provided object in the argument is present on the
// board
// Input:
//  @arg1: Object row location
//  @arg2: Object column location
//  @arg3: Object representation
bool Space::isObjectLocation(int row, int col, char object) {
    if (object == board[row][col]) {
        return true;
    }
    return false;
}

bool Space::isBulletLocation(int row, int col)
{
    return isObjectLocation(row, col, bullet);
}

bool Space::isGuardLocation(int row, int col)
{
    return isObjectLocation(row, col, guard);
}

bool Space::isKeyLocation(int row, int col)
{
    return isObjectLocation(row, col, key);
}

bool Space::isExitLocation(int row, int col)
{
    return isObjectLocation(row, col, door);
}

// Function to check if the location is occupied
// by any object
bool Space::isOccupied(int row, int col)
{
    if (isBulletLocation(row, col) ||
        isGuardLocation(row, col) ||
        isKeyLocation(row, col) ||
        isExitLocation(row, col) ||
        (row == 0 && col == 0)) {
        return true;
    }
    return false;
}

// Function to get user input about the direction
// in which he wants to move
string Space::getDirection()
{
    char c;
    string error="";

    cout << "Move the player: " << endl;
    cout << "Up: 'w'" << endl;
    cout << "Left: 'a'" << endl;
    cout << "Right: 'd'" << endl;
    cout << "Down: 's'" << endl;
    cout << "Enter direction: ";
    cin >> c;
    cout << "Input: " << c << endl;
    switch (c) {
    case 'w':
        player->movePlayerUp(board_size);
        break;
    case 'a':
        player->movePlayerLeft(board_size);
        break;
    case 'd':
        player->movePlayerRight(board_size);
        break;
    case 's':
        player->movePlayerDown(board_size);
        break;
    default:
        error = "Invalid input!";
        return error;
    }

    // Flush the contents in cin to prepare for next input
    cin.clear();
    fflush(stdin);

    return error;
}

// User to pick up bullets, and increase the bullet count
// by three
void Space::takeBullets()
{
    player->setBulletCount(player->getBulletCount() + 3);
    setPreviousStep(std::string("Picked up 3 bullets"));
}

// Function to fight with guard
// Input:
//  @arg1: unlock key is passed by derived class to say that
//          a key can be unlocked.
//         Example: For level4 and above, only after killing Ninja
//          you can get a key, this is passed by derived ninja class
//  Return:
//      True when number of bullets are left to kill a guard
//      False when there are no enough bullets to kill a guard, so the guard
//          kills you the battle
bool Space::killGuards(bool unlock_key)
{
    // If there are no enough bullets left, then the user gets killed
    // by the guard
    if (player->getBulletCount() <= 0) {
        printEndGameBoard(std::string("You got killed by a guard! You need to have atleast 1 bullet to kill a guard."));
        setGameEnd();
        return false;
    }

    // Kills the gaurd, and reduce gaurd and bullet count
    setPreviousStep(std::string("Killed a guard"));
    player->setBulletCount(player->getBulletCount() - 1);
    setGuardCount(getGuardCount() - 1);

    // Unlock the key if you have killed the last surviving guard
    if (unlock_key && guard_count == 0) {
        appendPreviousStep(std::string("Unlocked key for this space"));
        placeKeyOnBoard();
    }
    return true;
}

// Function to open the door
// Return:
//  True when key is already picked up
//  False when user doesn't have a key to unlock the door
bool Space::openTheDoor()
{
    if (!getKeyFound()) {
        setPreviousStep(std::string("Key not found! Kill all the guards, (ninjas, boss) to get a key.\nIf you have killed all then you need to pick up a Key from the space to unlock the Door/Exit."));
        return false;
    }

    // Mark the level as complete when a door is opened
    setLevelComplete();
    return true;
}

// Function to pickup a key
void Space::takeKey()
{
    setPreviousStep(std::string("You have picked up a key!"));
    keyfound = true;
}

// Function to perform an action when user moves
// to new location
bool Space::performAction(bool unlock_key)
{
    int player_row = player->getRow();
    int player_col = player->getCol();
    bool ret = true;

    if (isBulletLocation(player_row, player_col)) {
        takeBullets();
        return true;
    } else if (isGuardLocation(player_row, player_col)) {
        ret = killGuards(unlock_key);
        return ret;
    } else if (isExitLocation(player_row, player_col)) {
        ret = openTheDoor();
        return ret;
    } else if (isKeyLocation(player_row, player_col)) {
        takeKey();
        return true;
    }
    return ret;
}

void Space::postAction()
{
    setBoardValue(player->getOldRow(), player->getOldCol(), blank);
    setBoardValue(player->getRow(), player->getCol(), playerchar);
    player->setOldRow(player->getRow());
    player->setOldCol(player->getCol());
}

bool Space::postValidate()
{
    string end_str = "";
    if (getStepCount() <= 0) {
        printEndGameBoard(string("You have exceeded number of steps for this game!"));
        setGameEnd();
    }

    if (gameEnd()) {
        return false;
    }
    return true;
}