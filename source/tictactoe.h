
//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
using namespace std;


class TicTacToe{

	private:
		char board[9];

	public:
		TicTacToe();//constructor
		void initializeTicTacToe(); // set up board
		void resetBoard();
		void printBoard();
		void printInstructions();
		void makeMove(int,int);
		bool moveValid(int);
		bool gameOver();
/*
		void genMove(); 	
		void genAllMoves();	
*/
	};





#endif





