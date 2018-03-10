/******************************************************************
** Author:		Artem Slivka
** Date:		07/01/17
** Description: Ant.hpp is the header file for class
**				Ant.
******************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Ant
{
private:
	enum Direction {SOUTH = 0, NORTH = 1, EAST = 2, WEST = 3};
	int m_xCoord, m_yCoord;
	Direction m_currDirection;
	
public:
	Ant();		//Default constructor
	~Ant();
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	void setDirection(char direction);
	char getDirection();
	void flipDirection();
	int getXCoord();
	int getYCoord();
	void turnLeft();
	void turnRight();	
};

#endif 