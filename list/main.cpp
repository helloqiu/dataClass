#include "set.cpp"

int main(void){
	Set* s1 = new Set();
	Set* s2 = new Set();
	int l = 0;
	int tmp;
	Element* tmpElement;
	for (int i = 1 ; i < 3 ; i ++ ){
		cout << "please enter the number of " << (i == 1 ? "the first set:\n" : "the second set:\n");
		cin >> l;
		cout << "now please enter the numbers : \n";
		for (int j = 0 ; j < l ; j ++){
			cin >> tmp;
			tmpElement = new Element(tmp);
			i == 1 ? s1 -> addElement(tmpElement) : s2 -> addElement(tmpElement);
		}
	}
	s1 -> unionSet(s2);
	tmpElement = s1 -> head;
	while (tmpElement != NULL){
		cout << tmpElement -> num << "\n";
		tmpElement = tmpElement -> next;
	}
	return 0;
}