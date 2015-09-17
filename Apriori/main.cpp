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
		if (data == -1){
			cin >> data;
			if(tree->nodeFind(tree->root, data)){
				cout << "find " << data << " succeed!\n"; 
			}else{
				cout << "find " << data << " fail!\n";
			}
			continue;
		}
		tree->nodeInsert(tree->root, data);
		cout << "insert over\n";
		tree->nodePrint(tree->root, 0, tree->root->data);
	}
	return 0;
}
