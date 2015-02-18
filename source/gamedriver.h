//gamedriver.h

/*
	This is just a driver class to select which game
	to play, shouldn't do much else

*/


#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

//for debug, remove later, maybe guard?

#include <iostream> //for debug
using namespace std;

#include "tictactoe.h"
#include "connect4.h"

class Game{

	private:
		TicTacToe ticTacToeGame;
		Connect4 connect4Game;
		//other games	
	public:
		//constructors
		Game();
		//Game(enum Game); // fix this
		void playTicTacToe(int);
		void playConnect4(int);
	};


#endif







