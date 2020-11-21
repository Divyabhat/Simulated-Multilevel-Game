#include "level4.h"

// prepareBoard is a virtual function in Space base class
// Along with preparing the base class prepare board, it
// also adds Mines on the board
void Level4::prepareBoard()
{
    Space::prepareBoard();
    placeMineOnBoard();
}

void Level4::placeMineOnBoard()
{
    placeOnBoard(mine_count, mine);
}

bool Level4::isMineLocation(int i, int j)
{
    return (isObjectLocation(i, j, mine));
}

// PerformStepAction is a pure virtual function in the
// Space base class
// Along with base class function, it verifies whether th
// user has stepped on a Mine. If that is the case he will Die
bool Level4::performStepAction()
{
    if (isMineLocation(player->getRow(), player->getCol())) {
        printEndGameBoard(string("You have stepped on a mine!"));
        setGameEnd();
        return false;
    }
    return (performAction(true));
}

// PerformStepAction is a pure virtual function in the
// Space base class
void Level4::performPostStepAction()
{
    postAction();
}

void Level4::intro()
{
    clearScreen();
    string intro_str="";
    intro_str = "Level4:\n";
    intro_str += "\nOur Hero will encounter 7 Guards in this level.\n";
    intro_str += "Each Guard can be killed using 1 bullet.\n";
    intro_str += "However, if you run out of bullets and try to kill the Guard, then you will get killed.\n";
    intro_str += "\nThere are Mines in between. If you step on it, then you will DIE! Be extremely careful.\n";
    intro_str += "\nOnce you have killed all the enemies in the level, a key will appear in a random place on the board.\n";
    intro_str += "Hero can only unlock the door after picking up the key.\n";
    intro_str += "\nTry to complete the level using the steps shown in the screen.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    intro_str += "Mines representation: \"X\"\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");
}


