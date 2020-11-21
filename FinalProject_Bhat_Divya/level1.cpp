#include "level1.h"

// PerformStepAction is a pure virtual function in the
// Space base class
bool Level1::performStepAction()
{
    return (performAction(true));
}

// PerformPostStepAction is a pure virtual function in the
// Space base class
void Level1::performPostStepAction()
{
    postAction();
}

void Level1::intro()
{
    clearScreen();
    string intro_str="";
    intro_str = "Welcome to the game MAFIA\n";
    intro_str += "\nTheme: To catch & kill the most wanted criminal in the world.\n";
    intro_str += "\nOur Hero is a Police Officer, who goes through 6 levels of extreme difficulties to catch the criminal.\n";
    intro_str += "Each level is filled with unique difficulties for our Hero to endure.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    intro_str += "Mines representation: \"X\"\n";
    intro_str += "Ninja representation: \"N\"\n";
    intro_str += "Boss (Criminal) representation: \"C\"\n";
    intro_str += "\nContainer: Gun is the container for this game, which contains 3 bullets to begin with.\n";
    intro_str += "Hero can pick up more bullets from the space.\n";
    intro_str += "\nEach enemies are stronger than the other. For example number of bullets to kill an enemy is as follows:\n";
    intro_str += "Gaurd: 1 Bullet\n";
    intro_str += "Ninja: 2 Bullets\n";
    intro_str += "Criminal/Boss: 3 Bullets\n";
    intro_str += "\nOnce you have killed all the enemies in the level, a key will appear in a random place on the board.\n";
    intro_str += "Hero can only unlock the door after picking up the key.\n";
    intro_str += "\nMovement of the Hero can be controlled using 'w', 'a', 's', 'd' buttons on the keyboard.\n";
    intro_str += "If you have played First Person Shooter games, then this should be a walk in the park for you.\n";
    intro_str += "If not, no worries, there are clear instructions on each screen to guide you through each level.\n";
    intro_str += "\nHope you enjoy the GAME!\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");

    clearScreen();
    intro_str = "Level1:\n";
    intro_str += "\nOur Hero will encounter 3 Guards in this level.\n";
    intro_str += "Each Guard can be killed using 1 bullet.\n";
    intro_str += "However, if you run out of bullets and try to kill the Guard, then you will get killed.\n";
    intro_str += "Try to complete the level within the number of steps shown in the screen.\n";
    intro_str += "\nFew of the objects that you will interact are represented as follows:\n";
    intro_str += "Hero representation: \"@\"\n";
    intro_str += "Guard representation: \"G\"\n";
    intro_str += "Bullet (set of 3) representation: \"B\"\n";
    cout << intro_str << endl;

    cout << "\nPress any key & hit enter to continue..." << endl;
    system("read");
}