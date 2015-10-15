#include<iostream>
#include"avl-tree.h"
using namespace std;

int main(void){
	cout << "This is an avl tree" << endl;
	AvlTree* tree = new AvlTree();
	cout << "please enter the node and -1 means find and -2 means delete :\n";
	int data;
	while (true){
		cin >> data;
		if (data == -1){
			//test tree
			cin >> data;
			if(tree->nodeFind(tree->root, data)){
				cout << "find " << data << " succeed!\n"; 
			}else{
				cout << "find " << data << " fail!\n";
			}
			continue;
		}
		if (data == -2){
			cin >> data;
			if (tree -> nodeDelete(tree->root , data)){
				cout << "delete succeed\n";
			}else{
				cout << "delete fail\n";
			}
			tree->nodePrint(tree->root, 0, tree->root->data);
			continue;
		}
		tree->nodeInsert(tree->root, data);
		cout << "insert over\n";
		tree->nodePrint(tree->root, 0, tree->root->data);
	}
	return 0;
}