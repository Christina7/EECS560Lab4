#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "queue.h"

using namespace std;

struct node{
double data;
node *leftchd;
node *rightchd;
};


class tree{
private:
node *head;
//bool flag;

public:
tree();
~tree(); 

void insert(double x, node *&L); //should insert x in the BST. 

void remove(double x); //should delete x from the BST. For consistency when removing a data that has two children, use the smallest data in the right subtree of the data that should be removed in order to replace the removed data. 

void minSwitch(node *&L );

node*& search(double x, node *&L); //should find x in the BST and return a pointer to it, NULL if not found. 

void deletemin( node *&L); //should delete the smallest value from the BST.

void deletemax( node *&L); //should delete the largest value from the BST. 

void preorder(node *&L); //should print out all the elements of the BST using preorder traversal. 

void inorder(node *&L); //should print out all the elements of the BST using inorder traversal. (sort) 

void levelorder(node *&L); //should print out all the elements of the BST using levelorder traversal.

node*& getHead();

void build(ifstream& file);

};


#endif
