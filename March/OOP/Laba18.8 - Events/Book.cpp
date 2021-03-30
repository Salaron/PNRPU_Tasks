#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(): Print() {
	m_pagesCount = 0;
	m_izd = "";
}

Book::Book(string name, string author, string izd, int pagesCount) : Print(name, author) {
	m_izd = izd;
	m_pagesCount = pagesCount;
}

Book::Book(const Book& b) {
	m_author = b.m_author;
	m_name = b.m_name;
	m_pagesCount = b.m_pagesCount;
	m_izd = b.m_izd;
}

Book::~Book() {

}

void Book::Show() {
	cout << "Book name: " << m_name << endl;
	cout << "Author: " << m_author << endl;
	cout << "Izdanie: " << m_izd << endl;
	cout << "Pages count: " << m_pagesCount << endl;
}

void Book::Input() {
	cout << "Book name: "; cin >> m_name;
	cout << "Author: "; cin >> m_author;
	cout << "Izdanie: "; cin >> m_izd;
	cout << "Pages count: "; cin >> m_pagesCount;
}