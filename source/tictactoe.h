//tictactoe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

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


		//general functions (ie print)
		
		//for debug
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
		/*
		alphaBeta();	//add arguments soon
		void genMoves(Board*, );	
		Board* makeMove(Board*, int);
		Board* unmakeMove(Board*, int);
		bool moveValid(const Board*, int);	//overloading for move gen

		*/	


	};


#endif


