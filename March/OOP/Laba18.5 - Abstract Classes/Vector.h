#pragma once
#include "Object.h"
#include <iostream>

class Vector {
	int size, current;
	Object** beg;
public:
	Vector(int size);
	~Vector();

	void push(Object* p);
	friend std::ostream& operator<<(std::ostream& out, const Vector& t);
};