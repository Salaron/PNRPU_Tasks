#include <iostream>
#include "Pair.h"
#include "Complex.h"

using namespace std;

int main() {
	system("chcp 1251>nul");
	Pair a;
	cin >> a;
	cout << a;
	Pair b(2, 4);
	cout << b << endl;
	Pair sum = a.sum(b);
	cout << "a + b, c + d = " << sum << endl;

	Complex c;

	return 0;
}