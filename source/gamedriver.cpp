//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}

void Game::playConnect4(){

	Connect4 myGame;
	myGame.printCurBoard();
	int side = 0, move;
	char player[2] = { 'X', 'O'};

	cout<<"Select a column [0-6] > ";
	cin>>move;	
	
	if(myGame.moveValid(move)){
		myGame.makeMove(move);
		}

	myGame.printCurBoard();

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
	int counter = 0;
	while((!gameOver) && (counter <= 8)){
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
		counter++;
		}
	if(gameOver){
		cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";
		}
	else{
		cout<<"Game is a draw\n";
		}


	}


