#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int n = 0;
	while ((n % 2) == 0 || n <= 0) {
		cout << "Введите положительное нечётное число: ";
		cin >> n;
	}

	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= (n - i) / 2; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}