#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

struct Queue {
	int value = 0;
	Queue* prev = nullptr;
};

void createSTL(queue<int>& q, int size) {
	for (int i = 0; i < size; i++) {
		int a = rand() % 100;
		cout << a << " ";
		q.push(a);
	}
	cout << endl;
}

Queue* create(int size) {
	Queue* p = new Queue;
	Queue* first = p;
	p->value = rand() % 100;
	for (int i = 1; i < size; i++) {
		Queue* tmp = new Queue;
		tmp->value = rand() % 100;
		p->prev = tmp;
		p = tmp;
	}
	return first;
}

void printSTL(queue<int>& q) {
	queue<int> copy = q;
	while (!copy.empty()) {
		cout << copy.front() << " ";
		copy.pop();
	}
	cout << endl;
}

void print(Queue* q) {
	while (q != nullptr) {
		cout << q->value << " ";
		q = q->prev;
	}
	cout << endl;
}

void solveSTL(queue<int>& q) {
	queue<int> tmp;
	bool isFound = false;
	while (!q.empty()) {
		int c = q.front();
		if (c % 2 == 0 && !isFound) {
			isFound = true;
		}
		else {
			tmp.push(c);
		}
		q.pop();
	}
	q = tmp;
}

void solve(Queue*& l) {
	Queue* q = l;
	Queue* last = nullptr;
	bool removed = false;
	while (q != nullptr && !removed) {
		if (q->value % 2 == 0) {
			Queue* thiz = q;

			if (last != nullptr) {
				last->prev = q->prev;
			}
			else {
				l = q->prev;
			}
			q = q->prev;
			
			delete thiz;
			removed = true;
		}
		else {
			last = q;
			q = q->prev;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(0));
	int size = 0;
	while (size <= 0) {
		cout << "Введите количество элементов очереди: ";
		cin >> size;
	}
	cout << "1. Реализация через структуру" << endl;
	// struct
	Queue* qq = create(10);
	print(qq);
	solve(qq);
	cout << "Элементы очереди после удаления первого элемента с чётным информационным полем: " << endl;
	print(qq);

	cout << "2. Реализация через STL библиотеку" << endl;
	// stl
	queue<int> q;
	createSTL(q, 10);
	printSTL(q);
	solveSTL(q);
	printSTL(q);
	return 0;
}