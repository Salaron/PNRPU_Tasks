#include <iostream>
#include "Time.h"

using namespace std;

int main() {
	system("chcp 1251>nul");
	Time a;
	Time b; 
	Time c; 
	cin >> a;
	cin >> b;
	++a;
	cout << "'a' after increment: ";
	cout << a << endl;
	c = (a++) + b;
	cout << "a = "<< a << endl;
	cout << "b = "<< b << endl;
	cout << "c = "<< c << endl;
	return 0;
}