
//gamedriver.h

#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

#include <iostream> //for debug
using namespace std;



#include "tictactoe.h"
//other games soon

#include "alphabeta.h"


class Game{

	private:
		TicTacToe ticTacToeGame;
//		aiPlayer readyPlayerOne; //handle this soon
		//other games	
	public:
		//constructors
		Game();
		//Game(enum Game); // fix this
		void playTicTacToe();

	};






#endif





