
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
	
	depth = 3;
		/*
	cout<<"here testing stuff\n";	

	c4Board boardTest = *curBoard;


	boardTest = makeMove(boardTest, 0);
	printBoard(&boardTest);
	boardTest = makeMove(boardTest, 0);
	printBoard(&boardTest);
	boardTest = makeMove(boardTest, 1);
	printBoard(&boardTest);
	boardTest = makeMove(boardTest, 1);
	printBoard(&boardTest);
	boardTest = makeMove(boardTest, 2);
	printBoard(&boardTest);
	boardTest = makeMove(boardTest, 2);
	printBoard(&boardTest);
*/
		boardCount = 0;

//	c4Board bestBoard = minimax(boardTest, depth);

//	cout<<"in best move\n";
//	printBoard(curBoard);
	c4Board newBoard = *curBoard;

	c4Board bestBoard = minimax(newBoard, depth);

	printf("boards considered: %d\n",boardCount);
	cout<<"best board has a value of: "<<bestBoard.value<<endl;
	return bestBoard.lastMove[1];	//col is only "move"
	}
/*
c4Board Connect4::minimax(c4Board myBoard, int depth){
	return maxValue(myBoard, depth);
	}
*/

c4Board Connect4::minimax(c4Board myBoard, int depth){
	c4Board bestBoard = myBoard;
	c4Board tempBoard = myBoard;
	bestBoard.value = INT_MIN;
	tempBoard.value = INT_MIN;
	for(int i = 0; i < 7; i++){
		if(moveValid(&myBoard, i)){
			tempBoard = minValue(makeMove(myBoard, i), depth);
			if(tempBoard.value > bestBoard.value){
				bestBoard = tempBoard;
				bestBoard.lastMove[1] = i;
				}
			}
		}

	return bestBoard;

	}


c4Board Connect4::maxValue(c4Board myBoard, int depth){
	if(gameOver(&myBoard) || depth == 0){
		return myBoard;
		}
	c4Board v = myBoard;
	v.value = INT_MIN;
	for(int i = 0; i < 7; i++){
		if(moveValid(&myBoard, i)){
			v = max(v, minValue(makeMove(myBoard, i), depth - 1));
			}
		}
	return v;
	}


c4Board Connect4::minValue(c4Board myBoard, int depth){
	if(gameOver(&myBoard) || depth == 0){
		return myBoard;
		}
	c4Board v = myBoard;
	v.value = INT_MAX;
	for(int i = 0; i < 7; i++){
		if(moveValid(&myBoard, i)){
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
	cout<<"ERROR\n";
	return myBoard;	//should never get here, move is assumed valid
			//and checked before function is called
	}

bool Connect4::gameOver(c4Board* testBoard){
	//"connect 3" currently

	int connect = 3;

	c4Board myBoard = *testBoard;
	int lastRow = myBoard.lastMove[0];
	int lastCol = myBoard.lastMove[1];
	int newRow, newCol, counter;
	for(int side = 0; side <= 1; side++){
	//check vertical
	counter = 0;
	for(int i = -connect; i <= connect; i++){
		newRow = lastRow + i;
		if(onBoard(newRow, lastCol)){
			if(myBoard.board[newRow][lastCol] == side){
				counter++;
				if(counter >= connect){
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
	for(int i = -connect; i <= connect; i++){
		newCol = lastCol + i;
		if(onBoard(lastRow, newCol)){
			if(myBoard.board[lastRow][newCol] == side){
				counter++;
				if(counter >= connect){
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
	for(int i = -connect; i <= connect; i++){
		newRow = lastRow + i;
		newCol = lastCol + i; 
		if(onBoard(newRow, newCol)){
			if(myBoard.board[newRow][newCol] == side){
				counter++;
				if(counter >= connect){
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
	for(int i = -connect; i <= connect; i++){
		newRow = lastRow - i;
		newCol = lastCol + i; 
		if(onBoard(newRow, newCol)){
			if(myBoard.board[newRow][newCol] == side){
				counter++;
				if(counter >= connect){
					return true;
					}
				}
			else{
				counter = 0;
				}
			}
		}	
	}
	return false;
	}



/*
 *	Change this to check both sides, ugh
 *
 */
/*
bool Connect4::gameOver(c4Board* testBoard){
//	cout<<"side: "<<testBoard->side<<"\n";


	//"connect 3" currently

	c4Board myBoard = *testBoard;
	int lastRow = myBoard.lastMove[0];
	int lastCol = myBoard.lastMove[1];
	int newRow, newCol, counter;
	int side = myBoard.side;

	//check vertical
	counter = 0;
	for(int i = -3; i <= 3; i++){
		newRow = lastRow + i;
		if(onBoard(newRow, lastCol)){
			if(myBoard.board[newRow][lastCol] == side){
				counter++;
				if(counter >= 3){
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
			if(myBoard.board[lastRow][newCol] == side){
				counter++;
				if(counter >= 3){
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
			if(myBoard.board[newRow][newCol] == side){
				counter++;
				if(counter >= 3){
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
			if(myBoard.board[newRow][newCol] == side){
				counter++;
				if(counter >= 3){
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
*/
bool Connect4::moveValid(c4Board* myBoard, int move){
	boardCount++;	// counter to make sure I'm doing things correctly
	//printBoard(myBoard);
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
//	c4Board tempBoard = *curBoard;
//	cout<<"checking game over for side: "<<tempBoard.side<<endl;
//	tempBoard.side ^= 1;
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

void Connect4::printBoard(c4Board* myBoard){
	cout<<"\n\n";
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			cout<<myBoard->board[i][j]<<" ";
			}
		cout<<endl;
		}
	cout<<"\n\n";

	}	

void Connect4::makeMove(int move){
//	cout<<"checking col: "<<move<<endl;
	cout<<"changing side for curBoard\n";
	//search from the "bottom" up
	for(int i = 5; i >= 0; i--){
		if(curBoard->board[i][move] == 2){
			curBoard->board[i][move] = curBoard->side;
			curBoard->lastMove[0] = i;
			curBoard->lastMove[1] = move;
			curBoard->side ^= 1;
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





