
//tictactoe.cpp

#include "tictactoe.h"

TicTacToe::TicTacToe(){

	player[0] = 'X';
	player[1] = 'O';
	player[2] = ' ';
	curBoard = newBoard();
	}


TicTacToe::~TicTacToe(){
	//free up memory

	}

Board* TicTacToe::newBoard(){
	Board* myBoard = new Board;
	for(int i = 0; i < 9; i++){
		myBoard->board[i] = 2;
		}
	myBoard->parent = NULL;
	myBoard->side = 0;	//default to 'X'
	myBoard->lastMove = -1;	//last move is null
	myBoard->value = 0;
	return myBoard;
	}

int TicTacToe::bestMove(){
	Board newBoard = *curBoard;
	Board alphaBoard = newBoard;
	alphaBoard.value = INT_MIN;
	Board betaBoard = newBoard;
	betaBoard.value = INT_MAX;
	Board nextBoard = alphaBeta(newBoard, 10, alphaBoard, betaBoard);
	return nextBoard.lastMove;
	}

Board TicTacToe::max(Board first, Board second){
	if(first.value >= second.value){
		return first;
		}
	return second;
	}

Board TicTacToe::min(Board first, Board second){
	if(first.value <= second.value){
		return first;
		}
	return second;
	}

Board TicTacToe::alphaBeta(Board myBoard, int depth, Board alpha, Board beta){
	Board newBoard = myBoard;
	Board v = myBoard;
	if(depth == 0){
		return newBoard;
		}
	if(gameOver(&newBoard)){
		if(newBoard.side == 0){	//cpu is 'X'
			newBoard.value = 10;
			}
		else{
			newBoard.value = -10;
			}
		return newBoard;
		}
	if(newBoard.side == 0){
		v.value = INT_MIN;
		for(int i = 0; i < 9; i++){
			if(moveValid(&newBoard, i)){
				v = max(v, alphaBeta(makeMove(newBoard,i),depth-1, alpha, beta));
				alpha = max(alpha, v);
				if(beta.value <= alpha.value){
					break;
					}
				}
			}
		return v;
		}
	else{
		v.value = INT_MAX;
		for(int i = 0; i < 9; i++){
			if(moveValid(&newBoard, i)){
				v = min(v, alphaBeta(makeMove(newBoard, i),depth-1, alpha, beta));
				beta = min(beta, v);
				if(beta.value <= alpha.value){
					break;
					}
				}
			}
		return v;
		}		
	}















bool TicTacToe::gameOver(Board* myBoard){
	bool over = true;
	int side = myBoard->side ^ 1;	//because makemove changes side
	//check columns
	for(int i = 0; i < 3; i++){
		over = true;
		for(int j = i; j< 9; j += 3){
			if(myBoard->board[j] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}
		}
	//check rows
	for(int i = 0; i < 9; i += 3){
		over = true;
		for(int j = i; j < (i+3); j++){
			if(myBoard->board[j] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}
		}
	//diagonal one
	over = true;
	for(int i = 0; i < 9; i+=4){
		if(myBoard->board[i] != side){
			over = false;		
			}
		}
	if(over){
		return over;
		}
	//other diagonal	
	over = true;
	for(int i = 2; i < 7; i+=2){
		if(myBoard->board[i] != side){
			over = false;		
			}
		}
	if(over){
		return over;
		}
	return false;
	}
/*
Board* TicTacToe::makeMove(Board* myBoard, int move){
	Board *newBoard = myBoard;
	newBoard->parent = myBoard;
	newBoard->board[move] = myBoard->side;
	newBoard->side ^= 1;
	newBoard->lastMove = move;
	newBoard->board[move] = myBoard->side;
	return newBoard;
	}
*/

Board TicTacToe::makeMove(Board myBoard, int move){
	Board newBoard = myBoard;
	newBoard.parent = &myBoard;
	newBoard.board[move] = myBoard.side;
	newBoard.side ^= 1;
	newBoard.lastMove = move;
	newBoard.board[move] = myBoard.side;
	return newBoard;
	}

bool TicTacToe::moveValid(Board* myBoard, int move){
	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(myBoard->board[move] != 2){
		return false;
		}	
	return true;
	}

void TicTacToe::printBoard(Board* myBoard){
	cout<<"print board function\n";
	cout<<	player[myBoard->board[0]]<<" | "<<
	player[myBoard->board[1]]<<" | "<<
	player[myBoard->board[2]]<<"\n"<<
	player[myBoard->board[3]]<<" | "<<
	player[myBoard->board[4]]<<" | "<<
	player[myBoard->board[5]]<<"\n"<<
	player[myBoard->board[6]]<<" | "<<
	player[myBoard->board[7]]<<" | "<<
	player[myBoard->board[8]]<<"\n\n";
	}

void TicTacToe::printCurBoard(){
	cout<<"printing current board\n";
	cout<<	player[curBoard->board[0]]<<" | "<<
		player[curBoard->board[1]]<<" | "<<
		player[curBoard->board[2]]<<"\n"<<
		player[curBoard->board[3]]<<" | "<<
		player[curBoard->board[4]]<<" | "<<
		player[curBoard->board[5]]<<"\n"<<
		player[curBoard->board[6]]<<" | "<<
		player[curBoard->board[7]]<<" | "<<
		player[curBoard->board[8]]<<"\n\n";

	}

void TicTacToe::printInstructions(){
	cout<<"Select square by number as shown below\n";
	cout<<"0 | 1 | 2\n---------\n3 | 4 | 5\n---------\n6 | 7 | 8\n\n";
	}

bool TicTacToe::moveValid(int move){
	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(curBoard->board[move] != 2){
		return false;
		}	
	return true;
	}

void TicTacToe::makeMove(int move){
	//this makes the move on the current board
	switch(curBoard->side){
		case 0:
			curBoard->board[move] = 0; break;
		case 1:
			curBoard->board[move] = 1; break;
		default:
			cout<<"something went wrong\n";
			break;
		}	
	curBoard->side ^= 1;
	}




bool TicTacToe::gameOver(){
	bool over = true;
	int side = curBoard->side ^ 1;	//because makemove changes side
	//check columns
	for(int i = 0; i < 3; i++){
		over = true;
		for(int j = i; j< 9; j += 3){
			if(curBoard->board[j] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}
		}
	//check rows
	for(int i = 0; i < 9; i += 3){
		over = true;
		for(int j = i; j < (i+3); j++){
			if(curBoard->board[j] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}
		}
	//diagonal one
	over = true;
	for(int i = 0; i < 9; i+=4){
		if(curBoard->board[i] != side){
			over = false;		
			}
		}
	if(over){
		return over;
		}
	//other diagonal	
	over = true;
	for(int i = 2; i < 7; i+=2){
		if(curBoard->board[i] != side){
			over = false;		
			}
		}
	if(over){
		return over;
		}
	return false;
	}

Board* TicTacToe::operator=(const Board* myBoard){
	Board *newBoard = new Board;
	for(int i = 0; i < 9; i++){
		newBoard->board[i] = myBoard->board[i];
		}
	newBoard->parent = myBoard->parent;
	newBoard->lastMove = myBoard->lastMove;
	newBoard->side = myBoard->side;
	newBoard->value = myBoard->value;
	return newBoard;
	}

Board TicTacToe::operator=(const Board myBoard){
	Board newBoard;
	for(int i = 0; i < 9; i++){
		newBoard.board[i] = myBoard.board[i];
		}
	newBoard.parent = myBoard.parent;
	newBoard.lastMove = myBoard.lastMove;
	newBoard.side = myBoard.side;
	newBoard.value = myBoard.value;
	return newBoard;
	}

