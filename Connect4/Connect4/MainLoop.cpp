/********************************************
Connect4 Clone
name: Joseph Bentley	p10011026

/********************************************/

#include "Board.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

typedef struct Peice//struct to hold the move data
{
	int _position;// the position 0-9 at the top of the board to put in it
	int _type;
};

int main()
{
	cout<<"-----------Welcome to 4-in-a-row!----------------";
	cout<<"\n the aim of the game is to get 4 in a row or column!\n ";
	cout<<"One or 2 player?(enter 1 or 2)\n";
	cout<<"One player is against AI, 2 Player lets you play with a buddy :D \n";
	int _numPlayers;//read in the number of players, i wanted AI :D
	cin>>_numPlayers;
	srand(time(NULL));//random, for simple AI
	Board* _board = new Board();//create a pointer to a new Board Object
	while(_board->CheckForWin() == false)//loop untill someone wins
	{
		_board->PrintBoard();
		cout<<"\n enter your move Player 1 \n";
		Peice _myMove;//create a peice, then read in the players move
		cin>>_myMove._position;
		_myMove._type=1;//set their type(colour in connect 4)
		_board->DoMove(_myMove._type,_myMove._position);//execute the move
		if(_numPlayers==1)//if its 1 player, 
		{
			Peice _enemyMove;//gen a random, and execute a cpu move
			_enemyMove._type = 2;
			_enemyMove._position = rand()%10;
			_board->DoMove(_enemyMove._type,_enemyMove._position);
		}
		else//otherwise its 2 player, so just read it in
		{
			cout<<"\n enter your move Player 2 \n";
			Peice _myMove;
			cin>>_myMove._position;
			_myMove._type=2;
			_board->DoMove(_myMove._type,_myMove._position);

		}
		
	}
	cin.get();
	system("cls");
	cout<<"thanks for playing :D";
	cin.get();
	return 0;
}