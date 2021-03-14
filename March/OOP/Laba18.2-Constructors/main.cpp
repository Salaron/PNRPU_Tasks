#include <iostream>
#include "number.h"

using namespace std;

Number::Number() {
	m_mantissa = 0.0;
	m_poryadok = 0;
	m_number = "0";
}

Number::Number(string n, double mantissa, int poryadok) {
	m_mantissa = mantissa;
	m_poryadok = poryadok;
	m_number = n;
}

Number::Number(const Number& n) {
	m_mantissa = n.m_mantissa;
	m_poryadok = n.m_poryadok;
	m_number = n.m_number;
}

void Number::Show() {
	cout << "Мантисса: " << m_mantissa << endl;
	cout << "Порядок: " << m_poryadok << endl;

}

int main() {
	system("chcp 1251>nul");
	Number test1;
	test1.Show();
}