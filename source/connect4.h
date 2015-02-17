
//connect4.h

#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef unsigned long long uint64;

inline bool onBoard(int row, int col){
	if(row >= 0 and row < 6 and col >= 0 and col < 7){
		return true;
		}
	return false;
	}

inline uint64 rand64(){
	return 	((uint64)rand() | \
		(uint64)rand() << 15 | \
		(uint64)rand() << 30 | \
		(uint64)rand() << 45 | \
		((uint64)rand() & 0xf) << 60 );
	}

struct c4Board{

	int board[6][7];	// row, col
	int side;
	int value;
	int lastMove[2];	//row, col
	uint64 hashKey;

	};

class Connect4{

	private:
		c4Board* curBoard;
		void genHashKey(c4Board*);
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
		//also add transposition tables

		int bestMove(int);
		c4Board minimax(c4Board, int);
		c4Board maxValue(c4Board, int);
		c4Board minValue(c4Board, int);

		bool gameOver(c4Board*);
		c4Board makeMove(c4Board, int);
		bool moveValid(c4Board*, int);	//overloading for move gen
		c4Board max(c4Board, c4Board);
		c4Board min(c4Board, c4Board);




//		void setHash();
//		probeTable();
//		addToTable(c4Board);

	};

#endif

