#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int N = 0;
	cout << "Введите натуральное число: ";
	cin >> N;
	while (N <= 0) {
		cout << "Число должно быть натуральным!" << endl << "Введите натуральное число: ";
		cin >> N;
	}
	int sum = 0;
	int reserv = N;
	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}
	cout << "В числе " << reserv << " сумма цифр равна " << sum << endl;
	return 0;
}