#include"Set.h"
Element::Element(int num){
	this -> next = NULL;
	this -> last = NULL;
	this -> num = num;
}

Set::Set(){
	this -> head = NULL;
}

void Set::addElement(Element* e){
	if (this -> head == NULL){
	//the set is empty
		this -> head = e;
		cout << e -> num;
		return;
	}
	//the set isn't empty
	Element* tmpElement = this -> head;
	while (tmpElement != NULL){
		if (tmpElement -> num == e -> num){
		//already have this element
			break;
		}
		if (tmpElement -> num > e -> num){
		//continue 
			if (tmpElement -> next == NULL){
				tmpElement -> next = e;
				e -> last = tmpElement;
				break;
			}
			tmpElement = tmpElement -> next;
			continue;
		}else{
		//find the position
			if (tmpElement -> last == NULL){
			//the first element
				tmpElement -> last = e;
				e -> next = tmpElement;
				this -> head = e;
				break;
			}else{
				tmpElement -> last -> next = e;
				e -> last = tmpElement -> last;
				tmpElement -> last = e;
				e -> next = tmpElement;
				break;
			}
		}
	}
	tmpElement = this -> head;
	while (tmpElement != NULL){
		cout << tmpElement -> num << "\n";
		tmpElement = tmpElement -> next;
	}
}

void Set::unionSet(Set* s){
	if (this -> head == NULL){
	//this set is empty
		this -> head = s -> head;
		return;
	}
	Element* e1 = this -> head;
	Element* e2 = s -> head;
	while(e2 != NULL){
		if (e1 -> next == NULL){
			cout << "add " << e1 -> num << " after " << e2 -> num << endl;
			e1 -> next = e2;
			e2 -> last = e1;
			e1 = e2;
			e2 = e2 -> next;
			if (e2 -> next -> num == e2 -> num){
				e2 -> next = NULL;
				break;
			}
			continue;
		}
		if (e1 -> num == e2 -> num){
			cout << "change " << e2 -> num << "to next\n";
			e2 = e2 -> next;
			continue;
		}
		if (e1 -> num > e2 -> num){
			cout << "change " << e1 -> num << "to " << e1 -> next -> num << "\n";
			e1 = e1 -> next;
			continue;
		}
		if (e1 -> num < e2 -> num){
			cout << "add " << e2 -> num << " front " << e1 -> num << endl;
			Element* tempE2 = e2 -> next;
			if (e1 -> last == NULL){
			//the first element
				e2 -> last = NULL;
				this -> head = e2;
			}else{
				e2 -> last = e1 -> last;
				e1 -> last -> next = e2;
			}
				e2 -> next = e1;
				e1 -> last = e2;
				e2 = tempE2;
				continue;
		}
	}
}