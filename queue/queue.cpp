#include "queue.h"
queue::queue(){
	this -> head = NULL;
	this -> tail = NULL;
}
void queue::addElement(element* e){
	if (this -> head == NULL && this -> tail == NULL){
		this -> head = e;
		this -> tail = e;
		return;
	}
	this -> tail -> next = e;
	this -> tail = e;
}
element* queue::giveElement(){
	if (this -> head == NULL && this -> tail == NULL){
		//the queue is empty
		return NULL;
	}
	if (this -> head == this -> tail){
		//the queue only has one element
		element* tempE = this -> head;
		this -> head = NULL;
		this -> tail = NULL;
		return tempE;
	}
	element* tempE = this -> head;
	this -> head = this -> head -> next;
	return tempE;
}
void queue::showQueue(){
	element* e = this -> head;
	while(e != this -> tail){
		cout << e -> num << "\n";
		e = e -> next;
	}
	if (e != NULL){
		cout << e -> num << "\n";
	}
}