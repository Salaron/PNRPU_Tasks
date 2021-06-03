#include <iostream>
#include <deque>
#include <queue>
#include "Time.h"
#include "../Laba18.7 - Templates/Vector.h"
#include "VectorQueue.h"

using namespace std;

template <typename T>
void PrintDQ(deque<T> dq) {
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << "; ";
	cout << endl;
}

template <typename T>
void PrintQ(queue<T> q) {
	while (!q.empty()) {
		cout << q.front() << "; ";
		q.pop();
	}
	cout << endl;
}

void Task1() {
	deque<int> dq;
	int size = 1;
	while (size <= 2) {
		cout << "Введите размер двунаправленной очереди: "; cin >> size;
	}
	for (int i = 0; i < size; i++) 
		dq.push_back(rand() % 100);
	PrintDQ(dq);
	// remove front & back
	dq.pop_back();
	dq.pop_front();
	cout << "Двунаправленная очередь после удаления первого и последнего элемента: " << endl;
	PrintDQ(dq);
}

void Task2() {
	deque<Time> dq;
	int size = 1;
	while (size <= 2) {
		cout << "Введите размер двунаправленной очереди: "; cin >> size;
	}
	for (int i = 0; i < size; i++)
		dq.push_back(Time(rand() % 60, rand() % 60));
	PrintDQ(dq);
	dq.pop_front();
	cout << "Двунаправленная очередь после удаления последнего элемента: " << endl;
	PrintDQ(dq);
}

void Task3() {
	Vector<int> vec(5, 0);
	for (int i = 0; i < 5; i++) {
		vec[i] = rand() % 100;
	}
	cout << vec << endl;
	int max = vec[0];
	for (int i = 0; i < vec(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
	}
	cout << "Max =" << max << endl;
	vec.push(max);
	cout << vec << endl;
}

void Task4() {
	queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(rand() % 100);
	}
	PrintQ(q);
	int val;
	cout << "Введите значение элемента, который нужно удалить: "; cin >> val;
	queue<int> temp;
	for (int i = 0; i < 10; i++) {
		if (q.front() != val) {
			temp.push(q.front());
		}
		q.pop();
	}
	q = temp;
	PrintQ(q);
}

void Task5() {
	VectorQueue<int> vec(10);
	vec.Print();
	cout << "Среднее значение: ";
	int avg = vec.FindAverageValue();
	cout << avg << endl;
	cout << "Изменённый вектор: " << endl;
	vec = vec + avg;
	vec.Print();
}

int main() {
	system("chcp 1251>nul");
	string input = "";
	while (input[0] != '0') {
		cout << "1) Задание 1" << endl;
		cout << "2) Задание 2" << endl;
		cout << "3) Задание 3" << endl;
		cout << "4) Задание 4" << endl;
		cout << "5) Задание 5" << endl;
		cout << "> "; cin >> input;
		switch (input[0]) {
		case '0': break;
		case '1': Task1(); break;
		case '2': Task2(); break;
		case '3': Task3(); break;
		case '4': Task4(); break;
		case '5': Task5(); break;
		}
	}
	return 0;
}