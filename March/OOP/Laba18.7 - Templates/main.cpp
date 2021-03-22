#include "Vector.h"
#include <iostream>
#include "Time.h"

using namespace std;

int main() {
	system("chcp 1251>nul");
	cout << "Создание вектора типа int на 5 элементов" << endl;
	Vector<int> a(5, 0);
	cout << a << endl;
	cin >> a;
	cout << a << endl;

	cout << "Тест класса Time" << endl;
	Time t;
	cin >> t;
	cout << t;

	cout << "Создание вектора типа Time на 3 элемента" << endl;
	Vector<Time> b(3, t);
	cin >> b;
	cout << b << endl;
	b = b * 2;
	cout << b << endl;

	return 0;
}