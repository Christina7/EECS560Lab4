#ifndef	QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;



struct node{	//may need to put back in tree.h
	double data;
	node *leftchd;
	node *rightchd;
};


struct nodeQ{
	node *data;
	nodeQ *next;
};


class queue{
private:
	nodeQ *head;
	bool flag;

public:
	queue();
	~queue();
	void insert(node *&x, nodeQ *&L);
	bool isEmpty();
	void pop();
	nodeQ *& peek();
	nodeQ*& getHead();
};


#endif