/******************************************************************
** Author: Artem Slivka
** Date : 07/01/17
** Description : Board.cpp is the function implementation file
**				 for class Board. This class allows the
**				 user play the game of Langton's ant.
******************************************************************/
#include "Board.hpp"
/*********************************************************************
** Description:		This function is a contructor for Board class.
**
*********************************************************************/
Board::Board()
{

}

/*********************************************************************
** Description:		This function is a destructor for Board class.
**					It deallocates 2d array board of size (rows*cols)
*********************************************************************/
Board::~Board()
{
	deAllocate();
}

/*********************************************************************
** Description:		This function allocates and fills an empty 2d array
**					for ant based on entered user data for rows and
**					cols.
*********************************************************************/
void Board::createBoard(int height, int width)
{
	//Deallocating old memory
	
	//Allocating the 2d array
	m_height = height;
	m_width = width;
	
	board = new char*[m_height];
	for (int i = 0; i < m_height; i++)
	{
		board[i] = new char[m_width];
	}

	//Filling it with white spaces
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			board[i][j] = white;
		}
	}
}
/*********************************************************************
** Description:		This function sets the initial location of the 
**					ant on the board.
*********************************************************************/
void Board::setAntInit(int xCoord, int yCoord, char direction)
{	
	testAnt.setXCoord(xCoord-1);
	testAnt.setYCoord(yCoord-1);
	testAnt.setDirection(direction);
}

/*********************************************************************
** Description:		This function gets color of the ant at it's current
**					location.
*********************************************************************/
char Board::getColor()
{
	int XCoord = testAnt.getXCoord();
	int YCoord = testAnt.getYCoord();
	return board[YCoord][XCoord];
}

/*********************************************************************
** Description:		This function flips the color of the space
**					the ant currently occupies.
*********************************************************************/
void Board::flipColor()
{
	int XCoord = testAnt.getXCoord();
	int YCoord = testAnt.getYCoord();

	if (getColor() == white)
	{
		board[YCoord][XCoord] = black;
	}
	else if (getColor() == black)
	{
		board[YCoord][XCoord] = white;
	}
}

/*********************************************************************
** Description:		This function moves the ant by turning right or
**					left depending on the color it currently occupies.
**					If the ant encounters a wall, it will turn around
**					and go back.
**					Finally, it switches the color of the previous 
**					space for all cases.
*********************************************************************/
void Board::antMove()
{
	//If the move is valid
	if (isValidMove() == true)
	{
		if (getColor() == white)
		{
			flipColor();
			testAnt.turnRight();
		}
		else if (getColor() == black)
		{
			flipColor();
			testAnt.turnLeft();
		}
	}
	//If the move is not valid, turn the ant around
	//in the opposite direction until a valid move is found
	else
	{
		flipColor();
		while (isValidMove() == false)
		{
				turnAround();

			cout << endl;
		//	cout << "Invalid move. ";
		//	cout << "New direction: " << testAnt.getDirection();
		}
	}
}

/*********************************************************************
** Description:		This function turns the ant around if it hits
**					the left/right x/y boundaries.
*********************************************************************/
void Board::turnAround()
{
	int tempXCoord = testAnt.getXCoord();
	int tempYCoord = testAnt.getYCoord();


	if (tempXCoord == 0)
	{
		testAnt.setXCoord(1);
	}
	if (tempYCoord == 0)
	{
		testAnt.setYCoord(1);
	}
	if (tempXCoord == (m_width - 1))
	{
		testAnt.setXCoord(m_width - 2);
	}

	if (tempYCoord == (m_height - 1))
	{
		testAnt.setYCoord(m_height - 2);
	}
	testAnt.flipDirection();
}

/*********************************************************************
** Description:		This function checks if the next move of the ant
**					is valid.
*********************************************************************/
bool Board::isValidMove()
{
	bool isValid = false;
	int tempXCoord = testAnt.getXCoord();
	int tempYCoord = testAnt.getYCoord();
	//char direction = testAnt.getDirection();
	int allBoundaries = 0;
	//Testing next move, if it will be inside the board.
	if ((tempXCoord + 1) <= (m_width - 1) && (tempXCoord - 1) >= 0)
	{
		allBoundaries++;
	}

	if ((tempYCoord + 1) <= (m_height - 1) && (tempYCoord - 1) >= 0)
	{
		allBoundaries++;
	}

	if (allBoundaries == 2)
	{
		isValid = true;
	}
	return isValid;
}


/*********************************************************************
** Description:		This function starts the program and presents the
**					user with options.
*********************************************************************/
void Board::start()
{
	// 1) Play with user defined params, 2) Play with predefined params, and 3) Quit.
	//Add a new options to the menu
	menu1.addOption(" Play game (with user-defined settings)");			
	menu1.addOption(" Play game (with pre-defined settings)");				
	menu1.addOption(" Quit");	

	//Prints entire menu
	do
	{
		menu1.printMenu();
		cout << "Enter menu selection." << endl;
		int menuChoice;
		menuChoice = getUnsignInt();

		//Check if entered option is valid)
		while(menu1.validMenuOption(menuChoice) == false)
		{
			cout << "Enter a valid menu item(1-3)." << endl;
			menuChoice = getUnsignInt();
		} 

		//Set/select a menu option
		menu1.setOption(menuChoice);

		switch (menu1.getOption())
		{
		case 1: {
				play();
				break;
				}
		case 2: {
				playDefined();
				break;
				}
		}
	} while (menu1.getOption() != 3);

	cout << "Quitting program..." << endl;
}

/*********************************************************************
** Description:		This function controls the play of the board
**					It allows user defined settings for game play.
*********************************************************************/
void Board::play()
{
	int initYCoord, initXCoord;
	char initDirection;

	if (board != NULL)
	{
		deAllocate();
	}

	//Prompting user for initial parameters
	do
	{
		cout << "Enter the desired width of the array(from 3 to 80)" << endl;
		m_width = getUnsignInt();
	} while (m_width > 80 || m_width < 3);
	
	do
	{
		cout << "Enter the desired height of the array(from 3 to 100)" << endl;
		m_height = getUnsignInt();
	} while (m_height > 100 || m_height < 3);

	createBoard(m_height, m_width);

	//Setting initial ant location 
	do
	{
		cout << "Enter starting location column (from 1 to width)" << endl;
		initXCoord = getUnsignInt();
	} while (initXCoord > m_width || initXCoord < 1);

	do
	{
		cout << "Enter starting location row (from 1 to height)" << endl;
		initYCoord = getUnsignInt();
	} while (initYCoord > m_height || initYCoord < 1);
	
	//Setting maximum number of steps
	do
	{
		cout << "Enter number of desired steps(from 1 to 200)" << endl;
		m_maxSteps = getUnsignInt();
	} while (m_maxSteps > 200 || m_maxSteps < 1);
	
	//Setting direction for ant
	do
	{   
		cout << "Enter direction of ant (n, s, e, w) " << endl;
		initDirection = getAChar();
	} while (initDirection != 'n' && initDirection != 's' && initDirection != 'e' && initDirection != 'w');
	
	//Setting ant's initial location on the board
	setAntInit(initXCoord, initYCoord, initDirection);

	//Playing the game 
	for (int i = 0; i < m_maxSteps; i++)
	{
		cout << endl << "  Step " << i + 1;
		cout << "  Direction " << testAnt.getDirection() << ",";
		cout << "  Color ";

		//Printing out the color, instead of the character
		if (getColor() == white)
		{
			cout << "white";
		}
		else if (getColor() == black)
		{
			cout << "black";
		}
					
		//cout << "  Ant pos:" << testAnt.getXCoord() + 1;
		//cout << " " << testAnt.getYCoord() + 1 <<  endl;
		print();
		antMove();
		cout << endl;
	}
	cout << "  Game ended." << endl;
	cin.get();

}

/*********************************************************************
** Description:		This function controls the play of the board
**					It uses pre-defined settings for game play.
*********************************************************************/
void Board::playDefined()
{
	int initYCoord, initXCoord;
	char initDirection;

	//Deallocating board from game1
	if (board != NULL)
	{
		deAllocate();
	}	

	//Setting all  game parameters using the structure data
	m_width = sample.m_width;
	m_height = sample.m_height;
	createBoard(m_height, m_width);
	initYCoord = sample.initY;
	initXCoord = sample.initX;
	m_maxSteps = sample.m_maxSteps;
	initDirection = sample.direction;
	
	//Setting the at the initial location on the board
	setAntInit(initXCoord, initYCoord, initDirection);

	cout << " ===Starting pre-defined game====" << endl;
	cout << "Board size: width=" << m_width;
	cout << ", height =" << m_height << endl;
	cout << "Initial row, column position: ";
	cout << initYCoord << ", " << initXCoord << endl;
	cout << "Number of steps: " << m_maxSteps << endl;
	cout << "Direction: " << initDirection << endl;
	
	//Playing the game 
	for (int i = 0; i < m_maxSteps; i++)
	{
		cout << endl << "  Step " << i + 1;
		cout << "  Direction " << testAnt.getDirection() << ",";

		//Printing out the color, instead of the character
		cout << "  Color ";
		if (getColor() == white)
		{
			cout << "white";
		}
		else if (getColor() == black)
		{
			cout << "black" ;
		}
		//cout << "  Ant pos:" << testAnt.getXCoord() + 1;
		//cout << " " << testAnt.getYCoord() + 1<< endl;
		print();
		antMove();
		cout << endl;
	}
	cout << "  Game ended." << endl;
	cin.get();
}

/*********************************************************************
** Description:		This function prints the current board state
**					with current step info.
*********************************************************************/
void Board::print()
{
	//Storing the current ant location
	int XCoord = testAnt.getXCoord();
	int YCoord = testAnt.getYCoord();

	for (int i = 0; i < m_height; i++)
	{
		cout << endl << "  ";
		for (int j = 0; j < m_width; j++)
		{
			//If iterating through the ant location
			//prints the ant's character
			if (XCoord == j && YCoord == i)
			{
				cout << '@';
			}
			//Otherwise just prints what's on the board
			else
			{
				cout << board[i][j];
			}
		}
	}
}

/*********************************************************************
** Description:		This function deallocates the memory for the board
**					
*********************************************************************/
void Board::deAllocate()
{
	for (int i = 0; i < m_height; i++)
	{
		//Freeing individual rows
		delete[] board[i];
	}
	delete[] board;
}

