
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
	intBoard = new int[9];
	for(int i = 0; i < 9; i++){
		intBoard[i] = myBoard[i];
		}
	}

void tBoard::setValue(int myValue){
	value = myValue;
	}

void tBoard::setSide(int mySide){
	side = mySide;
	}

void tBoard::switchSide(){
	side ^= 1;
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


