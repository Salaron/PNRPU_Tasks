#include <iostream>
#include <string>

using namespace std;

int getIntSafe(bool strict = true)
{
	int res;
	while (!(cin >> res) || (cin.peek() != '\n') || (strict == true && res <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите целое число, которое больше нуля!" << endl;
	}
	return res;
}

string* createArray(int size)
{
	string* arr = new string[size];
	cin.ignore();
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " элемент: ";
		getline(cin, arr[i]);
	}
	return arr;
}

void printArray(string* arr, int size)
{
	if (size <= 0) {
		cout << "Массив пуст" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "[" << i << "] = " << arr[i] << endl;
		}
	}
}

void removeDubles(string* arr, int* size) {
	for (int i = 0; i < *size; i++) {
		for (int j = i + 1; j < *size; j++) {
			if (arr[i] == arr[j]) {
				for (int k = j; k < *size - 1; k++) {
					arr[k] = arr[k + 1];
				}
				(*size) -= 1;
				i -= 1;
			}
		}
	}
}

void removeFromBottom(string*& arr, int* size, int K) {
	(*size) -= K; // можно оставить только эту строку, но это будет слишком просто, so, so...
	string* newarr = new string[*size];
	for (int i = 0; i < *size; i++) {
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите размер массива: ";
	int size = getIntSafe();
	string* arr = createArray(size);
	printArray(arr, size);
	removeDubles(arr, &size);
	cout << "Массив после удаления дубликатов: " << endl;
	printArray(arr, size);
	delete[] arr;

	cout << "Введите размер массива: ";
	int size2 = getIntSafe();
	string* arr2 = createArray(size2);
	printArray(arr2, size2);
	cout << "Введите количество строк, которые нужно удалить: ";
	int K = getIntSafe();
	while (K > size2) {
		cout << "Количество удаляемых строк не может быть больше, чем строк в массиве!" << endl;
		K = getIntSafe();
	}
	removeFromBottom(arr2, &size2, K);
	cout << "Массив после удаления " << K << " последних строк:" << endl;
	printArray(arr2, size2);
	delete[] arr2;

	return 0;
}