#include <iostream>
#include "stack.h"

using namespace std;

void Fill(Stack* stk, int size) {
	// ручное заполнение стека
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " элемент стека: ";
		cin >> *stk;
	}
}

void Solve(Stack* stk) {
	// Добавить в стек после каждого элемента с	отрицательным информационным полем элемент с информационным	полем равным 0
	Stack* tmp = new Stack;
	while (!stk->empty()) {
		double element = stk->top();
		tmp->push(element);
		if (element < 0)
			tmp->push(0);
		stk->pop();
	}
	while (!tmp->empty()) {
		double element = tmp->top();
		stk->push(element);
		tmp->pop();
	}
	delete tmp;
}

int main() {
	system("chcp 1251>nul");
	int size = 0;
	while (size <= 0) {
		cout << "Введите размер стека: ";
		cin >> size;
	}
	Stack* stk = new Stack;
	Fill(stk, size);
	// вывод стека
	cout << *stk;
	// решение
	Solve(stk);
	// вывод результата
	cout << *stk;
	delete stk;
	return 0;
}