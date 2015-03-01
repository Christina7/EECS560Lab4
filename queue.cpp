#include <iostream>
#include "queue.h"
using namespace std;

queue::queue(){
	head = NULL;
	flag = false;
}

queue::~queue(){
	node *temp = head;
	while (temp != NULL){
		node *temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = NULL;
	temp = NULL;
}

//adds node to end of queue if it is not already in the queue
void queue::insert(double x, node *&L){
	if (L == NULL){	//if current node is NULL adds new node with data
		L = new node;
		L->data = x;
		L->next = NULL;
	}
	else{
		if (L->data == x){	//if current node is not null and is the number being inserted 
			cout << "Number already in queue \n";
		}
		else{	//if current node is not null, last node with data, and not number being inserted, then adds new node with data
			if (L->next == NULL){
				L->next = new node;
				L->next->next = NULL;
				L->next->data = x;
			}
			else{	// current node is not last node and does not contain the number being inserted, then move on to next node recursively
				insert(x, L->next);
			}
		}
	}
}

//checks if queue is empty
bool queue::isEmpty(){
	if (head == NULL){
		return true;
	}
	else{
		return false;
	}
}

//removes node from queue if there
void queue::pop(){
	if (head == NULL){
		cout << "Number not in queue \n";
	}
	else{
		node *temp = head->next;
		delete head;
		head = temp;
		
	}

}

//prints current head
void queue::peek(){
	if (head == NULL){
		cout << "Empty queue \n";
	}
	else{
		cout << head->data << endl;	//print last node
	}
}

node*& queue::getHead(){
	return head;
}