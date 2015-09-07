#include "jihehebing.h"
int unionSet(Set* s1 , Set* s2 );

int unionSet(Set* s1 , Set* s2 ){
	s1 -> findLast(s1 -> head) -> next = s2 -> head;
	s2 -> head -> front = s1 -> findLast(s1 -> head);
	return 0;
}
int main(void){
	Set s1 , s2;
	//two set try twice
	for (int k = 0 ; k < 2; k ++){
		cout << "please enter the number of the numbers you want to enter:";
		int l1 = 0;
		cin >> l1;
		cout << "please enter some numbers:\n";
		int j;
		for (int i = 0 ; i < l1 ; i ++){
			cin >> j;
			Element* e = new Element();
			e -> num = j;
			if (k == 0){
				s1.addNum(e);
			}else{
				s2.addNum(e);
			}
			
		}
	}
	unionSet(&s1 , &s2);
	Element* e = s1.head;
	while(e != NULL){
		cout << e -> num << "\n";
		e = e -> next;
	}
	return 0;
}