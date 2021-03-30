#include "number.h"
#include <iostream>
#include <math.h>

using namespace std;

Number::Number() {
	m_mantissa = 0.0;
	m_poryadok = 0;
	m_number = "0";
}

Number::Number(double mantissa, int poryadok) {
	m_mantissa = mantissa;
	m_poryadok = poryadok;
	m_number = to_string(m_mantissa * pow(10, m_poryadok));
}

Number::Number(const Number& n) {
	m_mantissa = n.m_mantissa;
	m_poryadok = n.m_poryadok;
	m_number = n.m_number;
}

void Number::updateNumber() {
	m_number = to_string(m_mantissa * pow(10, m_poryadok));
}

double Number::getMantissa() {
	return m_mantissa;
}

int Number::getPoryadok() {
	return m_poryadok;
}

string Number::getNumber() {
	return m_number;
}

void Number::setMantissa(double man) {
	m_mantissa = man;
	updateNumber();
}

void Number::setPoryadok(int por) {
	m_poryadok = por;
	updateNumber();
}


void Number::Show() {
	cout << "Мантисса: " << m_mantissa << endl;
	cout << "Порядок: " << m_poryadok << endl;
	cout << "Строковое представление: " << m_number << endl;
}