#include "level5.h"

// prepareBoard is a virtual function in Space base class
// Along with preparing the base class prepare board, it
// also adds Mines on the board
void Level5::prepareBoard()
{
    Space::prepareBoard();
    placeNinjaOnBoard();
}

void Level5::placeNinjaOnBoard()
{
    placeOnBoard(ninja_count, ninja);
}

bool Level5::isNinjaLocation(int i, int j)
{
    return (isObjectLocation(i, j, ninja));
}

bool Level5::killNinja()
{
    // Ninja will die after hitting him twice. So the user needs to
    // have two bullets to kill a Ninja
    if (player->getBulletCount() <= 1) {
        printEndGameBoard(std::string("You got killed by a Ninja! You need to have atleast 2 bullets to kill a Ninja"));
        setGameEnd();
        return false;
    }

    setPreviousStep(std::string("Killed a Ninja"));
    player->setBulletCount(player->getBulletCount() - 2);
    setNinjaCount(getNinjaCount() - 1);

    return true;
}

// PerformStepAction is a pure virtual function in the
// Space base class
bool Level5::performStepAction()
{
    bool ret = true;
    if (isNinjaLocation(player->getRow(), player->getCol())) {
        ret = killNinja();
        if (!ret) {
            return ret;
        }
    }

    if (ninja_count == 0 && getGuardCount() == 0 && !unlock_key) {
        appendPreviousStep(std::string("Unlocked key for this space"));
        placeKeyOnBoard();
        unlock_key = true;
    }

    return (performAction(unlock_key));
}

// PerformStepAction is a pure virtual function in the
// Space base class
void Level5::performPostStepAction()
{
    postAction();
}

void Level5::intro()
{
    clearScreen();
    string intro_str="";
    intro_str = "Level5:\n";
    intro_str += "\nOur Hero will encounter 7 Guards & 2 Ninjas in this level.\n";
    intro_str += "Each Guard can be killed using 1 bullet.\n";
    intro_str += "However, if you run out of bullets and try to kill the Guard, then you will get killed.\n";
    intro_str += "Each Ninja can be killed using 2 bullets.\n";
    intro_str += "However, if you run out of bullets and try to kill the Ninja, then you will get killed.\n";
    intro_str += "\nOnce you have killed all the enemies in the level, a key will appear in a random place on the board.\n";
    intro_str += "Hero can only unlock the door after picking up the key.\n";
    intro_str += "\nTry to complete the level using the steps shown in the screen.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    intro_str += "Ninja representation: \"N\"\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");
    
}

void Level5::printBoard()
{
    string level_info = "";
    level_info = "Ninja count: " + to_string(ninja_count) + "\n"; 
    Space::printBoard(level_info);
}

