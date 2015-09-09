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
	cout << "here is the tree :" << endl;
	tree.showAll();
	while(true){
		cout << "please enter the number that you what to find and enter 0 to halt:\n";
		cin >> tmp;
		if (tmp == 0){
			break;
		}
		if (tree.findNode(tmp)){
			cout << "find the node!\n";
		}else{
			cout << "not find the node!\n";
		}
	}
	return 0;
}
