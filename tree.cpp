#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;


tree::tree(){
	head = NULL;
}

tree::~tree(){
	while (head != NULL){
		deletemin(head);
	}
}

void tree::insert(double x, node *&L){
	if (L == NULL){ 
		L = new node;
		L->data = x;
		L->leftchd = NULL;
		L->rightchd = NULL;
	}
	else{
		if (L->data == x){ //not Null and already in tree
			cout << "Already in tree \n";
		}
		else{
			if (L->data > x){
				insert(x, L->leftchd);
			}
			else{
				insert(x, L->rightchd);
			}
		}
	}

}

void tree::remove(double x){
	node * check = search(x, head);
	node * temp = check;
	if (check == NULL){
		cout << "Number not in list \n";
	}
	else {
		if ((check->leftchd == NULL) && (check->rightchd == NULL)){
			delete check;
		}
		else if ((check->leftchd == NULL) && (check->rightchd != NULL)){
			temp = check->rightchd;
			delete check;
			check = temp;
		}
		else if ((check->leftchd != NULL) && (check->rightchd == NULL)){
			temp = check->leftchd;
			delete check;
			check = temp;
		}
		else if ((check->leftchd != NULL) && (check->rightchd != NULL)){
			minSwitch(check);
		}
	}
}

void tree::minSwitch( node *&L ){
	node * temp = L;
	while (temp->leftchd != NULL){
		temp = temp->leftchd;
	}
	double item = temp->data;
	delete temp;
	L->data = item;
}

node*& tree::search(double x, node *&L){
		if (L->data == x){
			return L;
		}
		else{
			if (L == NULL){
				return L;
			}
			else{
				if (L->data > x){
					search(x, L->leftchd);
				}
				else{
					search(x, L->rightchd);
				}

			}
		}
	
}


void tree::deletemin(node *&L){
	if (L == NULL){
		cout << "Nothing to delete";
	}
	else{
		if (L->leftchd == NULL){
			remove(L->data);
		}
		else{
			deletemin(L->leftchd);
		}
	}
}


void tree::deletemax(node *&L){
	if (L == NULL){
		cout << "Nothing to delete";
	}
	else{
		if (L->rightchd == NULL){
			remove(L->data);
		}
		else{
			deletemax(L->rightchd);
		}
	}
}


void tree::preorder(node *&L){
	if (L == NULL){

	}
	else{
		cout << L->data << " ";
		//if (L->leftchd != NULL){
			preorder(L->leftchd);
		//}
		//else{
		//	if (L->rightchd != NULL){
				preorder(L->rightchd);
			//}
		}
	}
//}


void tree::inorder(node *&L){

}


void tree::levelorder(node *&L){

}

node*& tree::getHead(){
	return head;
}

void tree::build(ifstream& file){
	double item;
	while (file >> item){//read from file and add each number to head
		insert(item, head);
	}
}