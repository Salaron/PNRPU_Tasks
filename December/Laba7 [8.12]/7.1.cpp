#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void move(int* arr, int size) {
	int offset = (arr[0] % size);
	for (int j = 0; j < offset; j++) {
		int temp = arr[0];
		for (int i = 1; i < size; i++) {
			arr[i - 1] = arr[i];
		}
		arr[size - 1] = temp;
	}
}
void move(int* arr, int n, bool state) {
	int offset = (arr[n - 1] % n);
	for (int i = offset; i > 0; i--) {
		int size = n;
		int temp = arr[--size];
		while (size > 0) arr[size--] = arr[size - 1];
		arr[0] = temp;
	}
}

int GetInt()
{
	int res;
	if (!(cin >> res) || (cin.peek() != '\n') || res < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите целое число, которое больше нуля!" << endl;
	}
	return res;
}

void PrintArray(int* arr, int n) {
	cout << "Индекс:   ";
	for (int i = 0; i < n; i++) {
		
		cout << i << "\t";
	}
	cout << endl << "Значение: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	srand(time(0));

	int n;
	for (;;) {
		cout << "Введите размер массива: ";
		n = GetInt();
		if (n > 0) break;
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
	}
	PrintArray(arr, n);
	cout << endl;

	if ((arr[0] % 2) == 0) {
		cout << "Первый элемент чётный -> выполняем циклический сдвиг влево на " << arr[0] << " позиций" << endl;
		move(arr, n);
	}
	else {
		cout << "Первый элемент нечётный -> выполняем циклический сдвиг вправо на " << arr[n - 1] << " позиций" << endl;
		move(arr, n, true);
	}
	cout << "Результат" << endl;
	PrintArray(arr, n);
	return 0;
}