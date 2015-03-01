#include <iostream>
#include "tree.h"
using namespace std;

int main(){

	tree l;
	//ifstream fileName;
	//fileName.open("C:\\Users\\Christina\\Documents\\Visual Studio 2013\\Projects\\eecs560Lab2\\Debug\\data.txt");
	//fileName.open("data.txt");
	//l.build(fileName);



	int input;
	double x;

	while (1){
		cout << "Please choose one of the following commands: \n 1 - insert \n 2 - delete \n 3 - print \n 4 - exit \n";
		cin >> input;

		switch (input) {
		case 1:
			cin >> x;
			l.insert(x, l.getHead());
			break;
		case 2:
			//cin >> x;
			//l.remove(x);
			break;
		case 3:
			//l.print();
			break;
		case 4:
			//fileName.close();
			exit(0);
			break;
		default:
			cout << "Option not available try again \n";

		}
	}

}