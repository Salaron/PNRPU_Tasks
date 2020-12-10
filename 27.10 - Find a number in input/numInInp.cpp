#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int N = 0;
	cout << "Введите натуральное число: ";
	cin >> N;
	while (N <= 0) {
		cout << "Число должно быть натуральным!" << endl << "Введите натуральное число: ";
		cin >> N;
	}
	int a;
	cout << "Введите цифру от 0 до 9, которую нужно найти: ";
	cin >> a;
	while (a < 0 || a > 9) {
		cout << "Цифра должна быть от 0 до 9!" << endl << "Введите цифру от 0 до 9, которую нужно найти: ";
		cin >> a;
	}
	int reserv = N;
	bool founded = false;
	while (!founded && N > 0) {
		if (N % 10 == a) {
			founded = true;
		}
		N /= 10;
	}

	if (!founded) {
		cout << "В числе " << reserv << " нет цифры " << a << endl;
	}
	else {
		cout << "В числе " << reserv << " цифра " << a << " присутствует" << endl;
	}

	return 0;
}