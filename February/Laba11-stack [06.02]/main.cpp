#include <iostream>
#include <time.h>
#include <stack>

using namespace std;

struct Stack {
	double value;
	Stack* prev = nullptr;
};


double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Stack* create(int size) {
	Stack* p = new Stack;
	p->value = fRand(-100, 100);

	Stack* last = p;
	for (int i = 1; i < size; i++) {
		Stack* tmp = new Stack;
		tmp->value = fRand(-100, 100);
		tmp->prev = last;
		last = tmp;
		p = last;
	}
	return last;
}

void createSTL(stack<double>& s, int size) {
	for (int i = 0; i < size; i++) {
		s.push(fRand(-100, 100));
	}
}

void print(Stack* s) {
	while (s != nullptr) {
		cout << s->value << " ";
		s = s->prev;
	}
	cout << endl;
}

void printSTL(stack<double>& s) {
	stack<double> copy = s;
	while (!copy.empty()) {
		cout << copy.top() << " ";
		copy.pop();
	}
	cout << endl;
}

void solve(Stack*& first) {
	Stack* s = first;
	Stack* last = nullptr;
	while (s != nullptr) {
		if (s->value < 0) {
			Stack* newE = new Stack;

			newE->prev = s;
			newE->value = 0;

			if (last != nullptr) {
				last->prev = newE;
			}
			else {
				first = newE;
			}
		}
		last = s;
		s = s->prev;
	}
}

void solveSTL(stack<double>& s) {
	stack<double> tmp;

	while (!s.empty()) {
		double el = s.top();
		tmp.push(el);
		if (el < 0) {
			tmp.push(0);
		}
		s.pop();
	}
	s = tmp;
}

int main() {
	system("chcp 1251>nul");
	srand(time(0));
	int size = 0;
	while (size <= 0) {
		cout << "Введите количество элементов стека: ";
		cin >> size;
	}
	cout << "1. Реализация через структуру" << endl;

	Stack* s = create(size);
	print(s);
	solve(s);
	cout << "Стек после добавления нулей после каждого отрицательного элемента:" << endl;
	print(s);

	cout << endl << "2. Реализация через STL библиотеку" << endl;
	// stl
	stack<double> ss;
	createSTL(ss, size);
	printSTL(ss);
	solveSTL(ss);
	cout << "Стек после добавления нулей после каждого отрицательного элемента:" << endl;
	printSTL(ss);

	return 0;
}