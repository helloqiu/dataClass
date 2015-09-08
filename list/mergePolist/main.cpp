#include "polist.h"

int main(void){
	int l = 0;
	int num;
	Element* e;
	Polist* polist = new Polist();

	cout << "enter the number of the numbers you want to enter : \n";
	cin >> l;
	cout << "now enter the Polist:\n";
	for (int i = 0 ; i < l ; i ++){
		cin >> num;
		e = new Element(num);
		polist -> addElement(e);
	}
	polist->printPolist();
	return 0;
}