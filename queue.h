#ifndef	QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct node{
	double data;
	node *next;
};


class queue{
private:
	node *head;
	bool flag;

public:
	queue();
	~queue();
	void insert(double x, node *&L);
	bool isEmpty();
	void pop();
	void peek();
	//node*& find(double x, node *&L);
	//void build(ifstream& file);
	node*& getHead();
};


#endif