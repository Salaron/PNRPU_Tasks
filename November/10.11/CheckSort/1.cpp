#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251>nul");
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