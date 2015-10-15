#include <iostream>
using namespace std;

#define MAX(num1 , num2) ((num1 > num2) ? (num1) : (num2))

class Node{
public:
	Node* left;
	Node* right;
	int height;
	int data;
	Node(Node* left , Node* right , int data);
};
class AvlTree{
public:
	Node* root;

	AvlTree();
	Node* LL(Node* rootNode);
	Node* RR(Node* rootNode);
	Node* LR(Node* rootNode);
	Node* RL(Node* rootNode);
	Node* nodeInsert(Node* &rootNode , int data);
	bool nodeFind(Node* rootNode , int data);
	void nodePrint(Node* rootnode , int dir , int data);
	Node* nodeDelete(Node* rootnode , int data);
};