
//boards.cpp

#include "boards.h"

tBoard::tBoard(){
	//add prompt
	cout<<"this isn't done yet\ntoo bad for you\n";
	}

tBoard::tBoard(int* board, int value, int side){
	setBoard(board);
	setValue(value);
	setSide(side);
	}

void tBoard::setBoard(int *myBoard){
	intBoard = myBoard;
	}

void tBoard::setValue(int myValue){
	value = myValue;
	}

void tBoard::setSide(int mySide){
	side = mySide;
	}

void tBoard::updateBoard(int move, int side){
	intBoard[move] = side;
	}

int* tBoard::getBoard(){
	return intBoard;
	}

int tBoard::getValue(){
	return value;
	}

int tBoard::getSide(){
	return side;
	}


