#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	double b;
	cout << "Введите параметр b: ";
	cin >> b;
	while (b > 7) {
		cout << "Параметр b не должен превышать 7!" << endl << "Введите параметр b: ";
		cin >> b;
	}

	if (b > 1) {
		double z1 = (sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4))) / (sqrt(pow(b, 2) - 4) + b + 2);
		cout << "z1 = " << z1 << endl;
	}
	else {
		cout << "z1 не существует -- извлечение квадратного корня из отрицательного числа" << endl;
	}
	if (b > -2) {
		double z2 = 1 / (sqrt(b + 2));
		cout << "z2 = " << z2 << endl;
	}
	else if (b == -2) {
		cout << "z2 не существует -- деление на нуль" << endl;
	}
	else {
		cout << "z2 не существует -- извлечение квадратного корня из отрицательного числа" << endl;
	}

	return 0;
}