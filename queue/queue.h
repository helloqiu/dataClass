#ifndef QUEUE_H
#define QUEUE_H
#include "element.h"
class queue{
public:
	element* head;
	element* tail;
	queue();
	void addElement(element* e);
	element* giveElement();
	void showQueue();
};
#endif