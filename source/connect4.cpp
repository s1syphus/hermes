
//connect4.cpp

#include "connect4.h"

int boardCount;	//just for checking stuff, delete later

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

void Connect4::genHashKey(c4Board* myBoard){
	//do stuff here
	//generate and update hash key for myBoard	
	}



int Connect4::bestMove(int depth){

	//might be able to remove this function
	//keeping it for now for cleaner debug
	//
	//
	boardCount = 0;
	c4Board bestBoard = minimax(*curBoard, depth);
	printf("boards considered: %d\n",boardCount);
	return bestBoard.lastMove[1];	//col is only "move"
	}


c4Board Connect4::minimax(c4Board myBoard, int depth){

	c4Board bestBoard = myBoard;
	c4Board tempBoard = myBoard;
	bestBoard.value = INT_MIN;
	tempBoard.value = INT_MIN;
	for(int i = 0; i < 9; i++){
		if(moveValid(&myBoard, i)){
			tempBoard = minValue(makeMove(myBoard,i), depth - 1);
			if(tempBoard.value > bestBoard.value){	
				bestBoard = tempBoard;
				}
			}
		}	
	return bestBoard;
	}

c4Board Connect4::maxValue(c4Board myBoard, int depth){
	c4Board v = myBoard;
	if(gameOver(&myBoard) || depth == 0){
		return myBoard;
		}
	v.value = INT_MIN;
	for(int i = 0; i < 9; i++){
		if(moveValid(&myBoard, i)){
			boardCount++;//temp
			v = max(v, minValue(makeMove(myBoard, i), depth - 1));
			}		
		}
	return v;
	}


c4Board Connect4::minValue(c4Board myBoard, int depth){
	c4Board v = myBoard;
	if(gameOver(&myBoard) || depth == 0){
		return myBoard;
		}
	v.value = INT_MAX;
	for(int i = 0; i < 9; i++){
		if(moveValid(&myBoard, i)){
			boardCount++;//temp
			v = min(v, maxValue(makeMove(myBoard, i), depth - 1));
			}		
		}
	return v;
	}


c4Board Connect4::max(c4Board first, c4Board second){
	if(first.value > second.value){
		return first;
		}
	return second;
	}

c4Board Connect4::min(c4Board first, c4Board second){
	if(first.value < second.value){
		return first;
		}
	return second;
	}


c4Board Connect4::makeMove(c4Board myBoard, int move){
	for(int i = 5; i >= 0; i--){
		if(myBoard.board[i][move] == 2){
			myBoard.board[i][move] = myBoard.side;
			myBoard.lastMove[0] = i;
			myBoard.lastMove[1] = move;
			if(gameOver(&myBoard)){
				if(myBoard.side == 0){
					myBoard.value = 10;
					}
				else{
					myBoard.value = -10;
					}
				}
			myBoard.side ^= 1;
			return myBoard;
			}
		}

	return myBoard;	//should never get here, move is assumed valid
			//and checked before function is called
	}

bool Connect4::gameOver(c4Board* myBoard){
	int lastRow = myBoard->lastMove[0];
	int lastCol = myBoard->lastMove[1];
	int newRow, newCol, counter;
	int side = myBoard->side^1;
	//check vertical
	counter = 0;
	for(int i = -3; i <= 3; i++){
		newRow = lastRow + i;
		if(onBoard(newRow, lastCol)){
			if(myBoard->board[newRow][lastCol] == side){
				counter++;
				if(counter >= 4){
//					cout<<"won vertical\n";
					return true;
					}
				}
			else{
				counter = 0;
				}
			}
		}

	//check horizontal
	counter = 0;
	for(int i = -3; i <= 3; i++){
		newCol = lastCol + i;
		if(onBoard(lastRow, newCol)){
			if(myBoard->board[lastRow][newCol] == side){
				counter++;
				if(counter >= 4){
//					cout<<"won horizontal\n";

					return true;
					}
				}
			else{
				counter = 0;
				}
			}
		}

	//check diagonal up to down
	counter = 0;
	for(int i = -3; i <= 3; i++){
		newRow = lastRow + i;
		newCol = lastCol + i; 
		if(onBoard(newRow, newCol)){
			if(myBoard->board[newRow][newCol] == side){
				counter++;
				if(counter >= 4){
//					cout<<"won up to down\n";
					return true;
					}
				}
			else{
				counter = 0;
				}
			}
		}	

	//check diagonal down to up
	counter = 0;
	for(int i = -3; i <= 3; i++){
		newRow = lastRow - i;
		newCol = lastCol + i; 
		if(onBoard(newRow, newCol)){
			if(myBoard->board[newRow][newCol] == side){
				counter++;
				if(counter >= 4){
//					cout<<"won down to up\n";
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

bool Connect4::moveValid(c4Board* myBoard, int move){
	if(move > 7 || move < 0){
		return false;
		} 
	if(myBoard->board[0][move] == 2){
		return true;
		}
	return false;
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
	return gameOver(curBoard);
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
//	cout<<"checking col: "<<move<<endl;
	//search from the "bottom" up
	for(int i = 5; i >= 0; i--){
		if(curBoard->board[i][move] == 2){
			curBoard->board[i][move] = curBoard->side;
			curBoard->side ^= 1;
			curBoard->lastMove[0] = i;
			curBoard->lastMove[1] = move;
			cout<<"Making move: "<<i<<", "<<move<<endl;
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





