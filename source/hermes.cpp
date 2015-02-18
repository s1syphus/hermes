//hermes.cpp

#include "gamedriver.h"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){


	Game game;
	int selection;
	cout<<"Welcome to Hermes!\nSelect Game Below:\n1) TicTacToe\n2) Connect 4\n3) Chess (not working yet)\n> ";
	cin>>selection;
		
	switch(selection){
		case 1:	{
			cout<<"You have selected TicTacToe\nSelect Game Mode:\n1) One Player\n2) Two Player\n> ";
			cin>>selection;
			game.playTicTacToe(selection);
			break;
			}
		case 2:	{
			cout<<"You have selected Connect 4 (still in development)\nSelect Game Mode:\n1) One Player\n2) Two Player\n> ";
			cin>>selection;
			game.playConnect4(selection);
			break;
			}
		case 3: {
			cout<<"You have selected Chess, sadly this is not working yet =(\n";
			break;
			}
		default:
			break;
		}

	return 0;

	}



