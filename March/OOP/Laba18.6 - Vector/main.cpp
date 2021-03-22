#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	system("chcp 1251>nul");
	Vector a(5);
	cout << a << endl;
	cin >> a;
	cout << a << endl;

	Vector b(7);
	cout << b << endl;
	b = a;
	cout << b << endl;
	b[0] = 1970;
	cout << b << endl;

	Vector c(10);
	c = a * 5;
	cout << c << endl;
	cout << "Len 'a': " << a() << endl << "Len 'b': " << b() << endl << "Len 'c': " << c() << endl;

	for (Iterator i = b.first(); i != b.last(); i++)
		cout << *i << " ";

	return 0;
}