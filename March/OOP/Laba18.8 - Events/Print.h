#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Print: public Object {
protected:
	string m_name;
	string m_author;
public:
	Print();
	Print(string name, string author);
	Print(const Print& print);
	~Print();

	// selectors
	string getName();
	string getAuthor();

	// setters
	void setName(string name);
	void setAuthor(string author);

	Print& operator = (const Print& print);

	void Show();
	void Input();
	void HandleEvent(TEvent& event);
};