#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "queue.h"

using namespace std;



class tree{
private:
node *head;
//bool flag;

public:
tree();
~tree(); 

void insert(double x, node *&L); 
void remove(double x); 
void minSwitch(node *&L );
node*& search(double x, node *&L);
void deletemin( node *&L);
void deletemax( node *&L);
void preorder(node *&L); 
void inorder(node *&L); 
void levelorder(node *&L);
node*& getHead();
void build(ifstream& file);

};


#endif
