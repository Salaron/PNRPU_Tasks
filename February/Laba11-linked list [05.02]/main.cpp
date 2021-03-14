#include <iostream>
#include <time.h>
#include "List.h"

#define uint unsigned int

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

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

List* makeList(uint count) {
	List* first = new List;
	first->value = fRand(-100, 100);
	List* p = first;
	for (int i = 1; i < count; i++) {
		List* n = new List;
		n->value = fRand(-100, 100);
		p->next = n;
		p = p->next;
	}
	return first;
}

void printList(List* first) {
	List* element = first;
	while (element != nullptr) {
		cout << element->value << " ";
		element = element->next;
	}
	cout << endl;
}

void addZero(List* element) {
	while (element != nullptr) {
		if (element->value < 0) {
			List* old = element->next;
			List* newL = new List;
			newL->value = 0;
			newL->next = old;

			element->next = newL;
		}
		element = element->next;
	}
}
void removeList(List*& element) {
	while (element != nullptr) {
		List* before = element;
		element = element->next;
		delete before;
	}
}

int main()
{
	system("chcp 1251>nul");
	srand(time(0));

	cout << "Введите количество элементов в списке: ";
	int count = getIntSafe();
	List* list = makeList(count);
	cout << "Сгенерированные информационные поля в списке:" << endl;
	printList(list);

	addZero(list);
	cout << "Информационные поля после добавления нулевых элементов после полей с отрицательными значениями:" << endl;
	printList(list);
	removeList(list);
	return 0;
}