//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <climits>
using namespace std;


//Board struct

struct Board{

	Board* parent;
	int lastMove;
	int side;
	int board[9];
	int value;

	};

//Actual game class

class TicTacToe{

	private:
			
		Board* curBoard;
		char player[3];

	public:

		TicTacToe(); //Default constructor
		~TicTacToe();	//deconstructor, need to do stuff here

		//copy constructor for board
		Board* operator=(const Board*);
		Board operator=(const Board);


		//general functions (ie print)
		
		void printBoard(Board*);
		void printCurBoard();	
		void printInstructions();

		//Accessors

		//Manipulators, mainly for curBoard
		Board* newBoard();	
		bool moveValid(int);
		bool gameOver();
		void makeMove(int);

		//For AI
		int bestMove();
		Board minimaxDecision(Board);
		Board maxValue(Board);
		Board minValue(Board);

		bool gameOver(Board*);
		Board makeMove(Board, int);
		bool moveValid(Board*, int);	//overloading for move gen
		Board max(Board, Board);
		Board min(Board, Board);

	};


#endif


