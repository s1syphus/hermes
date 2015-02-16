
//connect4.h

#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <climits>
using namespace std;


struct c4Board{

	int board[6][7];	// row, col
	int side;
	int value;
	int lastMove[2];	//row, col

	};

class Connect4{

	private:
		c4Board* curBoard;
	public:

		//constructor
		Connect4();
		~Connect4();
		
		//copy constructors

		c4Board* operator=(const c4Board*);
		c4Board operator=(const c4Board);


		//general functions

		void printCurBoard();
		void printBoard(const c4Board*);

		//gameplay, on curBoard
		bool moveValid(int);
		bool gameOver();

		void makeMove(int);	//make move on current board
		
	
		//for ai
		
		//Start with minimax but make sure to do alphabeta
		//also add transpotition tables
	


	};

#endif

