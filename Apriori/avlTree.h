#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"
class avlTree{
	public :
		avlTree();
		void add(int data);
		void showAll(void);
	private :
		Node createNode(Node left , Node right , int data);
		static Node LL(Node rootnode);
		static Node RR(Node rootnode);
		static Node LR(Node rootNode);
		static Node RL(Node rootNode);
		Node nodeInsert(Node rootNode , int data);
		Node findMax(Node rootNode);
		Node findMin(Node rootNode);
		Node find(int data);
		void printNode(Node rootnode , int dir , int data);
		bool find(Node node);

		Node RootNode;
};

#endif // AVLTREE_H
