#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
using namespace std;
class element{
public:
	element(int num);
	element* next;
	int num;
};
#endif