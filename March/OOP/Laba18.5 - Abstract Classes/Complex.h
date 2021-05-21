#pragma once
#include "Pair.h"

class Complex : public Pair {
	int m_real;
	int m_im;
public:
	Complex();
	Complex(Pair a, Pair b);

	void setReal(Pair a, Pair b);
	void setIm(Pair a, Pair b);

	int getReal();
	int getIm();

	void Show();
};