#ifndef JIHEBING_H
#define JIHEBING_H
#include<iostream>

using namespace std;
 
class Element{
public:
	Element* next = NULL;
	Element* front = NULL;
	int num = 0;
};

class Set{
public:
	Element* head = NULL;

	Element* findLast(Element* e){
		if (e -> next == NULL){
			return e;
		}else{
			return this->findLast(e -> next);
		}
	}

	void addNum(Element* e){
		if (head == NULL){
			head = e;
		}else{
			//this -> findLast(head) -> next = e;
			Element* tempE = head;
			while(true){
				if (tempE -> num == e -> num){
					return;
				}
				if (tempE -> num > e -> num){
					if (tempE -> next == NULL){
						tempE -> next = e;
						e -> front = tempE;
						return;
					}
					tempE = tempE -> next;
					continue;
				}
				if (tempE -> front != NULL){
					tempE -> front -> next = e;
				}			
				e -> next = tempE;
				e -> front = tempE -> front;
				tempE -> front = e;

				return;
			}
			

		}
	}
};
#endif