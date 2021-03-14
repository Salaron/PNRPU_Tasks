#pragma once
#include <iostream>

using namespace std;
class Stack {
	int m_size;
	double* m_stack;
public:
	Stack();
	Stack(Stack&);
	~Stack();

	void push(double);
	void pop();
	double top();
	int size();
	bool empty();

	friend istream& operator >>(istream& in, Stack& p);
	friend ostream& operator <<(ostream& out, Stack& p);
};