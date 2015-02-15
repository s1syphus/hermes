
//connect4.cpp

#include "connect4.h"

Connect4::Connect4(){
	//initialize board	
	curBoard = new c4Board;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			curBoard->board[i][j] = 2;
			}
		}
	curBoard->side = 0;
	curBoard->value = 0;
	curBoard->lastMove = -1;
	}

Connect4::~Connect4(){
	//clean up memory
	
	}
 
bool Connect4::moveValid(int move){
	bool valid = true;

	//this needs some work, check for column bounds and then if columns are available


	return valid;
	}

bool Connect4::gameOver(){
	//for curBoard
	bool over = false;

	return over;
	}

void Connect4::printCurBoard(){
	char player[3] = {
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			cout<<player[curBoard->board[i][j]]<<" ";
			}
		cout<<endl;
		for(int j = 0; j < 7; j++){
			cout<<"--";
			}
		cout<<endl;
		}
	}

void Connect4::printBoard(const c4Board* myBoard){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			cout<<myBoard->board[i][j]<<" ";
			}
		cout<<endl;
		}
	}	

void Connect4::makeMove(int move){
	//search from the "bottom" up

	for(int i = 5; i >= 0; i--){
		if(curBoard->board[i][move] == 2){
			curBoard->board[i][move] = curBoard->side;
			curBoard->side ^= 1;
			return;
			}
		}
	}




c4Board* Connect4::operator=(const c4Board* myBoard){
	c4Board* newBoard = new c4Board;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			newBoard->board[i][j] = myBoard->board[i][j];
			}
		}
	newBoard->side = myBoard->side;
	newBoard->value = myBoard->value;
	newBoard->lastMove = myBoard->lastMove;
	return newBoard;
	}

c4Board Connect4::operator=(const c4Board myBoard){
	c4Board newBoard;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			newBoard.board[i][j] = myBoard.board[i][j];
			}
		}
	newBoard.side = myBoard.side;
	newBoard.value = myBoard.value;
	newBoard.lastMove = myBoard.lastMove;
	return newBoard;
	}





