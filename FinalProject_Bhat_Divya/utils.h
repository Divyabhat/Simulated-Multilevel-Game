#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

// validate functions
int isValidInteger(int value);
int isValidFloat(int value);
int isValidYesNo(char value);
int isValidLimit(int value, int min, int max);

// Validate and re-ask user input
void inputMessage(const string& msg, int *input);
void inputMessage(const string& msg, float *input);
void inputMessage(const string& msg, char *input);
void inputMessage(const string& msg, string &input);
void inputMessage(const string& msg, int *input, int min, int max);
void validateInteger(int *input);

// Random number generator
int randomNumberGenerate(void);

// Ask user if he wants to continue
int wantToContinue(std::string input_str);

// Helper functions
void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out);

