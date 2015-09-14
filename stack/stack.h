/*
Time:2015-9-14 7:00
Name:stack
Description:a stack using vector to code less^_^
Author:helloqiu

Time:2015-9-14 7:37
Description:decide to not use stack
Author:helloqiu
*/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

class stack{
public:
	stack();
	void push(char ch);
	Element* pop();
	Element* now = NULL;
	list l;
private:

	
};
#endif