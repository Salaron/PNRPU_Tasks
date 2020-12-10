#include <iostream>
#include <time.h>

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
		cout << "������� ����� �����, ������� ������ ����!" << endl;
	}
	return res;
}

void PrintArray(int* arr, int n) {
	cout << "������:   ";
	for (int i = 0; i < n; i++) {
		
		cout << i << "\t";
	}
	cout << endl << "��������: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	int n;
	for (;;) {
		cout << "������� ������ �������: ";
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
		cout << "������ ������� ������ -> ��������� ����������� ����� ����� �� " << arr[0] << " �������" << endl;
		move(arr, n);
	}
	else {
		cout << "������ ������� �������� -> ��������� ����������� ����� ������ �� " << arr[n - 1] << " �������" << endl;
		move(arr, n, true);
	}
	cout << "���������" << endl;
	PrintArray(arr, n);
	return 0;
}