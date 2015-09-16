#include "queue.h"
queue::queue(){
	for (int i = 0 ; i < 100 ; i ++){
		num[i] = 0;
	}
	this -> head = 0;
	this -> tail = 0;
}
void queue::addNum(int num){
	if (this -> head == this -> tail){
		//empty
		tail += 1;
		tail %= 100;
		this -> num[tail] = num;
		return;
	}
	tail += 1;
	tail %= 100;
	if (this -> num[tail] != 0){
		cout << "the queue is full\n";
		return;
	}
	this -> num[tail] = num;
}
int queue::deleteNum(){
	if (this -> head == this -> tail){
		//empty
		return 0;
	}
	head += 1;
	head %= 100;
	
	int temp = num[head];
	num[head] = 0;
	return temp;
}
void queue::showQueue(){
	int tempH = head;
	while (tempH != tail){
		tempH += 1;
		tempH %= 100;
		cout << num[tempH] << "\n";
	}
}