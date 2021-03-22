#pragma once
#include <iostream>

using namespace std;

class Iterator {
	friend class Vector;
	int* m_pCurrent;
public:
	Iterator() { m_pCurrent = 0; }
	Iterator(const Iterator& it) { m_pCurrent = it.m_pCurrent;  }

	bool operator == (const Iterator& it) { return m_pCurrent == it.m_pCurrent; }
	bool operator != (const Iterator& it) { return m_pCurrent != it.m_pCurrent; }
	void operator ++ () { ++m_pCurrent; }
	void operator ++ (int) { m_pCurrent++; }
	void operator -- () { --m_pCurrent; }
	void operator -- (int) { m_pCurrent--; }
	void operator -  (const int k) { m_pCurrent -= k; }
	int& operator *  () const { return *m_pCurrent; }
};

class Vector {
	int m_size;
	int* m_container;
	Iterator m_begin;
	Iterator m_end;
public:
	Vector(int s, int k = 0);
	Vector(const Vector&a);
	~Vector();

	Vector& operator = (const Vector&a);
	int& operator [] (int index);
	Vector operator * (const int k);
	int operator () ();

	Iterator first() { return m_begin; }
	Iterator last()  { return m_end;   }

	friend ostream& operator << (ostream& out, Vector&a);
	friend istream& operator >> (istream& in, Vector&a);
};