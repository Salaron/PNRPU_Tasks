#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Book.h"

using namespace std;

Vector::Vector() {
	m_begin = nullptr;
	m_current = 0;
	m_size = 0;
}

Vector::Vector(int count) {
	m_begin = new Object*[count];
	m_current = 0;
	m_size = count;
}

Vector::~Vector() {
	if (m_begin != nullptr) delete[] m_begin;
	m_begin = nullptr;
}

void Vector::Add() {
	if (m_size == 0) {
		cout << "Please make a Vector first" << endl;
		return;
	}
	if (m_size == m_current) {
		cout << "Vector is full!" << endl;
		return;
	}
	Object* p;
	cout << "Выберите тип элемента: " << endl;
	cout << "1) Печатное издание (print)" << endl;
	cout << "2) Книга (book)" << endl;
	int choise;
	cin >> choise;
	if (choise == 1) {
		Print* t = new Print;
		t->Input();
		p = t;
	}
	else {
		Book* t = new Book;
		t->Input();
		p = t;
	}

	if (m_current < m_size) {
		m_begin[m_current] = p;
		m_current++;
	}
}

void Vector::Show() {
	if (m_current == 0) {
		cout << "Empty" << endl;
	}
	else {
		Object** p = m_begin;
		for (int i = 0; i < m_current; i++) {
			(*p)->Show();
			p++;
			cout << endl;
		}
	}
}

void Vector::Del() {
	if (m_size == 0) {
		cout << "Please make a Vector first" << endl;
	}
	if (m_current > 0) m_current--;
}

int Vector::operator () () {
	return m_current;
}

void Vector::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		Object** p = m_begin;
		for (int i = 0; i < m_current; i++) {
			(*p)->HandleEvent(event);
			p++;
		}
	}
}