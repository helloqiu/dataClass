#ifndef POLIST_H
#define POLIST_H
#include <iostream>
using namespace std;
class Element{
public:
	int num;
	Element* previous;
	Element* next;

	Element(int num);	
};
class Polist{
public:
	Element* head;

	Polist();
	Polist(Element* head);
	void addElement(Element* e);
	void mergePolistInRequestedWay(Polist* pb , Polist* pc);
	void printPolist();
};
#endif