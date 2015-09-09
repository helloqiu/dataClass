#include"avlTree.h"
#include<iostream>
using namespace std;
int avlTree::height(Node node){
	return node -> height;
}
avlTree::avlTree(){
	RootNode = NULL;

}
void avlTree::add(int data){
	avlTree::nodeInsert(RootNode , data);
}
void avlTree::showAll(){
	avlTree::printNode(RootNode , 0 , RootNode -> data);
}
Node avlTree::createNode(Node left , Node right , int data){
	static Node node = new(struct Point);
	node -> left = left;
	node -> right = right;
	node -> data = data;
	node -> height = 1;
	return node;
}
Node avlTree::LL(Node rootnode){
	Node node;
	node = rootnode -> left;
	rootnode -> left = node -> right;
    node -> right = rootnode;
	rootnode -> height = MAX(avlTree::height(rootnode -> left) , avlTree::height(rootnode -> right)) + 1;
	node -> height = MAX(avlTree::height(node -> left) , avlTree::height(node -> right)) + 1;
	cout << node -> data << " do a LL" << endl;
	return node;
}
Node avlTree::RR(Node rootnode){
	Node node;
	node = rootnode -> right;
	rootnode -> right = node -> left;
    node -> left = rootnode;
	rootnode -> height = MAX(avlTree::height(rootnode -> left) , avlTree::height(rootnode -> right)) + 1;
	node ->height = MAX(avlTree::height(node -> left) , avlTree::height(node -> right)) + 1;
	cout << node -> data << "do a RR" << endl;
	return node;
}
Node avlTree::LR(Node rootnode){
	rootnode -> left = RR(rootnode -> left);
	cout << rootnode -> data << "do a LR" << endl;
	return LL(rootnode);
}
Node avlTree::RL(Node rootnode){
	rootnode -> right = LL(rootnode -> right);
	cout << rootnode -> data << "do a RL" << endl;    
	return RR(rootnode);
}
Node avlTree::nodeInsert(Node rootnode , int data){
	if (rootnode == NULL){
        rootnode = createNode(NULL , NULL , data);
		return rootnode;
    }
  	if (data == rootnode -> data){
		cout << "Insert Node " << data << "failed" << endl; 
	}
	if (data < rootnode -> data){
		rootnode -> left = nodeInsert(rootnode -> left , data);
        rootnode -> height = MAX(avlTree::height(rootnode -> left) , avlTree::height(rootnode -> right)) + 1;
							        //lose balance
        int rightheight = 0;
        if (rootnode -> right != NULL){
			rightheight = rootnode -> right ->height;
		}						//                                    }
		if (avlTree::height(rootnode -> left) >= rightheight + 2){
			if (data < rootnode -> left -> data){
				rootnode = LL(rootnode);
			}else{
				rootnode = LR(rootnode);
			}
		}
	}else{
		if (data > rootnode -> data){
			rootnode -> right = nodeInsert(rootnode -> right , data);
			rootnode -> height = MAX(avlTree::height(rootnode -> left) , avlTree::height(rootnode -> right)) + 1;
			//lose balance
			int leftheight = 0;
			if (rootnode -> left != NULL){
				leftheight = rootnode -> left -> height;
			}
			if (avlTree::height(rootnode -> right) >= leftheight + 2){
				if (data > rootnode -> right -> data){
					rootnode = RR(rootnode);
				}else{
					rootnode = RL(rootnode);
				}
			}
		}
	}
	rootnode -> height = MAX(avlTree::height(rootnode -> left) , avlTree::height(rootnode -> right)) + 1;
	return rootnode;
}

void avlTree::printNode(Node rootnode , int dir , int data){
	if (rootnode == NULL){
		return;
	}
	if (dir == 0){
		cout << data << " is the rootnode" << endl;
	}else{
	cout <<rootnode -> data << " is " << data << "'s " << (dir == 1? "right" : "left") << " child" << endl;
	}
	avlTree::printNode(rootnode -> left , -1 , rootnode -> data);
	avlTree::printNode(rootnode -> right , 1 , rootnode -> data);
}

