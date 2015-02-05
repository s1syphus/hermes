
//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <stack>

#include "alphabeta.h"
#include "boards.h"

#define TMAX_DEPTH 2

using namespace std;

//at some point make accessor functions const
//and make sure I don't mess up my structures


class TicTacToe{

	private:
		tBoard *board; //  'X' = 0, 'O' = 1, ' ' = 2
		char player[3];
		
	public:
		TicTacToe();//constructor
		~TicTacToe(); //deconstructor, make this later
		void resetBoard();
		void printBoard();
		void printBoard(tBoard*);
		void printInstructions();
		tBoard* makeMove(tBoard*, int);
		tBoard* unmakeMove(tBoard*, int);
		bool moveValid(int);
		bool moveValid(tBoard*, int);	//overloaded, might fix later
		bool gameOver(tBoard*, int,int);
		bool gameOver(tBoard*);	//overloaded, might fix later
		tBoard* getCurBoard();


		//debug

		void testAlpha();
		void genMoves(tBoard*);	

	};





#endif





