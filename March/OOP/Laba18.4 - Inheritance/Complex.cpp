#include "Complex.h"

Complex::Complex() {
	m_real = 0;
	m_im = 0;
}

Complex::Complex(int real, int im) {
	setReal(real);
	setIm(im);
}

int Complex::getReal() {
	return m_real;
}

int Complex::getIm() {
	return m_im;
}

void Complex::setReal(int real) {
	m_real = real;
}

void Complex::setIm(int im) {
	m_im = im;
}

Complex Complex::mul(Complex other) {
	Complex result;
	result.setReal(getReal() * other.getReal() - getIm() * other.getIm());
	result.setIm(getIm() * other.getReal() + getReal() * other.getIm());
	return result;
}

Complex Complex::sub(Complex other) {
	Complex result;
	result.setReal(getReal() - other.getReal());
	result.setIm(getIm() + other.getIm());
	return result;
}