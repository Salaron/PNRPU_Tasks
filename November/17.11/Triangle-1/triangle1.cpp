#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int n = 0;
	for (;;) {
		cout << "Введите длину катетов треугольника: ";
		cin >> n;
		if (n >= 1) break;
		cout << "Длина должна быть больше 1!" << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}