#include "stack.h"
stack::stack(){
//nothing to do
}
void stack::push(char ch){
	this -> now = new Element(ch);
	l.addElement(now);
}
Element* stack::pop(){
	if (now != l.head){
		now = now ->last;
		return now -> next;
	}else{
		return NULL;
	}
}