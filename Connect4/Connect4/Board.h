/********************************************
Connect4 Clone
name: Joseph Bentley	p10011026

/********************************************/


#ifndef _BOARD_H//include gaurds
#define _BOARD_H
class Board
{
public:
	int _board[10][10];//our actual level
	Board(void);//constructor
	~Board(void);//destructor
	bool CheckForWin();//check has a win condition been meet
	void PrintBoard();//print off the game board
	bool DoMove(int _peice,int _place);//put in a peice
};

#endif

