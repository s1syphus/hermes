
//alphabeta.h

#ifndef ALPHABETA_H
#define ALPHABETA_H

#include "limits.h"
#include <vector>

//get rid of this later
#include <iostream>
using namespace std;

#define MAX_DEPTH 4


class Node{

	private:

		int value;
		Node* parent;
		vector<Node*> children;
		//int, or something move
		
	public:

		Node();
		Node(Node*, int);
		
		//Accessors
		int getValue();
		Node* getParent();
		Node* getChild();
		void updateChildren(Node*);
		void setValue(int);
		//return move
	};



class AlphaBeta{

	private:
		Node* root;
	public:
		AlphaBeta();
		int runAlphaBeta(Node*, int, int, int, int);			
		void addMove(Node*, int, int);
		int max(int, int);
		int min(int, int);
		void alphaBetaTest();	
		};







#endif
