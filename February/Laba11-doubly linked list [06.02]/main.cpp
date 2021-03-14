#include <iostream>
#include <list>
#include <time.h>
#include <iterator>
#include "List.h"

using namespace std;

List* createList(int size) {
	List* head = new List;
	head->value = rand() % 100;
	List* p = head;
	for (int i = 1; i < size; i++) {
		List* body = new List;
		p->next = body;
		body->value = rand() % 100;
		body->prev = p;
		p = body;
	}
	return head;
}

void createSTLlist(list<int>& stl, int size) {
	for (int i = 0; i < size; i++) {
		stl.push_back(rand() % 100);
	}
}

void printList(List* first) {
	List* element = first;
	while (element != nullptr) {
		cout << element->value << " ";
		element = element->next;
	}
	cout << endl;
}

bool remove(List*& head) {
	List* element = head;
	bool removed = false;
	while (element != nullptr && !removed) {
		if (element->value % 2 == 0) {
			List* t = element;
			if (element->prev) {
				element->prev->next = t->next;
				element->next->prev = t->prev;	
			}
			else {
				head = element->next;
			}
			delete t;
			removed = true;
		}
		else {
			element = element->next;
		}	
	}
	return removed;
}

bool removeStl(list<int>& stl) {
	list<int> additional;
	bool removed = false;
	for (list<int>::iterator it = stl.begin(); it != stl.end() && !removed; ++it) {
		if ((*it % 2) == 0) {
			removed = true;
			additional.push_back(*it);
		}
	}
	if (additional.size() > 0) stl.remove(additional.back());
	return removed;
}

int main()
{
	system("chcp 1251>nul");
	srand(time(0));
	int size = 0;
	while (size <= 0) {
		cout << "Введите количество элементов двунаправленного списка: ";
		cin >> size;
	}
	cout << "1. Реализация через структуру" << endl;
	List* structList = createList(size);
	printList(structList);
	remove(structList);
	printList(structList);

	cout << endl << "2. Реализация через STL библиотеку" << endl;
	list<int> stlList;
	createSTLlist(stlList, size);
	copy(stlList.begin(), stlList.end(), ostream_iterator<int>(cout, " ")); // print stl list
	cout << endl;
	removeStl(stlList);
	copy(stlList.begin(), stlList.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
