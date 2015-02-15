
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
	curBoard->lastMove[0] = -1;
	curBoard->lastMove[1] = -1;

	}

Connect4::~Connect4(){
	//clean up memory
	
	}
 
bool Connect4::moveValid(int move){
	if(move > 7 || move < 0){
		return false;
		} if(curBoard->board[0][move] == 2){
		return true;
		}
	return false;
	}

bool Connect4::gameOver(){	//for current board
	
	/*

	This is the right idea but I fucked up my indexing, fix soon, make sure to check
	other functions as well
	*/


	int lastMove[2];
	lastMove[0] = curBoard->lastMove[0];	//row
	lastMove[1] = curBoard->lastMove[1];	//col
	cout<<"last move: < "<<lastMove[0]<<", "<<lastMove[1]<<" >\n";
//	int side = curBoard->side^1;	//make move switches side
	int side = curBoard->side;	//make move switches side

	int counter = 0;
	//check horizontal moves, check boundary conditions
	
	for(int i = -3; i <= 3; i++){
		if((lastMove[1] + i) >= 0 and (lastMove[1] + i) <= 6){
			cout<<"looking at: <"<<lastMove[1] + i<<", "<<lastMove[1]<<"> : "<<curBoard->board[lastMove[1] + i][lastMove[0]]<<endl;
			if(curBoard->board[i][lastMove[0]] == side){
				counter++;	
				if(counter == 4){
					cout<<"game over!\n";
					return true;
					}
				}
			else{
				counter = 0;
				}
			}
		}
	

	return false;

	}

void Connect4::printCurBoard(){
	char player[3] = {'X','O',' '};
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			cout<<player[curBoard->board[i][j]]<<" | ";
			}
		cout<<endl;
		for(int j = 0; j < 7; j++){
			cout<<"----";
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
	//		curBoard->side ^= 1;	 //for debug! fix!!!!!!!!!!!
			curBoard->lastMove[0] = i;
			curBoard->lastMove[1] = move;
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
	newBoard->lastMove[0] = myBoard->lastMove[0];
	newBoard->lastMove[1] = myBoard->lastMove[1];

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
	newBoard.lastMove[0] = myBoard.lastMove[0];
	newBoard.lastMove[1] = myBoard.lastMove[1];

	return newBoard;
	}





