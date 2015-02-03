
//alphabeta.cpp

#include "alphabeta.h"

Node::Node(){
	}

Node::Node(Node* parent, int value){
	parent = parent;
	value = value;
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

AlphaBeta::AlphaBeta(){
	//default constructor
	}

int AlphaBeta::max(int first, int second){
	if(first >= second){
		return first;
		}
	else{
		return second;
		}	
	}

int AlphaBeta::min(int first, int second){
	if(first <= second){
		return first;
		}
	else{
		return second;
		}	

	}

void Node::updateChildren(Node* child){
	children.push_back(child);
	}


void AlphaBeta::alphaBetaTest(){
	
	Node* root = new Node(NULL, 0);

	addMove(root, 0, 0);

	cout<<"here\n";	
	runAlphaBeta(root, 4, INT_MIN, INT_MAX, 0);	
	
	}




void AlphaBeta::addMove(Node* prevMove, int curMoveValue, int depth){

	Node* curNode = new Node(prevMove, curMoveValue);
	int numChildren;
	int value = 0;

	while(depth < MAX_DEPTH and numChildren != 0){
		cout<<"Enter number of children >";
		cin>>numChildren;
		addMove(curNode, value, depth + 1);
		numChildren--;
		}
	cout<<"Enter value >";
	cin>>value;
	curNode->setValue(value);
	prevMove->updateChildren(curNode);

	
	}

int AlphaBeta::runAlphaBeta(Node* node, int depth, int alpha, int beta, int side){

	int v;
	int numChildren = 1;

	if(depth == 0){
		return node->getValue();
		}

		if(side == 0){
		//maximizing player
		v = INT_MIN;
		for(int i = 0; i < numChildren; i++){
			v = max(v, runAlphaBeta(node->getChild(), 
					depth - 1, alpha, beta, side^1));
			alpha = max(alpha, v);
			if(beta <= alpha){
				break;
				}
			}	
		}		
	else{
		v = INT_MAX;
		for(int i = 0; i < numChildren; i++){
			v = min(v, runAlphaBeta(node->getChild(), 
					depth - 1, alpha, beta, side^1));
			alpha = min(alpha, v);
			if(beta <= alpha){
				break;
				}
			}
		}

		return v;	
	}




