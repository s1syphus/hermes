
//alphabeta.h

#ifndef ALPHABETA_H
#define ALPHABETA_H

#include "limits.h"
#include <vector>

//get rid of this later
#include <iostream>
#include "boards.h"
using namespace std;

#define MAX_DEPTH 4


/*
class Node{

	private:

		int value;
		Node* parent;
		vector<Node*> children;
		int side;
		//will overload board structure later	
		tBoard *board;
	public:

		Node();
		Node(Node*, tBoard*, int, int);
		
		//Accessors
		int getValue();
		Node* getParent();
		Node* getChild();
		void updateChildren(Node*);
		void setValue(int);
		tBoard* getBoard();
		//return move
	};

*/

class AlphaBeta{

	private:
//		Node* root;
		tBoard *board;
	public:
		AlphaBeta();
//		tBoard* alphaBetaFunction(tBoard*, int, tBoard*, tBoard*, int);
//		void addMove(Node*, int, int);
//		tBoard* maxBoard(tBoard*, tBoard*);
//		tBoard* minBoard(tBoard*, tBoard*);
//		void alphaBetaTest();	

		};





#endif
