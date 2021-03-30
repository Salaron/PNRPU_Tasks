#pragma once
#include "Object.h"

class Vector {
protected:
	Object** m_begin;
	int m_size;
	int m_current;
public:
	Vector();
	Vector(int count);
	~Vector();

	void Add();
	void Del();
	void Show();
	void HandleEvent(TEvent& event);

	// размер вектора
	int operator () ();
};