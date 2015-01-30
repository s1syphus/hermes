
//tictactoe.cpp

#include "tictactoe.h"

TicTacToe::TicTacToe(){

	//default constructor
	resetBoard();

	}

void TicTacToe::resetBoard(){
	for(int i = 0; i < 9; i++){
		board[i] = ' ';
		}
	}

void TicTacToe::printBoard(){

	cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"\n"<<
	"---------\n"<<
	board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n"<<
	"---------\n"<<
	board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
	}

void TicTacToe::printInstructions(){


	for(int i = 0; i < 9; i++){
		board[i] = '0' + i ;
		}

	cout<<"Select square by number as shown below\n";
	printBoard();
	cout<<endl;

	resetBoard();


	}

void TicTacToe::makeMove(int move, int side){

	switch(side){
		case 0: //'X'
			board[move] = 'X';
			break;
		case 1: //'O'
			board[move] = 'O';
			break;
		default:
			cout<<"something broke (also turn this into a real error code\n";
			break;
		}

	}

bool TicTacToe::moveValid(int move){

	//make sure move is valid...ie in range and not already taken

	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(board[move] != ' '){
		return false;
		}	


	return true;
	}

bool TicTacToe::gameOver(){

	//check victory conditions, there's probably a good way to do this


	




	return false;

	}



