#include "queue.h"
#include <iostream>
using namespace std;
int main(void){
	queue q;
	int length = 0;
	cout << "please enter the length:\n";
	cin >> length;
	cout << "now please enter the queue:\n";
	int temp;
	element* tempE;
	for (int i = 0 ; i < length ; i ++){
		cin >> temp;
		tempE = new element(temp);
		q.addElement(tempE);
	}
	cout << "here is the queue:\n";
	q.showQueue();
	while (true){
		cout << "here is the queue:\n";
		q.showQueue();
		cout << "'0' : enter element; '1' : give element; '2' : halt\n";
		cin >> temp;
		if (temp == 0){
			cout << "please enter the element:\n";
			cin >> temp;
			tempE = new element(temp);
			q.addElement(tempE);
			continue;
		}
		if (temp == 1){
			tempE = q.giveElement();
			if (tempE == NULL){
				cout << "the queue is empty\n";
				continue;
			}
			cout << tempE -> num << "\n";
			delete tempE;
			continue;
		}
		if (temp == 2){
			break;
		}
	}
	return 0;
}