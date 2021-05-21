#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;
class Vector {
	int m_size;
	int* m_container;
public:
	Vector(int s, int k = 0);
	Vector(const Vector& a);
	~Vector();

	Vector& operator = (const Vector& a);
	int& operator [] (int index);
	int operator () ();
	Vector& operator --();
	Vector operator --(int);


	friend ostream& operator << (ostream& out, Vector& a);
	friend istream& operator >> (istream& in, Vector& a);
};