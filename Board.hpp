/******************************************************************
** Author:		Artem Slivka
** Date:		07/01/17
** Description: Board.hpp is the header file for class
**				Board.
******************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include <string>
#include <iostream>
#include "Ant.hpp"
#include "Menu.hpp"
#include "InputVal.hpp"
using std::cout;
using std::endl;
using std::string;

class Board
{
private:
	int m_height;
	int m_width;
	char white = '.';
	char black = '#';
	int m_maxSteps;
	char** board = NULL;
	Ant testAnt;
	Menu menu1;
	struct SampleGame 
	{
		int m_height = 5;
		int m_width = 5;
		int m_maxSteps = 80;
		char direction = 'n';
		int initX = 3;
		int initY = 3;
	};
	SampleGame sample;

public:
	Board();
	~Board();
	void createBoard(int height, int width);
	void setAntInit(int xCoord, int yCoord, char direction);
	char getColor();
	void flipColor();
	void antMove();
	void turnAround();
	bool isValidMove();
	void start();
	void play();
	void playDefined();
	void print();
	void deAllocate();
	
};

#endif 