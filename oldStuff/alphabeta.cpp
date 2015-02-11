
//alphabeta.cpp

#include "alphabeta.h"

/*
Node::Node(){
	}

Node::Node(Node* parent, Board* board, int value, int side){
	parent = parent;
	value = value;
	}

tBoard* Node::getBoard(){
	return board;
	}


int Node::getValue(){
	return value;
	}
Node* Node::getChild(){
	Node* child = children.back();
	children.pop_back(); 
	return child;
	}

Node* Node::getParent(){
	return this->parent;
	}

void Node::setValue(int newValue){
	value = newValue;
	}

*/

AlphaBeta::AlphaBeta(){
	//default constructor
	}
/*
tBoard* AlphaBeta::maxBoard(tBoard* first, tBoard* second){
	tBoard* maximum;
	if(first->getValue() >= second->getValue()){
		maximum	= new tBoard(first->getBoard(), first->getValue(), first->getSide());
		}
	else{
		maximum = new tBoard(second->getBoard(), second->getValue(), second->getSide());
		}	
	return maximum;
	}

tBoard* AlphaBeta::minBoard(tBoard* first, tBoard* second){
	tBoard* minimum;
	if(first->getValue() <= second->getValue()){
		minimum = new tBoard(first->getBoard(), first->getValue(), first->getSide());
		}
	else{
		minimum = new tBoard(second->getBoard(), second->getValue(), second->getSide());
		}	
	return minimum;
	}
void Node::updateChildren(Node* child){
	children.push_back(child);
	}


tBoard* AlphaBeta::alphaBetaFunction(tBoard* myBoard, int depth, tBoard* alpha, tBoard* beta, int side ){

	tBoard* tempBoard = new tBoard(myBoard->getBoard(), myBoard->getValue(), myBoard->getSide());

	tBoard* v;
	if(depth == 0 or gameOver(myBoard)){
		return myBoard;
		}	
	if(side == 0){
		v->setValue(INT_MIN);
		for(int i = 0; i < 9; i++){
			if(moveValid(myBoard, i)){
				//child node
				tempBoard = makeMove(myBoard, i);
				v = maxBoard(v,alphaBetaFunction(tempBoard, depth -1, alpha, beta, side^1));
				alpha = maxBoard(alpha, v);
				if(beta <= alpha){
					break;
					}	
				}
			}
		}
	else{
		v->setValue(INT_MAX);
		for(int i = 0; i < 9; i++){
			if(moveValid(myBoard, i)){
				//child node
				tempBoard = makeMove(myBoard, i);
				v = minBoard(v,alphaBetaFunction(tempBoard, depth -1, alpha, beta, side^1));
				beta = minBoard(alpha, v);
				if(beta <= alpha){
					break;
					}
				}
			}
		}

		return v;

	}

void AlphaBeta::alphaBetaTest(){
	
	Node* root = new Node(NULL, 0);

	cout<<"building the tree\n";
	//addMove(root, 0, 0);

	cout<<"here\n";	
	runAlphaBeta(root, 4, INT_MIN, INT_MAX, 0);	
	
	}
*/
