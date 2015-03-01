#ifndef	QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct nodeQ{
	double data;
	nodeQ *next;
};


class queue{
private:
	nodeQ *head;
	bool flag;

public:
	queue();
	~queue();
	void insert(double x, nodeQ *&L);
	bool isEmpty();
	void pop();
	void peek();
	//nodeQ*& find(double x, nodeQ *&L);
	//void build(ifstream& file);
	nodeQ*& getHead();
};


#endif