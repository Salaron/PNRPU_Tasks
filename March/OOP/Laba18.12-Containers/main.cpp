#include <iostream>
#include <map>
#include "Time.h"
#include "Vector.h"

using namespace std;

void PrintMap(map<int, int> m) {
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		cout << (*it).first << " = " << (*it).second << endl;
	}
}


void Task1() {
	map<int, int> m;
	for (int i = 0; i < 10; i++) {
		m.insert(make_pair(i + 1, rand() % 100));
	}
	PrintMap(m);

	int max = m[1];
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		if ((*it).second > max) {
			max = (*it).second;
		}
	}
	cout << "Максимальный элемент в контейнере: " << max << endl;
	m.insert(make_pair(m.size() + 1, max));
	cout << "Контейнер после добавление максимального элемента:" << endl;
	PrintMap(m);
}

void Task2() {
	map<int, Time> m;
	for (int i = 0; i < 10; i++) {
		m.insert(make_pair(i + 1, Time(rand() % 60, rand() % 60)));
	}
	for (map<int, Time>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << (*it).first << " = " << (*it).second << endl;
	}

	int key = -1;
	while (key < 0 || key > m.size()) {
		cout << "Введите ключ, по которому нужно удалить элемент: ";
		cin >> key;
	}

	map<int, Time>::iterator it = m.begin();
	while (it != m.end()) {
		if ((*it).first == key) {
			it = m.erase(it);
		}
		else {
			it++;
		}
	}
	cout << "Ассоциативный массив после удаления:" << endl;
	for (map<int, Time>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << (*it).first << " = " << (*it).second << endl;
	}
}

void Task3() {
	Vector<int> vec(10);
	vec.PrintMap();
	int avg = vec.FindAverageValue();
	cout << "Среднее арифметическое = " << avg << endl;
	vec + avg;
	cout << "Контейнер после изменения:" << endl;
	vec.PrintMap();
}

int main() {
	system("chcp 1251>nul");
	string input = "";
	while (input[0] != '0') {
		cout << "1) Задание 1" << endl;
		cout << "2) Задание 2" << endl;
		cout << "3) Задание 3" << endl;
		cout << "> "; cin >> input;
		switch (input[0]) {
		case '0': break;
		case '1': Task1(); break;
		case '2': Task2(); break;
		case '3': Task3(); break;
		}
	}
	return 0;
}