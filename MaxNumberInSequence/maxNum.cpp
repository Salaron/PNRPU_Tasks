#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int N = 0;
	while (N <= 0) {
		cout << "Введите количество чисел в последовательности: ";
		cin >> N;
	}

	// ввод первого числа последовательности
	int first;
	cin >> first;
	
	int maxCnt = 1;
	int max = first;

	int minCnt = 1;
	int min = first;
	for (int i = 1; i < N; i++) {
		int current;
		cin >> current;
		if (current >= max) {
			if (current == max)
				maxCnt++;
			else {
				max = current;
				minCnt = 1;
			}
		}
		if (current <= min) {
			if (current == min)
				minCnt++;
			else {
				min = current;
				minCnt = 1;
			}
		}
	}

	cout << "Максимальное число в последовательности: " << max << endl;
	cout << "Минимальное число последовательности: " << min << endl;

	return 0;
}