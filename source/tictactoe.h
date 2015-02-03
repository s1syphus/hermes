
//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>


using namespace std;



class TicTacToe{

	private:
		int board[9]; //  'X' = 0, 'O' = 1, ' ' = 2
		char player[3];
	public:
		TicTacToe();//constructor
		~TicTacToe(); //deconstructor, make this later
		void initializeTicTacToe(); // set up board
		void resetBoard();
		void printBoard();
		void printInstructions();
		void makeMove(int,int);
		bool moveValid(int);
		bool gameOver(int,int);
		int evaluateMove();//this needs to be written
	};





#endif





