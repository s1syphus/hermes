
//tictactoe.cpp

#include "tictactoe.h"

TicTacToe::TicTacToe(){
	int* newBoard = new int[9];
	for(int i = 0; i < 9; i++){
		newBoard[i] = 2;
		}
	board = new tBoard(newBoard, 0, 0);
	player[0] = 'X';
	player[1] = 'O';
	player[2] = ' ';
	}

TicTacToe::~TicTacToe(){
	//free up memory
	}

/*
void TicTacToe::genAllMoves(int *board, Node* parent, vector<Node*>* moves, int side){

	//generates all valid moves for current board position


	

	}
*/


void TicTacToe::testAlpha(){
/*
	int* newBoard = new int[9];

	newBoard[0] = 1;
	newBoard[1] = 2;
	newBoard[2] = 0;

	newBoard[3] = 0;
	newBoard[4] = 2;
	newBoard[5] = 2;

	newBoard[6] = 0;
	newBoard[7] = 1;
	newBoard[8] = 1;

	board->setBoard(newBoard);
	printBoard();
*/
	}



void TicTacToe::printBoard(){

	int* myBoard = board->getBoard();

	cout<<player[myBoard[0]]<<" | "<<player[myBoard[1]]<<" | "<<player[myBoard[2]]<<"\n"<<
	player[myBoard[3]]<<" | "<<player[myBoard[4]]<<" | "<<player[myBoard[5]]<<"\n"<<
	player[myBoard[6]]<<" | "<<player[myBoard[7]]<<" | "<<player[myBoard[8]]<<"\n";

	}

bool TicTacToe::gameOver(int move,int side){

	//check victory conditions, there's probably a good way to do this
	bool over = true;
	int n = 3; // size of board, this function will be reused for connect4
	int start = move;

	//this is for rows	
	start = move - (move %3);
	int* myBoard = board->getBoard();


	for(int i = start ; i < (start + n); i++){
		if(myBoard[i] != side){
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
		if(myBoard[i] != side){
			over = false;
			}
		}

	if(over){
		return over;
		}	
	
	//diag
	over = true;

	if((move%4) == 0){
		for(int i = 0; i < 9; i+=4){
			if(myBoard[i] != side){
				over = false;
				}
			}

		if(over){
			return over;
			}	
		}
	//other diag
	over = true;
	for(int i = 2; i < 7; i+=2){
		if(myBoard[i] != side){
			over = false;
			}
		}
	return over;

	}

void TicTacToe::printInstructions(){
	cout<<"Select square by number as shown below\n";
	cout<<"0 | 1 | 2\n---------\n3 | 4 | 5\n---------\n6 | 7 | 8 "<<endl<<endl;
	}

bool TicTacToe::moveValid(int move){
	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(board->getBoard()[move] != 2){
		return false;
		}	
	return true;
	}

void TicTacToe::makeMove(int move, int side){
	switch(side){
		case 0: //'X'
			board->updateBoard(move, 0);
			break;
		case 1: //'O'
			board->updateBoard(move, 1);
			break;
		default:
			break;
		}
	}


