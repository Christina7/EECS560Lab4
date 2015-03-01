#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;


tree::tree(){
	head = NULL;
}

tree::~tree(){
	while (head != NULL){
		deletemin();
	}
}

void tree::insert(double x, node *&L){
	if (L == NULL){ 
		L = new node;
		L->data = x;
		L->leftchd = NULL;
		L->rightchd = NULL;
		cout << x;
	}
	else{
		if (L->data == x){ //not Null and already in tree
			cout << "Already in tree \n";
		}
		else{
			if (L->data > x){
				insert(x, L->leftchd);
				cout << " left " << x;
			}
			else{
				insert(x, L->rightchd);
				cout << " right " << x;
			}
		}
	}

}

void tree::remove(double x){

}


node*& tree::search(double x){
	return head;
}


void tree::deletemin(){

}


void tree::deletemax(){

}


void tree::preorder(){

}


void tree::inorder(){

}


void tree::levelorder(){

}

node*& tree::getHead(){
	return head;
}