#include <string>
#pragma once
using namespace std;

class Number {
	double m_mantissa;
	int m_poryadok;
	string m_number;

	void updateNumber();
public:
	// конструкторы
	Number();
	Number(double, int);
	Number(const Number&);

	// геттеры
	double getMantissa();
	int getPoryadok();
	string getNumber();

	// сеттеры
	void setMantissa(double);
	void setPoryadok(int);
	
	void Show();
};