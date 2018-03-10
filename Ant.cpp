/******************************************************************
** Author: Artem Slivka
** Date : 07/01/17
** Description : Ant.cpp is the function implementation file
**				 for class Ant. This class allows the
**				 user to manipulate an Ant throught it's class 
**				 methods.
******************************************************************/
#include "Ant.hpp"

/*********************************************************************
** Description:		This function is a contructor for Ant class.
**
*********************************************************************/
Ant::Ant()
{
	
}

/*********************************************************************
** Description:		This function is a destructor for Ant class.
**					
*********************************************************************/
Ant::~Ant()
{
	
}

/*********************************************************************
** Description:		This function sets the x coordinate of the ant
**					on the board.
*********************************************************************/
void Ant::setXCoord(int xCoord)
{
	m_xCoord = xCoord;
}

/*********************************************************************
** Description:		This function sets the y coordinate of the ant
**					on the board.
*********************************************************************/
void Ant::setYCoord(int yCoord)
{
	m_yCoord = yCoord;
}

/*********************************************************************
** Description:		This function sets the direction of the ant
**					on the board.
*********************************************************************/
void Ant::setDirection(char direction)
{
	if (direction == 'n')
	{
		m_currDirection = NORTH;
	}
	else if (direction == 's')
	{
		m_currDirection = SOUTH;
	}

	else if (direction == 'e')
	{
		m_currDirection = EAST;
	}
	else if (direction == 'w')
	{
		m_currDirection = WEST;
	}
}
/*********************************************************************
** Description:		This function returns direction of the
**					ant on the board.
*********************************************************************/
char Ant::getDirection()
{
	char direction;
	if (m_currDirection == NORTH)
	{
		direction = 'n';
	}

	else if (m_currDirection == SOUTH)
	{
		direction = 's';
	}

	else if (m_currDirection == EAST)
	{
		direction = 'e';
	}

	else if (m_currDirection == WEST)
	{
		direction = 'w';
	}
	return direction;
}

/*********************************************************************
** Description:		This function returns the x coordinate of the 
**					ant on the board.
*********************************************************************/
int Ant::getXCoord()
{
	return m_xCoord;
}

/*********************************************************************
** Description:		This function returns the y coordinate of the
**					ant on the board.
*********************************************************************/
int Ant::getYCoord()
{
	return m_yCoord;
}

/*********************************************************************
** Description:		This function moves the ant to the left
**					on the board. First, it rotates the ant 90 
**					to the left, then updates the amp's position 
**					to be 1 space forward from initial position.
*********************************************************************/
void Ant::turnLeft()
{
	if (m_currDirection == NORTH)
	{
		m_currDirection = WEST;
		m_xCoord += -1;
	}

	else if (m_currDirection == SOUTH)
	{
		m_currDirection = EAST;
		m_xCoord += 1;
	}

	else if (m_currDirection == EAST)
	{
		m_currDirection = NORTH;
		m_yCoord += -1;
	}
	else if (m_currDirection == WEST)
	{
		m_currDirection = SOUTH;
		m_yCoord += 1;
	}
}

/*********************************************************************
** Description:		This function moves the ant to the right
**					on the board. First, it rotates the ant 90
**					to the right, then updates the amp's position
**					to be 1 space forward from initial position.
*********************************************************************/
void Ant::turnRight()
{
	if (m_currDirection == NORTH)
	{
		m_currDirection = EAST;
		m_xCoord += 1;
	}

	else if (m_currDirection == SOUTH)
	{
		m_currDirection = WEST;
		m_xCoord += -1;
	}

	else if (m_currDirection == EAST)
	{
		m_currDirection = SOUTH;
		m_yCoord += 1;
	}
	else if (m_currDirection == WEST)
	{
		m_currDirection = NORTH;
		m_yCoord += -1;
	}
}

/*********************************************************************
** Description:		This function flips the direction of the ant.
**					If current direction = west, new direction is
**					east, same thing for other directions.
*********************************************************************/
void Ant::flipDirection()
{	
	if (m_currDirection == NORTH)
	{
		m_currDirection = SOUTH;
	}

	else if (m_currDirection == SOUTH)
	{
		m_currDirection = NORTH;
	}

	else if (m_currDirection == EAST)
	{
		m_currDirection = WEST;
	}

	else if (m_currDirection == WEST)
	{
		m_currDirection = EAST;
	}
}
