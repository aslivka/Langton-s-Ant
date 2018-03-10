/******************************************************************
** Author: Artem Slivka
** Date : 06/24/17
** Description : InputVal.cpp is the function implementation file
**				 for library InputVal. This library allows the
**				 user to check input: if it's an integer, floating
**				 point number, string, etc.
******************************************************************/
#include "InputVal.hpp"

/*********************************************************************
** Description:		This function supervizes the number validation
**					process. Based on datatype, it will check if the
**					string has valid characters for that type.
**					If it does, it will return the value as a string.
**					If the input is not a valid value, it asks the user
**					to enter another, valid value.
*********************************************************************/
string getInput(string dataType)
{
	bool validVal = false;
	string typeDesc;		//type description
	string testInput;	    //keyboard input saved as string

							//Setting appropriate type descriptions
	if (dataType == "uint")
	{
		typeDesc = "unsigned integer";
	}

	else if (dataType == "int")
	{
		typeDesc = "signed integer";
	}

	else if (dataType == "dbl")
	{
		typeDesc = "double";
	}
	else if (dataType == "achar")
	{
		typeDesc = "alpha char";
	}

	//Storing input into a test string
	getline(cin, testInput);
	validVal = isValidValue(dataType, testInput);

	//Making the user re-enter a valid value if the first try 
	//was an invalid value.
	while (validVal == false)
	{
		cout << "Error! Invalid value." << endl;
		cout << "Enter new " << typeDesc << " value." << endl;
		getline(cin, testInput);
		validVal = isValidValue(dataType, testInput);
	}

	return testInput;
}

/*********************************************************************
** Description:		This function checks if the entered value is an
**					valid. It returns true if it is, false
**					if not. Parameter is the value datatype.
*********************************************************************/
bool isValidValue(string dataType, string& input)
{
	bool validVal = false;

	if (dataType == "uint")
	{
		validVal = isUnsignInt(input);
	}
	else if (dataType == "int")
	{
		validVal = isSignInt(input);
	}
	else if (dataType == "dbl")
	{
		validVal = isDouble(input);
	}

	else if (dataType == "achar")
	{
		validVal = isAChar(input);
	}
	return validVal;
}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					integer(signed). It returns true if it is, false
**					if not integer.
*********************************************************************/
bool isSignInt(const string input)
{
	//It's easier during implementation to assume the num is integer, then
	//check for cases where this condition is violated
	bool intValue = true;
	unsigned int strLen = input.length();

	//Checking the first digit:  has to be 0-9 or -
	//Negation of  0-9 or - = num is outside 0-9 and != -
	//2nd way: if ((input[0] < 48) || (input[0] > 57))
	if ((isdigit(input[0]) == false) && input[0] != '-')
	{
		intValue = false;
	}
	//Case: 0 good int
	//Case: 01 not int
	if (input[0] == '0' && strLen > 1)
	{
		intValue = false;
	}
	//Checking next digits: has to be 0-9 only
	for (unsigned int j = 1; j < strLen; j++)
	{
		//2nd way: if ((input[j] < 48) || (input[j] > 57))
		if (isdigit(input[j]) == false)
		{
			intValue = false;
		}
	}

	return intValue;
}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					integer(unsigned). It returns true if it is, false
**					if not integer.
*********************************************************************/
bool isUnsignInt(const string input)
{
	//It's easier during implementation to assume the num is integer, then
	//check for cases where this condition is violated
	bool intValue = true;
	unsigned int strLen = input.length();

	//Checking the first digit:  has to be 0-9
	//Negation of  0-9 = num is outside 0-9 

	if (isdigit(input[0]) == false)
	{
		intValue = false;
	}

	//Case: 0 good int
	//Case: 01 not int
	if (input[0] == '0' && strLen > 1)
	{
		intValue = false;
	}

	//Checking next digits: has to be 0-9 only
	for (unsigned int j = 1; j < strLen; j++)
	{
		if (isdigit(input[j]) == false)
		{
			intValue = false;
		}
	}

	return intValue;
}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					number with a decimal point(either float or double).
**					It returns true if it is, false if not.
*********************************************************************/
bool isDouble(const string input)
{
	bool dblValue = true;
	unsigned int strLen = input.length();
	int isDecPoint = 0;

	if (strLen <= 2)
	{
		dblValue = false;
	}
	else
	{
		//First digit
		if ((input[0] != '-') && (isdigit(input[0]) == false))
		{
			dblValue = false;
		}
		//Checking the rest of the string characters for digits or
		//1 decimal point
		for (unsigned int j = 1; j < strLen; j++)
		{
			if (input[j] == '.')
			{
				isDecPoint++;
			}
			else if (isdigit(input[j]) == false)
			{
				dblValue = false;
			}
		}
		//If the number has multiple decimal points and the other characters are digits
		//or if the number has no decimal point and the other characters are digits
		if ((isDecPoint > 1 && dblValue == true) || (isDecPoint == 0 && dblValue == true))
		{
			dblValue = false;
		}
	}
	return dblValue;
}

/*********************************************************************
** Description:		This function checks if the entered value is an
**					character. It returns true if it is, false if not.
*********************************************************************/
bool isAChar(string& input)
{
	//It's easier during implementation to assume the value is char, then
	//check for cases where this condition is violated
	bool charValue = true;

	//Removing whitespaces from string
	input = removeAllSpaces(input);
	unsigned int strLen = input.length();

	//cout << "String length: " << strLen << endl;
	if (strLen != 1 || isalpha(input[0]) == false)
	{
		charValue = false;
	}

	return charValue;
}

/*********************************************************************
** Description:		This function starts the process of getting valid
**					signed integer from the user. It then returns
**					the value.
*********************************************************************/
int getSignInt()
{
	int validVal;
	validVal = stoi(getInput("int"));
	return validVal;
}

/*********************************************************************
** Description:		This function starts the process of getting valid
**					unsigned integer from the user. It then returns
**					the value.
*********************************************************************/
int getUnsignInt()
{
	int validVal;
	validVal = stoi(getInput("uint"));
	return validVal;
}

/*********************************************************************
** Description:		This function starts the process of getting valid
**					double value from the user. It then returns
**					the value.
*********************************************************************/
double getDouble()
{
	double validVal;
	validVal = stod(getInput("dbl"));
	return validVal;
}

/*********************************************************************
** Description:		This function returns a valid char value
*********************************************************************/
char getAChar()
{
	char validVal;
	string inputString = getInput("achar");
	validVal = inputString[0];

	return validVal;
}

/*********************************************************************
** Description:		This function searches an input string for specific
**					string. It returns true if string is found, false
**					if not found.
*********************************************************************/
bool arraySearch(const string inputString, string searchString)
{
	for (unsigned int i = 0; i < searchString.length(); i++)
	{
		for (unsigned int j = 0; j < inputString.length(); j++)
		{
			if (inputString[j] == searchString[i])
			{
				return true;
			}
		}
	}

	return false;
}

/*********************************************************************
** Description:		This function removes all whitespace from a
**					string.

*********************************************************************/
string removeAllSpaces(string input)
{
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	return input;
}