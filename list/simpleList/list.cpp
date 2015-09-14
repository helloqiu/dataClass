#include "list.h"

Element::Element(int num){
	this -> num = num;
	this -> next = NULL;
	this -> last = NULL;
}
list::list(){
	this -> head = NULL;
	this -> length = 0;
}
void list::addElement(Element* e){
	length ++;
	if (this -> head == NULL){
		this -> head = e;
		e -> next = e;
		e -> last = e;
		return;
	}
	e -> next = head;
	e -> last = head -> last;
	head -> last -> next = e;
	head -> last = e;
}
void list::deleteElement(int pos , int length){
	if (pos + length - 1 > this -> length){
		return;
	}
	Element* e = this -> head;
	for (int i = 1 ; i != pos ; i++){
		e = e -> next;
	}
	Element* last = e -> last;
	Element* nowe = NULL;
	for (int i = 0 ; i < length ; i ++){
		nowe = e -> next;
		delete e;
		e = e -> next;
	}
	last -> next = e;
}