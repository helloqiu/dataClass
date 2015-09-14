#include <iostream>
#include "list.h"
using namespace std;

int main(){
	list l;
	cout << "please enter the number of Elements that you want to enter:\n";
	int length = 0;
	cin >> length;
	cout << "now please enter the " << length << "Element\n";
	int temp = 0;
	Element* e = NULL;
	for (int i = 0 ; i < length ; i ++){
		cin >> temp;
		e = new Element(temp);
		l.addElement(e);
	}
	cout << "now enter the position to delete element:\n";
	int pos = 0;
	cin >> pos;
	cout << "now enter the length that you want to delete:\n";
	cin >> length;
	l.deleteElement(pos, length);

	//show the list
	cout << "here is the list:\n";
	e = l.head;
	while (true){
		if (e -> next == l.head){
			cout << e -> num << "\n";
			break;
		}
		cout << e -> num << "\n";
		e = e -> next;
	}
	return 0;
}