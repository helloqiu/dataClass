#define MAX(num1 , num2) ((num1) > (num2) ? (num1) : (num2))
#include "Node.h"
class avlTree{
	public :
		avlTree();
		void add(int data);
		void showAll(void);
	private :
		Node createNode(Node left , Node right , int data);
		Node LL(Node rootnode);
		Node RR(Node rootnode);
		Node LR(Node rootNode);
		Node RL(Node rootNode);
		Node nodeInsert(Node rootNode , int data);
		Node findMax(Node rootNode);
		Node findMin(Node rootNode);
		Node find(int data);
		void printNode(Node rootnode , int dir , int data);
		int height(Node node);
		Node RootNode;
};
