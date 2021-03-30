#include "Print.h"
#include "Event.h"
#include <iostream>

using namespace std;

Print::Print() {
	m_name = "";
	m_author = "";
}

Print::Print(string name, string author) {
	m_name = name;
	m_author = author;
}

Print::Print(const Print& print) {
	m_name = print.m_name;
	m_author = print.m_author;
}

Print::~Print() {
}

string Print::getName() {
	return m_name;
}

string Print::getAuthor() {
	return m_author;
}

void Print::setName(string name) {
	m_name = name;
}

void Print::setAuthor(string author) {
	m_author = author;
}

Print& Print::operator = (const Print& print) {
	if (&print == this) return *this;
	m_author = print.m_author;
	m_name = print.m_name;
	return *this;
}

void Print::Show() {
	cout << "Book name: " << m_name << endl;
	cout << "Author: " << m_author << endl;
}

void Print::Input() {
	cout << "Book name: "; cin >> m_name;
	cout << "Author: "; cin >> m_author;
}

void Print::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmdName: {
			cout << "Book Name: " << getName() << endl;
			break;
		}
		}
	}
}