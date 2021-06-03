#pragma once
#include<iostream>
#include<map>
using namespace std;
template<class Type>
class Vector
{
protected:
	map<int, Type> arr;
	int size;
public:
	Vector();
	Vector(int length);
	Vector(const Vector& object);	
	~Vector();
	Vector& operator=(const Vector<Type>& other);
	Type& operator[] (int index);
	void operator+(const Type k);
	int operator()();
	void PrintMap();
	int FindAverageValue();
	void insert(int pos, Type element);
	friend ostream& operator<< (ostream& out, const Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			out << p.arr[i] << " ";
		}
		cout << endl;
		return out;
	}
	friend istream& operator>> (istream& in, Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			in >> p.arr[i];
		}
		return in;
	}
};
#include "Vector.cpp"