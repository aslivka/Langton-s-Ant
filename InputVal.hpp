/******************************************************************
** Author: Artem Slivka
** Date: 06/24/17
** Description: InputVal.hpp is the header file for library
**				InputVal (Input validation).
******************************************************************/

#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//List of library functions
//Checking string input for valid format
bool isSignInt(const string input);
bool isUnsignInt(const string input);
bool isDouble(const string input);
bool isAChar(string& input);

//Getter functions for valid output
string getInput(string dataType);						//Used for getting input to be checked for validity
bool isValidValue(string dataType, string& input);	//Checks if the value is valid based on datatype, input string
int getSignInt();										//Returns valid signed integer value
int getUnsignInt();										//Returns valid unsigned integer value
double getDouble();										//Returns valid double value
char getAChar();


//Misc
bool arraySearch(const string input, string search);
string removeAllSpaces(string input);

#endif