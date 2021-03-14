#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

int getIntSafe(bool strict = true) {
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}

struct Stadium {
	string name;
	string sports;
	int year;
	int num;

	void Print() {
		cout << endl;
		cout << "Название:\t" << name << endl;
		cout << "Год постройки:\t" << year << endl;
		cout << "Количество площадок:\t" << num << endl;
		cout << "Виды спорта:\t" << sports << endl;
	}

	void Fill() {
		cout << endl << "Введите название стадиона: ";
		getline(cin, name);

		cout << "Введите год постройки: ";
		year = getIntSafe();

		cout << "Введите количество площадок: ";
		num = getIntSafe();

		cout << "Введите виды спорта: ";
		getline(cin, sports);
	}
};

void Remove(Stadium* arr, int* count, int pos) {
	for (int i = pos; i < *count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*count)--;
}

void Insert(Stadium*& arr, int* count, int pos) {
	Stadium* newarr = new Stadium[*count + 1]; // create a new array
	int offset = 0; // offset over the old array
	for (int i = 0; i < *count; i++) {
		if (i == pos) {
			(*count)++;
			offset++;
			Stadium element;
			element.Fill();
			newarr[i] = element;
		}
		else {
			newarr[i] = arr[i - offset];
		}
	}
	delete[] arr;
	arr = newarr;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите количество элементов: ";
	int elementsCnt = getIntSafe();

	Stadium* stadiums = new Stadium[elementsCnt];
	for (int i = 0; i < elementsCnt; i++) {
		stadiums[i].Fill();
	}

	cout << "Введите год, до котого нужно удалить элементы: ";
	int year = getIntSafe();
	for (int i = 0; i < elementsCnt; i++) {
		if (stadiums[i].year < year) {
			Remove(stadiums, &elementsCnt, i);
			i--;
		}
	}

	for (int i = 0; i < elementsCnt; i++) {
		stadiums[i].Print();
	}

	cout << "Перед каким элементом нужно добавить дополнительные два элемента? [0; " << elementsCnt - 1 << "]" << endl;
	int pos = -1;
	while (pos < 0 || pos >= elementsCnt) {
		cout << "> ";
		pos = getIntSafe(false);
	}

	Insert(stadiums, &elementsCnt, pos);
	Insert(stadiums, &elementsCnt, pos + 1);
	for (int i = 0; i < elementsCnt; i++) {
		stadiums[i].Print();
	}
	delete[] stadiums;

	return 0;
}