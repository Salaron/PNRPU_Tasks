#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int n = 0;
	for (;;) {
		cout << "Введите количество чисел в последовательности: ";
		cin >> n;
		if (n > 0) break;
		cout << "Количество чисел должно быть больше нуля!" << endl;
	}
	int z = 0;
	cout << "Введите число, которое нужно найти: ";
	cin >> z;

	bool exists = false;
	while (n--) {
		int a;
		cin >> a;
		if (a == z) exists = true;
	}

	if (exists) {
		cout << "Число " << z << " присутствует в последовательности" << endl;
	}
	else {
		cout << "Числа " << z << " нет в данной последовательности" << endl;
	}

	return 0;
}