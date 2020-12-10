#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n;
	for (;;) {
		cout << "Введите цифру: ";
		cin >> n;
		if (n >= 0 && n <= 9)
			break;
		else
			cout << "Введена не цифра!" << endl;
	}

	switch (n) {
	case 0:
	case 1:
		cout << 1 << " ";
	case 2:
	case 3:
		cout << 3 << " ";
	case 4:
	case 5:
		cout << 5 << " ";
	case 6:
	case 7:
		cout << 7 << " ";
	case 8:
	case 9:
		cout << 9 << " ";
	}

	return 0;
}