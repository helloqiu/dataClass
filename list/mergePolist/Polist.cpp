#include "Polist.h"
Element::Element(int num){
	this -> num = num;
	this -> previous = NULL;
	this -> next = NULL;
}

Polist::Polist(){
	this -> head = NULL;
}

Polist::Polist(Element* head){
	this -> head = head;
}

void Polist::addElement(Element* e){
	if (this -> head == NULL){
		this -> head = e;
		return;
	}

	Element* nowE = this -> head;
	while (nowE -> next != NULL){
		if (nowE -> num >= e -> num){
			nowE = nowE -> next;
			continue;
		}
		if (nowE -> previous == NULL){
			this -> head = e;
			e -> next = nowE;
			nowE -> previous = e;
			return;
		}else{
			nowE -> previous -> next = e;
			e -> previous = nowE -> previous;
			nowE -> previous = e;
			e -> next = nowE;
			return;
		}
	}
	if (nowE -> num > e -> num){
		nowE -> next = e;
		e -> previous = nowE;
	}else{
		if (nowE -> previous == NULL){
			this -> head = e;
			e -> next = nowE;
			nowE -> previous = e;
		}else{
			nowE -> previous -> next = e;
			e -> previous = nowE -> previous;
			nowE -> previous = e;
			e -> next = nowE;
		}
	}

}

void Polist::printPolist(){
	Element* nowE = this -> head;
	cout << "Here is the Polist:\n";
	while(nowE != NULL){
		cout << nowE -> num << "\n";
		nowE = nowE -> next;
	}
}