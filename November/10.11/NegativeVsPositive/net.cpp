#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	int founded = false;
	int flag = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			if (!founded) founded = true;
		}
		if (a > 0 && !founded) flag = 1;
		else if (a < 0) flag = -1;
		else if (a == 0) flag = 0;
	}
	return 0;
}