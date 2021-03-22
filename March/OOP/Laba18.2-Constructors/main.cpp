#include <iostream>
#include "number.h"

using namespace std;

void Show(Number num) {
	num.Show();
}

int main() {
	system("chcp 1251>nul");
	cout << "n1; конструктор без параметров" << endl;
	Number n1;
	n1.Show();

	cout << "n2; конструктор с параметрами" << endl;
	Number n2(0.425, 3);
	n2.Show();

	cout << "n3; конструктор копирования" << endl;
	Number n3 = n2;
	n3.Show();
	double mantissa;
	int poryadok;
	cout << "Введите мантиссу: "; cin >> mantissa;
	cout << "Введите порядок: "; cin >> poryadok;
	n3.setMantissa(mantissa);
	n3.setPoryadok(poryadok);
	Show(n3);
	return 0;
}