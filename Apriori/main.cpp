#include<iostream>
#include"avl-tree.h"
using namespace std;

int main(void){
	cout << "This is an avl tree" << endl;
	AvlTree* tree = new AvlTree();
	cout << "please enter the node :\n";
	int data;
	while (true){
		cin >> data;
		tree->nodeInsert(tree->root, data);
		cout << "insert over\n";
		tree->nodePrint(tree->root, 0, tree->root->data);
	}
	return 0;
}
