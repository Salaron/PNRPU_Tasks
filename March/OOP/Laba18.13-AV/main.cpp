#include <iostream>
#include <deque>
#include <queue>
#include "Time.h"
#include <algorithm>

using namespace std;

template <typename iter>
iter max_element(iter& first, iter& last)
{
	if (first == last) return last;
	iter largest = first;

	while (first != last) {
		if (*largest < *first)
			largest = first;
		first++;
	}
	return largest;
}

template <typename T>
void PrintDQ(deque<T> dq) {
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << "; ";
	cout << endl;
}


void Task1() {
	deque<Time> dq;
	deque<Time> copy;
	for (int i = 0; i < 10; i++)
		dq.push_back(Time(rand() % 100, rand() % 100));
	PrintDQ(dq);
	deque<Time>::iterator max = max_element(dq.begin(), dq.end());
	cout << "Максимальный элемент: " << *max << endl;
	dq.insert(dq.end(), *max);
	PrintDQ(dq);
}

void Task2() {
	queue<Time> q;
	for (int i = 0; i < 10; i++) {
		q.push(Time(rand() % 100, rand() % 100));
	}

}

void Task3() {

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