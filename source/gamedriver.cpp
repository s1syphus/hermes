
//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}

void Game::testAlphaBeta(){

	cout<<"this is to test alpha beta\n";

	AlphaBeta myTree;

	}




void Game::playTicTacToe(){

	TicTacToe myGame;
	int move;
	int side = 0; //default, can change later I suppose
	bool gameOver = false;
	myGame.printInstructions();
	char player[2] = { 'X', 'O'};

	while(!gameOver){
		if(side == 0){
			cout<<"Player "<<player[side]<<" select square> ";
			cin>>move;			
			cout<<endl;		
			}
		else{
			//generate moves, will also add in a 'pick best'
			
			}	

	
		if(myGame.moveValid(move)){
			myGame.makeMove(move,side);
			gameOver = myGame.gameOver(move,side);
			}
		else{
			cout<<"learn how to type/follow directions...\n";
			}

		myGame.printBoard();
		cout<<endl;
		side ^= 1;	// switches side, love dem bit operations

		}

		cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";
	
	}


