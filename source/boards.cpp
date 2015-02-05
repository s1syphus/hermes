
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




/*


tBoard* TicTacToe::makeMove(tBoard* myBoard, int move ){
	tBoard* newBoard = new tBoard(myBoard->getBoard(), myBoard->getValue(), myBoard->getSide());
	switch(newBoard->getSide()){
		case 0: //'X'
			newBoard->updateBoard(move, 0);
			break;
		case 1: //'O'
			newBoard->updateBoard(move, 1);
			break;
		default:
			break;
		}
	newBoard->switchSide();
	return newBoard;
	}

tBoard* TicTacToe::unmakeMove(tBoard* myBoard, int move){

	//fix this
	return myBoard;
	}

*/


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
	int* newBoard = new int[9];
	for(int i = 0; i < 9; i++){
		newBoard[i] = intBoard[i];
		}
	return newBoard;
	}

int tBoard::getValue(){
	return value;
	}

int tBoard::getSide(){
	return side;
	}


