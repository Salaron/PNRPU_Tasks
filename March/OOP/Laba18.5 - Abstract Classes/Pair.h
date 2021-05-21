#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Pair: public Object {
	int m_first;
	int m_second;
public:

	Pair();
	Pair(int f, int s);

	int getFirst();
	int getSecond();

	void setFirst(int f);
	void setSecond(int s);

	Pair sum(Pair other);

	void Show();

	Pair operator +(const Pair& t);
	Pair operator -(const Pair& t);
	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, Pair& p);
};