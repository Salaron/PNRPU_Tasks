#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int a, b;
	cin >> a;
	if (a != 0) {
		cin >> b;

		bool f = true;
		while (a < b && f == true) {
			cin >> b;
			f = f && a < b;
			if (f == true) {
				a = b;
			}
		}

	}


	return 0;
}