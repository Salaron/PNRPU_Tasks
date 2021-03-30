#pragma once
#include "Print.h"

class Book : public Print {
protected:
	string m_izd;
	int m_pagesCount;
public:
	Book();
	Book(string name, string author, string izd, int pagesCount);
	Book(const Book& b);
	~Book();

	void Show();
	void Input();
};