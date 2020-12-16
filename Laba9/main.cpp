#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;


int* bubble(int* arr, int size)
{
	int* result = new int[size];
	memcpy(result, arr, size * sizeof(int));
	for (int i = 0; i < size; i++) {
		int swaps = 0;
		for (int j = 0; j < size - i - 1; j++) {
			if (result[j] > result[j + 1]) {
				int t = result[j];
				result[j] = result[j + 1];
				result[j + 1] = t;
				swaps += 1;
			}
		}
		if (swaps == 0) break; // массив отсортирован
	}
	return result;
}

int* insert(int* arr, int size)
{
	int* result = new int[size];
	memcpy(result, arr, size * sizeof(int));
	for (int i = 1; i < size; i++) {
		int k = result[i];
		int j = i;
		for (j = i; j > 0 && result[j - 1] < k; j--) {
			result[j] = result[j - 1];
		}
		result[j] = k;
	}

	return result;
}

int* select(int* arr, int size)
{
	int* result = new int[size];
	memcpy(result, arr, size * sizeof(int));
	for (int i = 0; i < size - 1; i++) {
		int imin = i;
		for (int j = i + 1; j < size; j++) {
			if (result[j] < result[imin]) {
				imin = j;
			}
		}
		int t = result[i];
		result[i] = result[imin];
		result[imin] = t;
	}

	return result;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	srand(time(0));
	int n = 5 + rand() % 15 + 1;
	cout << "Количество элементов в массиве: " << n << endl;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
	}
	cout << "Сгенерированный массив: " << endl;
	Print(arr, n);
	int* sorted1 = bubble(arr, n);
	cout << "Сортировка обменом: " << endl;
	Print(sorted1, n);
	
	int* sorted2 = insert(arr, n);
	cout << "Сортировка вставками (от большего к меньшему): " << endl;
	Print(sorted2, n);

	int* sorted3 = select(arr, n);
	cout << "Сортировка выбором: " << endl;
	Print(sorted3, n);

	return 0;
}