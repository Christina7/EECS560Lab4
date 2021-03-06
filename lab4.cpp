#include <iostream>
#include "tree.h"
using namespace std;

int main(){

	tree l;
	ifstream fileName;
	fileName.open("C:\\Users\\Christina\\Documents\\GitHub\\678EECS\\EECS560Lab4\\data.txt");
	//fileName.open("data.txt");
	l.build(fileName);


	int input;
	double x;

	while (1){
		cout << "Please choose one of the following commands: \n 1 - insert \n 2 - delete \n 3 - deletemin \n 4 - deletemax \n 5 - preorder \n 6 - inorder \n 7 - levelorder \n 8 - exit \n";
		cin >> input;

		switch (input) {
		case 1:
			cout << "Please insert the number that you want to be inserted in the tree \n";
			cin >> x;
			l.insert(x, l.getHead());
			break;
		case 2:
			cout << "Which number do you like to remove from the tree? \n";
			cin >> x;
			l.remove(x);
			break;
		case 3:
			l.deletemin(l.getHead());
			break;
		case 4:
			l.deletemax(l.getHead());
			break;
		case 5:
			cout << "preorder: ";
			l.preorder(l.getHead());
			cout << endl;
			break;
		case 6:
			cout << "inorder: ";
			l.inorder(l.getHead());
			cout << endl;
			break;
		case 7:
			cout << "levelorder: ";
			l.levelorder(l.getHead());
			cout << endl;
			break;
		case 8:
			fileName.close();
			exit(0);
			break;
		default:
			cout << "Option not available try again \n";

		}
	}

}