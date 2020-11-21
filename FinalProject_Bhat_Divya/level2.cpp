#include "level2.h"

// PerformStepAction is a pure virtual function in the
// Space base class
bool Level2::performStepAction()
{
    return (performAction(true));
}

// PerformStepAction is a pure virtual function in the
// Space base class
void Level2::performPostStepAction()
{
    postAction();
}

void Level2::intro()
{
    clearScreen();
    string intro_str="";
    intro_str = "Level2:\n";
    intro_str += "\nOur Hero will encounter 4 Guards in this level.\n";
    intro_str += "Each Guard can be killed using 1 bullet.\n";
    intro_str += "However, if you run out of bullets and try to kill the Guard, then you will get killed.\n";
    intro_str += "\nOnce you have killed all the enemies in the level, a key will appear in a random place on the board.\n";
    intro_str += "Hero can only unlock the door after picking up the key.\n";
    intro_str += "\nTry to complete the level using the steps shown in the screen.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");
}