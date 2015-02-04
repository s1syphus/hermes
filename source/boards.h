
//boards.h

#ifndef BOARDS_H
#define BOARDS_H

#include <iostream>

using namespace std;

class tBoard{

	private:
		int* board;
		int value;
		int side;

	public:
		tBoard();
		tBoard(int*, int, int);
		void setBoard(int*);
		void setValue(int);
		void setSide(int);

		int* getBoard();
		int getValue();	
		int getSide();	

	};

#endif
