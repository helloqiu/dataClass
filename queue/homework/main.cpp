#include <iostream>
using namespace std;
#include "queue.h"
int main(void){
	queue q;
	int n = 0;
	while (true){
		
		q.showQueue();
		cout << "      |      ";
		cout << "\n";
		cin >> n;
		if (n > 0){
			q.addNum(n);
			continue;
		}
		if (n == 0){
			q.deleteNum();
			continue;
		}
		if (n == -1){
			break;
		}
		cout << "enter error\n";
	}
	return 0;
}