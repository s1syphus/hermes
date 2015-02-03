
//tictactoe.cpp

#include "tictactoe.h"

TicTacToe::TicTacToe(){
	resetBoard();
	player[0] = 'X';
	player[1] = 'O';
	player[2] = ' ';
	}

TicTacToe::~TicTacToe(){
	//free up memory
	}

int TicTacToe::evaluateMove(){

	//this is going to send the numbers to minimax...

	//lets get minimax working first

	return 0;
	}























void TicTacToe::printBoard(){
	cout<<player[board[0]]<<" | "<<player[board[1]]<<" | "<<player[board[2]]<<"\n"<<
	"---------\n"<<
	player[board[3]]<<" | "<<player[board[4]]<<" | "<<player[board[5]]<<"\n"<<
	"---------\n"<<
	player[board[6]]<<" | "<<player[board[7]]<<" | "<<player[board[8]]<<endl;
	}

bool TicTacToe::gameOver(int move,int side){

	//check victory conditions, there's probably a good way to do this
	bool over = true;
	int n = 3; // size of board, this function will be reused for connect4
	int start = move;

	//this is for rows	
	start = move - (move %3);
	for(int i = start ; i < (start + n); i++){
		if(board[i] != side){
			over = false;
			}
		}
	if(over){
		return over;
		}	

	//this is for cols
	start = move%3;
	over = true;
	for(int i = start ; i < (start + n*n); i+= 3){
		if(board[i] != side){
			over = false;
			}
		}

	if(over){
		return over;
		}	
	
	//diag
	over = true;
	if(move%2 != 0){	//short circuit
		return false;
		}
	
	if(move%4 == 0){
		for(int i = 0; i < 9; i+=4){
			if(board[i] != side){
				over = false;
				}
			}
		}
	//other diag
	over = true;
	for(int i = 2; i < 7; i+=2){
		if(board[i] != side){
			over = false;
			}
		}
	return over;
	}

void TicTacToe::printInstructions(){
	cout<<"Select square by number as shown below\n";
	cout<<"0 | 1 | 2\n---------\n3 | 4 | 5\n---------\n6 | 7 | 8 "<<endl<<endl;
	}

void TicTacToe::resetBoard(){
	for(int i = 0; i < 9; i++){
		board[i] = 2;
		}
	}

bool TicTacToe::moveValid(int move){
	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(board[move] != 2){
		return false;
		}	
	return true;
	}

void TicTacToe::makeMove(int move, int side){

	switch(side){
		case 0: //'X'
			board[move] = 0;
			break;
		case 1: //'O'
			board[move] = 1;
			break;
		default:
			cout<<"something broke (also turn this into a real error code\n";
			break;
		}
	}


