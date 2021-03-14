#pragma once
#include <iostream>

using namespace std;

enum MENU {
	MENU_GENERATE = 1,
	MENU_SAVE,
	MENU_LOAD,
	MENU_PRINT,
	MENU_REMOVE,
	MENU_SEARCH,
	MENU_EXIT
};

struct DATA {
	string fio;
	string birth;
	string number;
	bool removed = false;

	void print() {
		cout << "���:          \t" << fio << endl;
		cout << "���� ��������:\t" << birth << endl;
		cout << "����� ��������:\t" << number << endl << endl;
	}
};

int getRandomInt(int start, int end);
int getSafeInt(bool strict = false);