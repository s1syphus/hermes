
//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}

void Game::testAlphaBeta(){


	TicTacToe myGame;
	myGame.testAlpha();


	}




void Game::playTicTacToe(){

	TicTacToe myGame;
	int move;
	int side = 0; //default, can change later I suppose
	bool gameOver = false;
	myGame.printInstructions();
	char player[2] = { 'X', 'O'};

	while(!gameOver){
		cout<<"Player "<<player[side]<<" select square> ";
		cin>>move;			
		cout<<endl;		

		myGame.printBoard();
		cout<<endl;
		side ^= 1;	// switches side, love dem bit operations

		}

		cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";
	
	}


