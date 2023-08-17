#pragma once
#ifndef LINKEDQUEUE
#define LINKEDQUEUE
#include<iostream>
#include<string>
#include "Employee.h"

struct Node {
	Employee data;
	Node* link;

	Node(Employee emp) {
		data = emp;
		link = nullptr;
	}
};

class LinkedQueue
{
public:
	int size = 0;
	Node* front = NULL;
	Node* rear = NULL;
	LinkedQueue();
	~LinkedQueue();
	//methods
	void ADD(Employee a);
	void REMOVE();
	int SIZE();
	void PRINT();
	bool EMPTY();
};
#endif // !LINKEDQUEUE