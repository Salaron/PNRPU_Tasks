#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector {
	int m_size;
	T* m_container;
public:
	Vector(int s, T k);
	Vector(const Vector<T>& a);
	~Vector();

	Vector& operator = (const Vector<T>& a);
	T& operator [] (int index);
	Vector operator * (int k);
	int operator () ();

	friend ostream& operator << (ostream& out,  Vector<T>& a) {
		for (int i = 0; i < a(); ++i)
			out << a.m_container[i] << " ";
		return out;
	}
	friend istream& operator >> (istream& in, Vector<T>& a) {
		for (int i = 0; i < a(); ++i)
			in >> a.m_container[i];
		return in;
	}
};

#include "Vector.cpp"