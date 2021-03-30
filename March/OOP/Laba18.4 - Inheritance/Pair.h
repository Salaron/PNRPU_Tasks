#pragma once
#include <iostream>

using namespace std;

class Pair {
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

	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, Pair& p);
};