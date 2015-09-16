#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
class queue{
public:
	int num[100];
	int head;
	int tail;

	queue();
	void addNum(int num);
	int deleteNum();
	void showQueue();
};
#endif