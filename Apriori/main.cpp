#include<iostream>
#include"avlTree.h"
using namespace std;

int main(void){
	cout << "This is an avl tree" << endl;
	avlTree tree;
	int tmp = 0;
	while (1){
		cout << "please enter intergers : ";
		cin >> tmp;
		if (tmp == -1){
			break;
		}
		tree.add(tmp);
		tree.showAll();
	}
	cout << "here id the tree :" << endl;
	tree.showAll();
	return 0;
}
