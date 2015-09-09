/*
Date : 2015-3-27-21:01
Author : 张宇阳(heheda | helloqiu)
Description : AVL tree

Date : 2015-3-27-23:46
Author : 张宇阳(heheda | helloqiu)
Description : Something goes wrong with AVL's xuanzhuan>_<and i'm too tired to point it out>_<

Date : 2015-3-28-18:21
Author : 张宇阳(heheda | helloqiu)
Description : Begin to solve the problem

Date : 2015-3-28-19:06
Author : 张宇阳(heheda | helloqiu)
Description : Problem solved.It's seemed to be alright.But how about the Delete?
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX(num1 , num2) ((num1) > (num2) ? (num1) : (num2))

typedef struct Point* Node;

struct Point{
    Node left;
    Node right;
    int height;
    int data;
};
static Node CreatNode(Node left , Node right , int data);
static Node LL(Node rootnode);
static Node RR(Node rootnode);
static Node LR(Node rootnode);
static Node RL(Node rootnode);
Node NodeInsert(Node rootnode , int data);
static Node NodeDelete(Node rootnode , Node delnode);
Node FindMax(Node rootnode);
Node FindMin(Node rootnode);
Node Find(int data);
void PrintNode(Node rootnode , int dir , int data);

int Height(Node node);

int main(void)
{
    printf("This is an application of AVL Tree !\n    >_<    \n");
    printf("please enter the node and end with an -1 : \n");
    int node = 0;
    Node rootnode = NULL;
    do{
        scanf("%d" , &node);
        if (node == -1){
            break;
        }
        rootnode = NodeInsert(rootnode , node);
        printf("Here is the tree : \n");
        PrintNode(rootnode , 0 , rootnode -> data);
    }while(1);
    printf("Here is the tree : \n");
    PrintNode(rootnode , 0 , rootnode -> data);
    return 0;
}

static Node CreatNode(Node left , Node right , int data){
    Node node;
    node = (Node)malloc(sizeof(struct Point));
    node -> data = data;
    node -> left = left;
    node -> right = right;
    node -> height = 1;
    return node;
}

int Height(Node node){
    if (node == NULL){
        return 0;
    }else{
    return node -> height;
    }
}

static Node LL(Node rootnode){
    Node node;
    node = rootnode -> left;
    rootnode -> left = node -> right;
    node -> right = rootnode;
    rootnode -> height = MAX(Height(rootnode -> left) , Height(rootnode -> right)) + 1;
    node -> height = MAX(Height(node -> left) , Height(node -> right)) + 1;

    printf("do a LL in node %d\n" , rootnode -> data);

    return node;
}
static Node RR(Node rootnode){
    Node node;
    node = rootnode -> right;
    rootnode -> right = node -> left;
    node -> left = rootnode;
    rootnode -> height = MAX(Height(rootnode -> left) , Height(rootnode -> right)) + 1;
    node -> height = MAX(Height(node -> left) , Height(node -> right)) + 1;

    printf("do a RR in node %d\n" , rootnode -> data);

    return node;
}
static Node LR(Node rootnode){

    printf("do a LR in node %d\n" , rootnode -> data);

    rootnode -> left = RR(rootnode -> left);
    return LL(rootnode);
}
static Node RL(Node rootnode){

    printf("do a RL in node %d\n" , rootnode -> data);

    rootnode -> right = LL(rootnode -> right);
    return RR(rootnode);
}
Node NodeInsert(Node rootnode , int data){
    if (rootnode == NULL){
        rootnode = CreatNode(NULL , NULL , data);
        return rootnode;
    }
    if (data == rootnode -> data){
        printf("Insert Node %d Failed !\n" , data);
    }
    if (data < rootnode -> data){
        rootnode -> left = NodeInsert(rootnode -> left , data);
        rootnode -> height = MAX(Height(rootnode -> left) , Height(rootnode -> right)) + 1;
        //lose balance
        int rightheight = 0;
        if (rootnode -> right != NULL){
            rightheight = rootnode -> right ->height;
        }
        if (Height(rootnode -> left) >= rightheight + 2){
            if (data < rootnode -> left -> data){
                rootnode = LL(rootnode);
            }else{
                rootnode = LR(rootnode);
            }
        }
    }else{
        if (data > rootnode -> data){
            rootnode -> right = NodeInsert(rootnode -> right , data);
            rootnode -> height = MAX(Height(rootnode -> left) , Height(rootnode -> right)) + 1;
            //lose balance
            int leftheight = 0;
            if (rootnode -> left != NULL){
                leftheight = rootnode -> left -> height;
            }
            if (Height(rootnode -> right) >= leftheight + 2){
                if (data > rootnode -> right -> data){
                    rootnode = RR(rootnode);
                }else{
                    rootnode = RL(rootnode);
                }
            }
        }
    }
    rootnode -> height = MAX(Height(rootnode -> left) , Height(rootnode -> right)) + 1;
    return rootnode;
}
static Node NodeDelete(Node rootnode , Node delnode){
    if (delnode == NULL || rootnode == NULL){
        return NULL;
    }
    //node in the left
    if (delnode -> data < rootnode -> data){
        rootnode -> left = NodeDelete(rootnode -> left , delnode);
        //lose balance
        if (Height(rootnode -> right) == Height(rootnode -> right) + 2){
            Node right = rootnode -> right;
            if (Height(right -> left) > Height(right -> right)){
                rootnode = RL(rootnode);
            }else{
                rootnode = RR(rootnode);
            }
        }
    }
    //node in the right
    if (delnode -> data > rootnode -> data){
        rootnode -> right = NodeDelete(rootnode -> right , delnode);
        //lose balance
        if (Height(rootnode -> left) == Height(rootnode -> right) + 2){
            Node left = rootnode -> left;
            if (Height(left -> right) > Height(left -> left)){
                rootnode = LR(rootnode);
            }else{
                rootnode = LL(rootnode);
            }
        }
    }
    //delnode is rootnode
    if (delnode -> data == rootnode -> data){
        if ((rootnode -> left != NULL) && (rootnode -> right != NULL)){
            //left is lager than right
            if (Height(rootnode -> left) > Height(rootnode -> right)){
                Node max = FindMax(rootnode -> left);
                rootnode -> data = max -> data;
                rootnode -> left = NodeDelete(rootnode -> left , max);
            }else{
            //right is lager than left
                Node min = FindMin(rootnode -> right);
                rootnode -> data = min -> data;
                rootnode -> right = NodeDelete(rootnode -> right , min);
            }
        }else{
        //left || right in null
            Node tmp = rootnode;
            if (rootnode -> left != NULL){
                rootnode = rootnode -> left;
            }else{
                rootnode = rootnode -> right;
            }
            free(tmp);
        }
    }
    return rootnode;
}
Node FindMax(Node rootnode){
    if (rootnode == NULL){
        return NULL;
    }
    while (rootnode -> right != NULL){
        rootnode = rootnode -> right;
    }
    return rootnode;
}
Node FindMin(Node rootnode){
    if (rootnode == NULL){
        return NULL;
    }
    while (rootnode -> left != NULL){
        rootnode = rootnode -> left;
    }
    return rootnode;
}
void PrintNode(Node rootnode , int dir , int data){
    if (rootnode == NULL){
        return;
    }
    if (dir == 0){
        printf("%d is the root\n" , data);
    }else{
        printf("%d is %d's %s child \n" , rootnode -> data , data , dir == 1?"right" : "left");
    }
    PrintNode(rootnode -> left , -1 , rootnode -> data);
    PrintNode(rootnode -> right , 1 , rootnode -> data);
}

