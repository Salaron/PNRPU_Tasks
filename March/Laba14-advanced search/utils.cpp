#include <iostream>
#include "utils.h"

using namespace std;

int getRandomInt(int start, int end) {
	return rand() % (end + 1 - start) + start;
}

int getSafeInt(bool strict) {
	int res;
	while (!(cin >> res) || (cin.peek() != '\n') || (strict == true && res <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите целое число, которое больше нул€!" << endl;
	}
	cin.get();
	return res;
}