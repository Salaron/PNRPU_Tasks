#include "Complex.h"

Complex::Complex() {
	m_real = 0;
	m_im = 0;
}

Complex::Complex(Pair a, Pair b) {
	setReal(a, b);
	setIm(a, b);
}

int Complex::getReal() {
	return m_real;
}

int Complex::getIm() {
	return m_im;
}

void Complex::setReal(Pair a, Pair b) {
	m_real = a.getFirst() * b.getFirst() - a.getSecond() * b.getSecond();
}

void Complex::setIm(Pair a, Pair b) {
	m_im = a.getFirst() * b.getSecond() + a.getSecond() * b.getFirst();
}

void Complex::Show() {
	cout << "(" << m_real << ", " << m_im << "i)" << endl;
}
