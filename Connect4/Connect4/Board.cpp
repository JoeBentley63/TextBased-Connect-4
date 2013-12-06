/********************************************
Connect4 Clone
name: Joseph Bentley	p10011026

/********************************************/
#include "Board.h"
#include <iostream>

using namespace std;
Board::Board(void)
{//initialize the board to all 0's
	for(int i = 0; i < 10; i ++ )
	{
		for(int j = 0; j < 10; j ++ )
		{
			_board[i][j] = 0;
		}
	}
}


Board::~Board(void)
{
}

void Board::PrintBoard()
{
	system("cls");//print out our array line by line
	for(int i = 0; i < 10; i ++)//put the numbers at the top, used to help the player
	{
			cout <<" | "<<i ;
		
	}
	cout<<"\n";
	for(int i = 0; i < 10; i ++ )
	{
		for(int j = 0; j < 10; j ++ )
		{
			cout<<" | "<<_board[i][j] ;
		}
		cout<<"\n";
	}
}

bool Board::CheckForWin()
{
	for(int i = 0; i <= 9; i ++)//check the board for a horizontal win
	{
		for(int j = 0; j <= 6; j++)//account for the j + 3 below, 
		{
			if(_board[j][i] == 1 && _board[j+1][i] ==1 &&  _board[j + 2][i] == 1 &&  _board[j + 3][i] == 1 )
			{
				
				cout<<"PLAYER1 WIN!!!!!!!!!!!!!!!!";
				cin.get();
				return true;
			}
			if(_board[j][i] == 2 && _board[j+1][i] == 2 &&  _board[j + 2][i] == 2 &&  _board[j + 3][i] == 2 )
			{
				
				cout<<"PLAYER2 WIN!!!!!!!!!!!!!!!!";
				cin.get();
				return true;
			}
		}
	}
	for(int i = 0; i <= 6; i ++)//check for a vertical win
	{
		for(int j = 0; j <= 9; j++)
		{
			if(_board[j][i] == 1 && _board[j][i+1] ==1 &&  _board[j][i+2] == 1 &&  _board[j][i+3] == 1 )
			{
				
				cout<<"PLAYER1 WIN!!!!!!!!!!!!!!!!";
				cin.get();
				return true;
			}
			if(_board[j][i] == 2 && _board[j][i+1] == 2 &&  _board[j][i+2] == 2 &&  _board[j][i+3] == 2 )
			{
				
				cout<<"PLAYER2 WIN!!!!!!!!!!!!!!!!";
				cin.get();
				return true;
			}
		}
	}
	//for(int i = 0; i <= 6; i ++)//check for a diagonal \ 
	//{
	//	for(int j = 0; j <= 6; j++)
	//	{
	//		if(_board[j][i] == 1 && _board[j+1][i+1] ==1 &&  _board[j+2][i+2] == 1 &&  _board[j+2][i+3] == 1 )
	//		{
	//			
	//			cout<<"PLAYER1 WIN!!!!!!!!!!!!!!!!";
	//			return true;
	//		}
	//		if(_board[j][i] == 2 && _board[j+1][i+1] == 2 &&  _board[j+2][i+2] == 2 &&  _board[j+3][i+3] == 2 )
	//		{
	//			
	//			cout<<"PLAYER2 WIN!!!!!!!!!!!!!!!!";
	//			return true;
	//		}
	//	}
	//}
	return false;
}


	

bool Board::DoMove(int _peice,int _place)//Do your move
{
		int _posY = 0;//set posy to 0, since we put peices in at the top
		_board[_posY][_place] = _peice;//change the top to the peice
		bool _continue = false;
		while(_continue == false)
		{

			/*if(_posY == 9 || _board[_place][_posY+1] != 0)
			{
				return true;
			
			}*/
			cout<<"moving peice";
			_board[_posY][_place] = 0;
			_posY++;//move the peice
			if(_posY > 9)
			{
				_posY == 9;
			}
			_board[_posY][_place] = _peice;//updaet its position
			if(_posY==9 || _board[_posY+1][_place] != 0)//check if we have hit the bottom, or if we have hit another peice
			{
				_continue = true;
			}
			this->PrintBoard();
			
		}
	return true;

}
