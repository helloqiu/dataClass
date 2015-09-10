#include "avl-tree.h"
int Height(Node* node){
	if (node == NULL){
		return 0;
	}else{
		return node -> height;
	}
}

Node::Node(Node* left , Node* right , int data){
	this -> data = data;
	this -> left = left;
	this -> right = right;
	this -> height = 1;
}

Node* AvlTree::LL(Node* rootNode){
	Node* node;
	node = rootNode -> left;
	rootNode -> left = node -> right;
	node -> right = rootNode;
	rootNode -> height = MAX(Height(rootNode->left) , Height(rootNode -> right)) + 1;
	node -> height = MAX(Height(node -> left) , Height(node -> right)) + 1;
	return node;
}

Node* AvlTree::RR(Node* rootNode){
	Node* node;
	node = rootNode->right;
	rootNode->right = node -> left;
	node -> left = rootNode;
	rootNode -> height = MAX(Height(rootNode -> left) , Height(rootNode -> right)) + 1;
	node -> height = MAX(Height(node -> left) , Height(node -> right)) + 1;
	return node;
}
Node* AvlTree::LR(Node* rootNode){
	rootNode -> left = RR(rootNode->left);
	return LL(rootNode);
}
Node* AvlTree::RL(Node* rootNode){
	rootNode -> right = LL(rootNode->right);
	return RR(rootNode);
}
Node* AvlTree::nodeInsert(Node* rootNode , int data){
	if (rootNode == NULL){
		rootNode = new Node(NULL, NULL, data);
		return rootNode;
	}
	if (data == rootNode->data){
		return NULL;
	}
	if (data < rootNode -> data){
		rootNode -> left = nodeInsert(rootNode->left, data);
		rootNode -> height = MAX(Height(rootNode->left) , Height(rootNode -> right)) + 1;
		int rightHeight = 0;
		if (root)
	}
}