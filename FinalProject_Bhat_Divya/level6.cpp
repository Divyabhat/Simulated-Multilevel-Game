#include "level6.h"

// prepareBoard is a virtual function in Space base class
// Along with preparing the base class prepare board, it
// also adds Mines on the board
void Level6::prepareBoard()
{
    Space::prepareBoard();
    placeBossOnBoard();
}

void Level6::placeBossOnBoard()
{
    placeOnBoard(boss_count, boss);
}

bool Level6::isBossLocation(int i, int j)
{
    return (isObjectLocation(i, j, boss));
}

bool Level6::killBoss()
{
    // Boss will die after hitting him twice. So the user needs to
    // have three bullets to kill a Boss
    if (player->getBulletCount() <= 2) {
        setPreviousStep(std::string("You got killed by a Boss! You need to have atleast 3 bullets to kill a Boss"));
        setGameEnd();
        return false;
    }

    setPreviousStep(std::string("Killed a Boss"));
    player->setBulletCount(player->getBulletCount() - 2);
    setBossCount(getBossCount() - 1);

    return true;
}

// PerformStepAction is a pure virtual function in the
// Space base class
bool Level6::performStepAction()
{
    bool ret = true;
    if (isBossLocation(player->getRow(), player->getCol())) {
        ret = killBoss();
        if (!ret) {
            return ret;
        }
    }

    if (boss_count == 0 && getGuardCount() == 0 && !unlock_key) {
        appendPreviousStep(std::string("Unlocked key for this space"));
        placeKeyOnBoard();
        unlock_key = true;
    }
    return (performAction(unlock_key));
}

// PerformStepAction is a pure virtual function in the
// Space base class
void Level6::performPostStepAction()
{
    postAction();
}

void Level6::intro()
{
    clearScreen();
    string intro_str="";
    intro_str = "FINAL LEVEL:\n";
    intro_str += "\nOur Hero will encounter 7 Guards & 1 Criminal in this level.\n";
    intro_str += "Each Guard can be killed using 1 bullet.\n";
    intro_str += "However, if you run out of bullets and try to kill the Guard, then you will get killed.\n";
    intro_str += "Criminal can be killed using 2 bullets.\n";
    intro_str += "However, if you run out of bullets and try to kill the Criminal, then you will get killed.\n";
    intro_str += "\nOnce you have killed all the enemies in the level, a key will appear in a random place on the board.\n";
    intro_str += "Hero can only unlock the door after picking up the key.\n";
    intro_str += "\nTry to complete the level using the steps shown in the screen.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    intro_str += "Boss (Criminal) representation: \"C\"\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");
}

void Level6::printBoard()
{
    string level_info = "";
    level_info = "Criminal count: " + to_string(boss_count) + "\n"; 
    Space::printBoard(level_info);
}


