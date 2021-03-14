#include <string>
#pragma once
using namespace std;

class Number {
	double m_mantissa;
	int m_poryadok;
	string m_number;
public:
	// конструкторы
	Number();
	Number(string, double, int);
	Number(const Number&);
	
	void Show();
};