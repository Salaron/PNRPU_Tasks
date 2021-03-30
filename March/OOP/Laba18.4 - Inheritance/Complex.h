#pragma once
#include "Pair.h"

class Complex : Pair {
	int m_real;
	int m_im;
public:
	Complex();
	Complex(int real, int im);

	void setReal(int real);
	void setIm(int im);

	int getReal();
	int getIm();

	Complex mul(Complex other);
	Complex sub(Complex other);
};