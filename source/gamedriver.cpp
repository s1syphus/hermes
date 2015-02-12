//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}



void Game::playTicTacToe(){

	TicTacToe myGame;
	int move;
	int side = 0; //default, can change later I suppose
	char player[2] = { 'X', 'O'};
	myGame.printCurBoard();
	myGame.printInstructions();
	bool gameOver = false;

	/*	
	Two player works!
	*/
/*
	while(!gameOver){
		cout<<"Player "<<player[side]<<" select square> ";
		cin>>move;			
		cout<<endl;		
		if(myGame.moveValid(move)){
			myGame.makeMove(move);
			gameOver = myGame.gameOver();
			}
		myGame.printCurBoard();
		side ^= 1;	// switches side, love dem bit operations
		}
	cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";
	*/	
	/*
	One player
	*/
	while(!gameOver){
		if(side == 1){
			cout<<"Player "<<player[side]<<" select square> ";
			cin>>move;			
			cout<<endl;		
			}
		else{
			cout<<"CPU is playing\n";
			move = myGame.bestMove();
			cout<<"move = "<<move<<endl;
			}
		if(myGame.moveValid(move)){
			myGame.makeMove(move);
			gameOver = myGame.gameOver();
			myGame.printCurBoard();
			side ^= 1;
			}
		else{
			cout<<"bad move\n";
			}
		}
	cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";

	}


