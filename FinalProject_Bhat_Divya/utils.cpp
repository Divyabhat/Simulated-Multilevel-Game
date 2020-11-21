#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Validate if the value is correct
//
// Input:
//  @arg1: Integer value
int isValidInteger(int value)
{
    if (value <= 0) {
        return 1;
    }
    return 0;
}

// Validate if the value is correct
//
// Input:
//  @arg1: Integer value
int isValidFloat(float value)
{
    if (value <= 0) {
        return 1;
    }
    return 0;
}

// Validate if the value is correct
//
// Input:
//  @arg1: Character value
int isValidYesNo(char value)
{
    if ('y' == value || 'Y' == value) {
        return 0;
    }

    if ('n' == value || 'N' == value) {
        return 0;
    }
    return 1;
}

int isValidLimit(int value, int min, int max) {
    if (value >= min && value <= max) {
        return 0;
    }
    return 1;
}

void inputMessage(const string& msg, int *input, int min, int max) {
    cout << msg;
    cin >> *input;
    while (cin.fail() || isValidInteger(*input) || isValidLimit(*input, min, max)) {
        cout << "\nInvalid entry: Please enter value within the range(" << min << ", " << max << ")" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMessage(msg, input, min, max);
    }
}

// Validate user input and throws error until proper input is entered
//
// Input:
//  @arg1: Message to be displayed to user
//  @arg2: Input variable
void inputMessage(const string& msg, float *input)
{
    cout << msg;
    cin >> *input;
    while (cin.fail() || isValidFloat(*input)) {
        cout << "\nInvalid entry: Please enter positive float value" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMessage(msg, input);
    }
}

// Validate user input and throws error until proper input is entered
//
// Input:
//  @arg1: Message to be displayed to user
//  @arg2: Input variable
void inputMessage(const string& msg, int *input)
{
    cout << msg;
    cin >> *input;
    while (cin.fail() || isValidInteger(*input)) {
        cout << "\nInvalid entry: Please enter positive integer value" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMessage(msg, input);
    }
}

// Validate user input and throws error until proper input is entered
//
// Input:
//  @arg1: Input variable
void validateInteger(int *input)
{
    cin >> *input;
    while (cin.fail() || isValidInteger(*input)) {
        cout << "\nInvalid entry: Please enter positive integer value" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        validateInteger(input);
    }
}

// Validate user input and throws error until proper input is entered
//
// Input:
//  @arg1: Message to be displayed to user
//  @arg2: Input variable
void inputMessage(const string& msg, char *input)
{
    cout << msg;
    cin >> *input;
    while (cin.fail() || isValidYesNo(*input)) {
        cout << "\nInvalid entry: Please enter valid input" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMessage(msg, input);
    }
}

// Validate user input and throws error until proper input is entered
//
// Input:
//  @arg1: Message to be displayed to user
//  @arg2: Input variable
void inputMessage(const string& msg, std::string &input)
{
    cout << msg;
    cin >> input;
    while (cin.fail()) {
        cout << "\nInvalid entry: Please enter valid string input" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputMessage(msg, input);
    }
}

// Helper function to check if the user wants to continue
int wantToContinue(std::string input_str) {
    bool valid=true;
    std::string inputStr;
    char input;

    inputStr = input_str + "?(y/n): ";
    inputMessage(inputStr, &input);

    if ('y' == input || 'Y' == input) {
        return 1;
    }
    return 0;
}

// Generates a random number
int randomNumberGenerate(void) {
    return rand();
}

void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &outvec)
{
	// construct a stream from the string
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		outvec.push_back(s);
	}
}
