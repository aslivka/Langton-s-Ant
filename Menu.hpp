/******************************************************************
** Author: Artem Slivka
** Date: 06/21/17
** Description: Menu.hpp is the header file for class Menu
******************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Menu
{
private:
	vector<string> menuItems;
	int currentOption;

public:
	Menu();												//Default constructor
	Menu(string pOptionDescription);					//Constructor with parameters
	void addOption(string pOptionDescription);			//Add a new option to the menu
	bool setOption(int pMenuOption);					//Set/select a menu option
	int getOption();								    //Returns current menu option as int
	void printMenu();									//Prints current menu
	void printOption();								    //Prints the selected option description only
	void printAnyOption(int pMenuOption);				//Prints any available menu option
	void clear();										//Clears current menu to have no options
	bool validMenuOption(int pMenuOption);				//Checks if entered option is valid
};

#endif
