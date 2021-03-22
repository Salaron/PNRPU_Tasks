#include <string>
#pragma once
using namespace std;

class Number {
	double m_mantissa;
	int m_poryadok;
	string m_number;

	void updateNumber();
public:
	// ������������
	Number();
	Number(double, int);
	Number(const Number&);

	// �������
	double getMantissa();
	int getPoryadok();
	string getNumber();

	// �������
	void setMantissa(double);
	void setPoryadok(int);
	
	void Show();
};