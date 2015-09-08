#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;
class Element{
public:
	int num;
	Element* next;
	Element* last;
	Element(int num);
};
class Set{
public:
	Element* head;
	Set();
	void addElement(Element* e);
	void unionSet(Set* s);
};

#endif