#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;

//constructor
tree::tree(){
	head = NULL;
}

//destructor
tree::~tree(){
	while (head != NULL){
		deletemin(head);
	}
}

//adds element to tree if not there
void tree::insert(double x, node *&L){
	if (L == NULL){  //empty tree
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
			if (L->data > x){	//not null and not in tree
				insert(x, L->leftchd);
			}
			else{
				insert(x, L->rightchd);
			}
		}
	}

}

//remove node from list if there
void tree::remove(double x){
	node * check = search(x, head); //finds node
	node * temp = check;
	if (check == NULL){ //not in tree
		cout << x <<" not in tree \n";
	}
	else {
		if (check->data == x){	//root is being removed
			if ((check->leftchd == NULL) && (check->rightchd == NULL)){ //no kids
				delete head;
				head = NULL;
			}
			else if ((check->leftchd == NULL) && (check->rightchd != NULL)){// right kid only
				temp = head->rightchd;
				delete head;
				head = temp;
			}
			else if ((check->leftchd != NULL) && (check->rightchd == NULL)){ // left kid only
				temp = head->leftchd;
				delete head;
				head = temp;
			}
			else if ((check->leftchd != NULL) && (check->rightchd != NULL)){ //both kids
				minSwitch(head);
			}
		}
		else{
			if ((check->leftchd != NULL) && (check->leftchd->data == x)){ //is left child checks for children and removes appropriately
				if ((check->leftchd->leftchd == NULL) && (check->leftchd->rightchd == NULL)){
					delete check->leftchd;
					check->leftchd = NULL;
				}
				else if ((check->leftchd->leftchd == NULL) && (check->leftchd->rightchd != NULL)){
					temp = check->leftchd->rightchd;
					delete check->leftchd;
					check->leftchd = temp;
				}
				else if ((check->leftchd->leftchd != NULL) && (check->leftchd->rightchd == NULL)){
					temp = check->leftchd->leftchd;
					delete check->leftchd;
					check->leftchd = temp;
				}
				else if ((check->leftchd->leftchd != NULL) && (check->leftchd->rightchd != NULL)){
					minSwitch(check->leftchd);
				}
			}
			if ((check->rightchd != NULL) && (check->rightchd->data == x)){ //is right child  checks for children and removes appropriately
				if ((check->rightchd->leftchd == NULL) && (check->rightchd->rightchd == NULL)){
					delete check->rightchd;
					check->rightchd = NULL;
				}
				else if ((check->rightchd->leftchd == NULL) && (check->rightchd->rightchd != NULL)){
					temp = check->rightchd->rightchd;
					delete check->rightchd;
					check->rightchd = temp;
				}
				else if ((check->rightchd->leftchd != NULL) && (check->rightchd->rightchd == NULL)){
					temp = check->rightchd->leftchd;
					delete check->rightchd;
					check->rightchd = temp;
				}
				else if ((check->rightchd->leftchd != NULL) && (check->rightchd->rightchd != NULL)){
					minSwitch(check->rightchd);
				}
			}
		}

	}
}

//method for remove when a node has both children. finds min, grabs data, removes min and sets node to min's data
void tree::minSwitch( node *&L ){
	node * temp = L->rightchd;
	while (temp->leftchd != NULL){
		temp = temp->leftchd;
	}
	double item = temp->data;
	remove(temp->data);
	L->data = item;
}

//finds node if there returns parent of node unless root
node*& tree::search(double x, node *&L){
	if (L == NULL){
		return L;
	}
	else{
		if (L->data == x){
			return L;
		}
		else{
			if ((L->leftchd != NULL) && (L->leftchd->data == x)){
				return L;
			}
			else {
				if ((L->rightchd != NULL) && (L->rightchd->data == x)){
					return L;
				}
				else{
					if (L->data > x){
						search(x, L->leftchd);
					}
					else{
						if (L->data <= x){
							search(x, L->rightchd);
						}
					}
				}
			}
		}
	}
}
	


//removes minimum node
void tree::deletemin(node *&L){
	if (L == NULL){
		cout << "Nothing to delete \n";
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

//removes max node
void tree::deletemax(node *&L){
	if (L == NULL){
		cout << "Nothing to delete \n";
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

//lists elements in preorder
void tree::preorder(node *&L){
	if (L == NULL){

	}
	else{
		cout << L->data << " ";
		preorder(L->leftchd);
		preorder(L->rightchd);
	}
}

//lists elements in inorder
void tree::inorder(node *&L){
	if (L == NULL){

	}
	else{
		inorder(L->leftchd);
		cout << L->data << " ";
		inorder(L->rightchd);
	}
}

//lists elements in levelorder
void tree::levelorder(node *&L){
	queue q;
	if (L == NULL){
		//cout << "Empty tree";
	}
	else{
		q.insert(L, q.getHead());

		while (!q.isEmpty()){
			cout << q.peek()->data->data << " ";
			q.pop();
			if (L->leftchd != NULL){
				q.insert(L->leftchd, q.getHead());
			}
			if (L->rightchd != NULL){
				q.insert(L->rightchd, q.getHead());
			}
			if (q.peek() != NULL){
				L = q.peek()->data;
			}
		}
	}
}

//gets root
node*& tree::getHead(){
	return head;
}

//builds initial tree
void tree::build(ifstream& file){
	double item;
	while (file >> item){//read from file and add each number to head
		insert(item, head);
	}
}