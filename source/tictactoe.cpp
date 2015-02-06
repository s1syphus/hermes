
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

void TicTacToe::testAlpha(){

	int* newBoard = new int[9];

/*
	newBoard[0] = 1;
	newBoard[1] = 2;
	newBoard[2] = 0;

	newBoard[3] = 0;
	newBoard[4] = 0;
	newBoard[5] = 2;

	newBoard[6] = 0;
	newBoard[7] = 1;
	newBoard[8] = 1;

	tBoard* myBoard = new tBoard(newBoard, 0, 1);

	printBoard(myBoard);	
	cout<<endl;
	if(gameOver(myBoard)){
		cout<<"game over\n";
		}
	else{
		cout<<"not over\n";
		}

*/
	

	newBoard[0] = 1;
	newBoard[1] = 2;
	newBoard[2] = 0;

	newBoard[3] = 0;
	newBoard[4] = 2;
	newBoard[5] = 2;

	newBoard[6] = 0;
	newBoard[7] = 1;
	newBoard[8] = 1;
	//printBoard();

	//fix this at some point, kind of hacky
	tBoard* myBoard = new tBoard(newBoard, 0, 0);
	printBoard(myBoard);
	int* blankBoard = new int[9];

	for(int i = 0; i < 9; i++){
		blankBoard[i] = 2;
		}

	tBoard* mehBoard = new tBoard(blankBoard, 0, 0);
	genMoves(mehBoard);


/*
	tBoard* alpha = new tBoard(blankBoard, INT_MIN, 0);
	tBoard* beta = new tBoard(blankBoard, INT_MAX, 0);

	cout<<"here\n";	
	myBoard = alphaBeta(myBoard, 3, alpha, beta, 0);
	
	cout<<"Best move:\n";
	printBoard(myBoard);
*/
	}

void TicTacToe::genMoves(tBoard* myBoard){

	//this generates and prints out all moves, this will be used in alphabeta

	tBoard* tempBoard;
	stack<tBoard*> allBoards;
	allBoards.push(myBoard);
	double counter = 0;
	while(!allBoards.empty()){
		tempBoard = allBoards.top();
		allBoards.pop();
		if(!gameOver(tempBoard)){
			for(int i = 0; i < 9; i++){
				if(moveValid(tempBoard, i)){
					cout<<counter<<endl;
					counter++;
					allBoards.push(makeMove(tempBoard,i));
					}
				}
			}
		}
	}


bool TicTacToe::moveValid(tBoard* myBoard, int move){
	if(move < 0){
		return false;
		}
	if(move > 8){
		return false;
		}
	if(myBoard->getBoard()[move] != 2){
		return false;
		}	
	return true;
	}

void TicTacToe::printBoard(){
	int* myBoard = board->getBoard();
	cout<<player[myBoard[0]]<<" | "<<player[myBoard[1]]<<" | "<<player[myBoard[2]]<<"\n"<<
	player[myBoard[3]]<<" | "<<player[myBoard[4]]<<" | "<<player[myBoard[5]]<<"\n"<<
	player[myBoard[6]]<<" | "<<player[myBoard[7]]<<" | "<<player[myBoard[8]]<<"\n\n";
	
	}

void TicTacToe::printBoard(tBoard* curBoard){

	int* myBoard = curBoard->getBoard();

	cout<<player[myBoard[0]]<<" | "<<player[myBoard[1]]<<" | "<<player[myBoard[2]]<<"\n"<<
	player[myBoard[3]]<<" | "<<player[myBoard[4]]<<" | "<<player[myBoard[5]]<<"\n"<<
	player[myBoard[6]]<<" | "<<player[myBoard[7]]<<" | "<<player[myBoard[8]]<<"\n";

	}


tBoard* TicTacToe::getCurBoard(){
	return board;
	}

bool TicTacToe::gameOver(tBoard* myGameBoard){

	bool over = true;
	int* board = myGameBoard->getBoard();

	for(int side = 0; side < 2; side++){
		//check columns
		
		for(int i = 0; i < 3; i++){
			over = true;
			for(int j = i; j< 9; j += 3){
				if(board[j] != side){
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
				if(board[j] != side){
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
			if(board[i] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}

		//other diagonal	
		over = true;
		for(int i = 2; i < 7; i+=2){
			if(board[i] != side){
				over = false;		
				}
			}
		if(over){
			return over;
			}
		}	

	return false;

	}

tBoard* TicTacToe::alphaBeta(tBoard* myBoard, int depth, tBoard* alpha, tBoard* beta, int side ){

	cout<<"depth: "<<depth<<"\n";

	cout<<"current board:\n";
	printBoard(myBoard);
	cout<<"\n";

	tBoard* tempBoard = new tBoard(myBoard->getBoard(), myBoard->getValue(), myBoard->getSide());

	tBoard* v = new tBoard(myBoard->getBoard(), myBoard->getValue(), myBoard->getSide());
	
	if(depth == 0){
		return myBoard;
		}	
	if(gameOver(myBoard)){
		if(myBoard->getSide() == 0){
			tempBoard->setValue(10);
			}
		else{
			tempBoard->setValue(-10);
			}
		return tempBoard;
		}
	if(side == 0){
		v->setValue(INT_MIN);
		for(int i = 0; i < 9; i++){
			if(moveValid(myBoard, i)){
				//child node
				tempBoard = makeMove(myBoard, i);
				v = maxBoard(v,alphaBeta(tempBoard, depth -1, alpha, beta, side^1));
				alpha = maxBoard(alpha, v);
				if(beta <= alpha){
					break;
					}	
				}
			}
		}
	else{
		v->setValue(INT_MAX);
		for(int i = 0; i < 9; i++){
			if(moveValid(myBoard, i)){
				//child node
				tempBoard = makeMove(myBoard, i);
				v = minBoard(v,alphaBeta(tempBoard, depth -1, alpha, beta, side^1));
				beta = minBoard(alpha, v);
				if(beta <= alpha){
					break;
					}
				}
			}
		}

		return v;

	}





bool TicTacToe::gameOver(tBoard* myGameBoard, int move,int side){

	
	bool over = true;
	int n = 3; // size of board, this function will be reused for connect4
	int start = move;

	//this is for rows	
	start = move - (move %3);
	int* myBoard = myGameBoard->getBoard();

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



tBoard* TicTacToe::maxBoard(tBoard* first, tBoard* second){
	tBoard* maximum;
	if(first->getValue() >= second->getValue()){
		maximum	= new tBoard(first->getBoard(), first->getValue(), first->getSide());
		}
	else{
		maximum = new tBoard(second->getBoard(), second->getValue(), second->getSide());
		}	
	return maximum;
	}

tBoard* TicTacToe::minBoard(tBoard* first, tBoard* second){
	tBoard* minimum;
	if(first->getValue() <= second->getValue()){
		minimum = new tBoard(first->getBoard(), first->getValue(), first->getSide());
		}
	else{
		minimum = new tBoard(second->getBoard(), second->getValue(), second->getSide());
		}	
	return minimum;
	}

