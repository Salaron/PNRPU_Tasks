#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
#include "utils.h"

using namespace std;

void insertionSort(DATA*& arr, int size)
{
	for (int i = 1; i < size; i++) {
		DATA k = arr[i];
		int j = i;
		for (j = i; j > 0 && arr[j - 1].number > k.number; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = k;
	}
}

void generate(DATA*& str, int count) {
	if (str != nullptr) delete[] str;
	str = new DATA[count];
	for (int i = 0; i < count; i++) {
		string names[] = { "�����", "����", "�������", "������", "��������", "�����������", "������", "����", "�����", "������", "������", "�����", "������", "�����", "��������", "��������", "���������", "��������", "�������", "��������", "������", "����", "����", "�������", "��������", "�������", "�����", "������", "�����", "�����", "������", "������", "��������", "�������", "������", "����", "�������", "�������", "����", "������", "�����", "������", "��������", "������", "�����", "�����", "�������", "�������", "��������", "������", "�����", "�����", "��������", "���������", "�������", "����", "�����", "����", "���������", "�������", "�����", "�����", "��������", "��������", "����", "�����", "����", "������", "���������", "������", "��������", "�������", "���", "�������", "�������", "�����������", "����", "�����", "�������", "������", "������", "�����", "�������", "�����", "������", "�������", "�������", "�����", "�������", "������", "�������", "��������", "���������", "������", "��������", "������", "�����", "�����", "������", "�����" };
		string surnames[] = { "�������", "���������", "���������", "���������", "�����������", "����������", "����������", "����������", "��������", "�����������", "��������", "��������", "�������", "���������", "����������", "�����������", "�����", "���������", "�������", "��������", "���������", "�����������", "�����", "��������", "�������", "�������", "������������������", "�����", "��������", "����", "���������", "��������", "����������", "�������", "������", "������������", "���������", "������������", "������", "��������", "�����������", "���������", "���������", "��������", "���������", "�������", "������", "���������", "���������", "���������", "���������", "��������", "���������", "�����������", "����������", "����������", "��������", "����������", "�����������", "���������", "������������", "����������", "������", "�����", "������", "����������", "��������", "���������", "�����������", "��������", "��������", "���������", "�������", "�������", "���������", "���������", "�����������", "�������", "��������", "�����������", "��������", "��������", "���������", "��������", "�������", "�����", "��������", "���������", "���������", "��������", "������", "��������", "�������", "���������", "���������", "���������", "�����������", "������������", "�����", "��������" };
		string midnames[] = { "����������", "��������", "����������", "����������", "���������", "�������", "����������", "����������", "���������", "����-��������", "�������������", "���������", "����������", "�������������", "�������� ����", "���������", "����������", "���������", "��������", "��������������", "����� ����", "�������", "�����������", "�������������", "������������", "���������", "������� ����", "��������", "����������", "��������", "�������������", "�������� ����", "���������", "����� ����", "����������", "����� ����", "����������", "������������", "������������", "��������", "����������", "���������", "�����������", "������������", "��������������", "�������", "��������������", "���������������", "���������", "���������", "����������", "���������", "��������", "������������", "����������", "�������������", "����� ����", "��������", "������ ����", "�������������", "���������", "���������", "�����������", "��������", "��������", "������������", "��������", "����������", "����������", "�����������", "���������", "���������", "���������", "����������", "�������������", "��������", "�����������", "�����������", "�����������", "�����������", "���������", "������������", "������������", "������������", "���������", "���������", "������������", "���������", "���������", "����������", "���������", "�����������", "����������", "��������", "�������������", "�����������", "���������", "�����������", "���������", "����������" };
		str[i].fio = names[getRandomInt(0, 99)] + " " + surnames[getRandomInt(0, 99)] + " " + midnames[getRandomInt(0, 99)];
		str[i].birth = to_string(getRandomInt(1, 30)) + "." + to_string(getRandomInt(1, 12)) + "." + to_string(getRandomInt(1940, 2021));
		str[i].number = getRandomInt(100000, 999999);
	}
	insertionSort(str, count);
}

int load(DATA*& str, int* count) {
	if (str != nullptr) delete[] str;
	*count = 0;
	ifstream input("data.bin", ios::binary);
	int result = 1; // ok by default

	input.read((char*)count, sizeof(int));
	if (*count != 0) {
		str = new DATA[*count];
		for (int i = 0; i < *count; i++) {
			size_t fio_size, birth_size;
			input.read((char*)&fio_size, sizeof(string::size_type));
			str[i].fio.resize(fio_size);
			input.read((char*)&str[i].fio[0], fio_size);
			input.read((char*)&birth_size, sizeof(string::size_type));
			str[i].birth.resize(birth_size);
			input.read((char*)&str[i].birth[0], birth_size);
			input.read((char*)&str[i].number, sizeof(int));
		}
	}
	else {
		result = -1; // fail
	}

	input.close();
	return result;
}

int save(DATA* str, int count) {
	ofstream out_bin("data.bin", ios::binary);
	ofstream out_txt("data.txt");
	int result = 0;
	if (!out_bin.is_open() || !out_txt.is_open() || count == 0) {
		result = -1;
	}
	else {
		out_bin.write((char*)&count, sizeof(int));
		for (int i = 0; i < count; i++) {
			if (str[i].removed) continue;
			// binary
			size_t fio_size = str[i].fio.size();
			size_t birth_size = str[i].birth.size();
			out_bin.write((char*)&fio_size, sizeof(string::size_type));
			out_bin.write((char*)str[i].fio.c_str(), fio_size);
			out_bin.write((char*)&birth_size, sizeof(string::size_type));
			out_bin.write((char*)str[i].birth.c_str(), birth_size);
			out_bin.write((char*)&str[i].number, sizeof(int));
			// text
			out_txt << "[" << i << "] = " << endl;
			out_txt << "���:          \t" << str[i].fio << endl;
			out_txt << "���� ��������:\t" << str[i].birth << endl;
			out_txt << "����� ��������:\t" << str[i].number << endl;
			result += 1;
		}
	}
	out_bin.close();
	out_txt.close();
	return result;
}

void print(DATA* str, int count) {
	if (count == 0) {
		cout << "�����" << endl;
	}
	else {
		for (int i = 0; i < count; i++) {
			if (str[i].removed) continue;
			str[i].print();
		}
	}
}

int lineSearch(DATA* str, int size, int passportNumber) {
	for (int i = 0; i < size; i++) {
		if (str[i].number == passportNumber) return i;
	}
	return -1;
}

int binarySearch(DATA* str, int size, int passportNumber) {
	int L = 0;
	int R = size - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (str[mid].number == passportNumber) return mid;
		if (str[mid].number > passportNumber) R = mid - 1;
		if (str[mid].number < passportNumber) L = mid + 1;
	}
	return -1;
}

int interpolarSearch(DATA* arr, int size, int passportNumber) {
	int mid;
	int low = 0;
	int high = size - 1;

	while (arr[low].number < passportNumber && arr[high].number > passportNumber) {
		if (arr[high].number == arr[low].number) // ������ �� ������� �� 0
			break;
		mid = low + ((passportNumber - arr[low].number) * (high - low)) / (arr[high].number - arr[low].number);

		if (arr[mid].number < passportNumber)
			low = mid + 1;
		else if (arr[mid].number > passportNumber)
			high = mid - 1;
		else
			return mid;
	}

	if (arr[low].number == passportNumber)
		return low;
	if (arr[high].number == passportNumber)
		return high;

	return -1;
}

bool markAsRemoved(DATA* arr, int* size, int value, bool index = false) {
	bool removed = false;
	for (int i = 0; i < *size; i++) {
		if (index && i == value || arr[i].number == value) {
			arr[i].removed = true;
			removed = true;
		}
	}
	return removed;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RU");
	int elementsCount = 0;
	DATA* data = nullptr;

	int choise = -1;
	bool loop = true;
	while (loop) {
		cout << endl << "�������� ��������:" << endl << "1) ������������� ������ ������" << endl << "2) ��������� ������ � ����" << endl << "3) ��������� ������ �� �����" << endl
			 << "4) ������� ������ ������" << endl << "5) ������� ������� �� �������" << endl << "6) ����� �� ������ ��������" << endl << "7) ����� �� ���������" << endl;
		choise = getSafeInt();
		switch (choise) {
		case MENU_GENERATE: {
			cout << "������� ���������� ���������: ";
			elementsCount = getSafeInt(true);
			generate(data, elementsCount);
			break;
		}
		case MENU_SAVE: {
			if (elementsCount != 0) {
				int result = save(data, elementsCount);
				if (result == -1) {
					cout << "�� ������� ��������� ������ � ���� :(" << endl;
				}
				else {
					cout << "� ���� ���� �������� " << result << " ���������" << endl;
				}
			}
			else {
				cout << "��� ��������� ��� ����������!" << endl;
			}
			break;
		}
		case MENU_LOAD: {
			int result = load(data, &elementsCount);
			if (elementsCount == 0 || result == -1) {
				cout << "�� ������� ��������� ������ �� �����" << endl;
			}
			else {
				cout << "�� ����� ���� ��������� " << elementsCount << " ���������" << endl;
			}
			break;
		}
		case MENU_PRINT: {
			print(data, elementsCount);
			break;
		}
		case MENU_REMOVE: {
			if (elementsCount != 0) {
				cout << "������� ����� ��������: ";
				int number = getSafeInt(true);
				bool result = markAsRemoved(data, &elementsCount, number);
				if (result) {
					cout << "������� ��� ������� �����" << endl;
				}
				else {
					cout << "� ������ ��� �������� � ������ ������� ��������!" << endl;
				}
			}
			else {
				cout << "���������� ��������� �������: ������ ����" << endl;
			}
			break;
		}
		case MENU_SEARCH: {
			if (elementsCount != 0) {
				cout << "������� ����� ��������: ";
				int number = getSafeInt(true);
				cout << "������� ����� ������: " << endl;
				cout << "1) ����������������" << endl << "2) ��������" << endl << "3) ��������" << endl;
				int method = getSafeInt(true);
				while (method > 3) method = getSafeInt(true);
				int idx = -1;
				if (method == 1) idx = interpolarSearch(data, elementsCount, number);
				if (method == 2) idx = binarySearch(data, elementsCount, number);
				if (method == 3) idx = lineSearch(data, elementsCount, number);

				if (idx == -1 || data[idx].removed) {
					cout << "�������� � ������ ������� �������� ��� � ����� ������ :(" << endl;
				}
				else {
					data[idx].print();
				}
			}
			else {
				cout << "���������� ��������� �����: ������ ����" << endl;
			}

			break;
		}
		case MENU_EXIT: loop = false; break;
		default: {
			cout << "�������� �����" << endl;
		}
		}
		choise = -1;
	}


	return 0;
}