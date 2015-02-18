//gamedriver.cpp

#include "gamedriver.h"

Game::Game(){
	//default constrctor...make default game?

	}

void Game::playConnect4(int selection){

	Connect4 myGame;
	int side = 0, move = 0;
	char player[2] = { 'X', 'O'};
	// timer stuff
	clock_t t;
	int depth = 1;

	//do stuff with selection

	while(!myGame.gameOver()){
		if(side == 1){
			cout<<"Select a column [0-6] > ";
			cin>>move;	
			if(!myGame.moveValid(move)){
				cout<<"move is invalid, try again\n";
				}
			}
		else{
//			cout<<"depth > ";
//			cin>>depth;
//			depth = 7;
			t = clock();
			move = myGame.bestMove(depth);
			t = clock() - t;
			printf("Move took: %f seconds\n",((float) t)/CLOCKS_PER_SEC);

			}
		myGame.makeMove(move);
		myGame.printCurBoard();
		side ^= 1;
		}

	//for debug

	


	cout<<"Game over!\nPlayer: "<<player[side^1]<<" is the winner!\n";

	}


void Game::playTicTacToe(int selection){

	TicTacToe myGame;
	int move;
	int side = 0; //default, can change later I suppose
	char player[2] = { 'X', 'O'};
	myGame.printCurBoard();
	myGame.printInstructions();
	bool gameOver = false;

	if(selection == 2){

		/*	
		Two player works!
		*/

		while(!gameOver){
			cout<<"Player "<<player[side]<<" select square> ";
			cin>>move;			
			cout<<endl;		
			if(myGame.moveValid(move)){
				myGame.makeMove(move);
				gameOver = myGame.gameOver();
				}
			myGame.printCurBoard();
			side ^= 1;
			}
		cout<<"Game is over!\nSide: "<<(side^1)<<" is the winner!\n";
	}

	else{
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
//				cout<<"move = "<<move<<endl;
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

	}


