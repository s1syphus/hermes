
//boards.h

#ifndef BOARDS_H
#define BOARDS_H

#include <iostream>

using namespace std;

class tBoard{

	private:
		int* intBoard;
		int value;
		int side;

	public:
		tBoard();
		tBoard(int*, int, int);
		void setBoard(int*);
		void setValue(int);
		void setSide(int);
		void updateBoard(int, int);
		void switchSide();		
		
		int* getBoard();
		int getValue();	
		int getSide();	
	
//		tBoard* makeMove(tBoard*, int);
//		tBoard* unmakeMove(tBoard*, int);

	};

#endif
