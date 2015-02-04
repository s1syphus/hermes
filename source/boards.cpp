
//boards.cpp

#include "boards.h"

tBoard::Board(){
	//add prompt
	cout<<"this isn't done yet\ntoo bad for you\n";
	}


tBoard::tBoard(int* board, int value, int side){
	setBoard(board);
	setValue(value);
	setSide(side);
	}

void tBoard::setBoard(int *myBoard){
	board = myBoard;
	}


void tBoard::setValue(int myValue){
	value = myValue;
	}

void tBoard::setSide(int mySide){
	side = mySide;
	}


int* tBoard::getBoard(){
	return board;
	}

int tBoard::getValue(){
	return value;
	}

int tBoard::getSide(){
	return side;
	}


