
//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>

#include "alphabeta.h"
#include "boards.h"

using namespace std;


class TicTacToe{

	private:
		tBoard *board; //  'X' = 0, 'O' = 1, ' ' = 2
		char player[3];
		
	public:
		TicTacToe();//constructor
		~TicTacToe(); //deconstructor, make this later
		void resetBoard();
		void printBoard();
		void printInstructions();
		void makeMove(int,int);
		bool moveValid(int);
		bool gameOver(int,int);

		void testAlpha();

		//skeleton functions


		int evaluateMove();
	};





#endif





