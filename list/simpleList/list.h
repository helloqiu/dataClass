#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class Element{
public:
	Element(int num);
	Element* next;
	Element* last;
	int num;
};

class list{
public:
	list();

	void addElement(Element* e);
	void deleteElement(int pos , int length);
	Element* head;
	int length;
};


#endif