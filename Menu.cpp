/******************************************************************
** Author: Artem Slivka
** Date : 06/21/17
** Description : Menu.cpp is the function implementation file
**				 for class Menu. This class stores a customizable
**				 menu. You can add options later, print the menu, and
**				 check if the menu option is valid
******************************************************************/
#include "Menu.hpp"			//Link to class header


/*********************************************************************
** Description: This is a default constructor. It sets no options
**				and has no option descriptions
*********************************************************************/
Menu::Menu()
{
	currentOption = 0;
}

/*********************************************************************
** Description: This is the 2nd constructor. It adds an option to the
**				the current menu using the description argument.
*********************************************************************/
Menu::Menu(string pOptionDescription)
{
	addOption(pOptionDescription);
}

/*********************************************************************
** Description:  This function checks if the entered menu option is
**				 valid according to current menu.
*********************************************************************/
bool Menu::validMenuOption(int pMenuOption)
{
	//Checking if option is in valid range
	if ((pMenuOption > 0) && (static_cast<unsigned int>(pMenuOption) <= menuItems.size()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description:  This function adds another option to the menu
*********************************************************************/
void Menu::addOption(string pOptionDescription)
{
	menuItems.push_back(pOptionDescription);
}

/*********************************************************************
** Description:  This function selects an option from menu. It 
**				 returns true if the menu selection was successful.
*********************************************************************/
bool Menu::setOption(int pMenuOption)
{
	//If valid menu option is available
	if (validMenuOption(pMenuOption) == true)
	{
		currentOption = pMenuOption;
		return true;
	}
	//If the option isn't available
	else
	{
		cout << "Error! Select a valid menu option" ;
		cout << "(1 to " << menuItems.size() << ")" << endl;
		return false;
	}
}

/*********************************************************************
** Description:  This function returns the currently selected
**				 option in the menu.
*********************************************************************/
int Menu::getOption()
{
	return currentOption;
}

/*********************************************************************
** Description:  This function prints the current menu
*********************************************************************/
void Menu::printMenu()
{
	cout << endl;
	cout << "====Current menu====" << endl;
	//If menu vector isn't empty
	if (menuItems.size() > 0)
	{
		for (unsigned int count = 0; count < menuItems.size(); count++)
		{
		cout << " " << (count + 1) << ": " << menuItems[count] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Menu is empty." << endl;
	}
	
}
		
/*********************************************************************
** Description:  This function prints the selected menu option
*********************************************************************/
void Menu::printOption()
{
	cout << endl;
	cout << "====Selected menu option====" << endl;
	cout << " " << getOption() << ": ";
	cout << menuItems[getOption() - 1] << endl << endl;
}

/*********************************************************************
** Description:  This function prints any available menu option
*********************************************************************/
void Menu::printAnyOption(int pMenuOption)
{
	cout << endl;
	if (validMenuOption(pMenuOption) == true)
	{
		cout << "====Menu option====" << endl;
		cout << " " << pMenuOption << ": ";
		cout << menuItems[pMenuOption - 1] << endl << endl;
	}
	else
	{
		cout << "Error! Invalid option." << endl;
	}
}
/*********************************************************************
** Description:  This function clears the menu of all items
*********************************************************************/
void Menu::clear()
{
	menuItems.clear();
}

