
//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}

void Game::playTicTacToe(){

	cout<<"about to start playing tic-tac-toe\n";
	
	TicTacToe myGame;
	int selection;
	int side = 0; //default, can change later I suppose

	myGame.printInstructions();

	while(!myGame.gameOver()){

		cout<<"Player "<<side<<" select square> ";
		cin>>selection;			
		cout<<endl;
		if(myGame.moveValid(selection)){
			myGame.makeMove(selection,side);			}
		else{
			cout<<"learn how to type/follow directions...\n";
			}
		myGame.printBoard();
		cout<<endl;
		side ^= 1;	// switches side, love dem bit operations
		}

	
	}


