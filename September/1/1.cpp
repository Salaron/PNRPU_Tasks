#include "iostream"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int n;
	cin >> n;
	if (n <= 3 || n % 2 != 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}

	return 0;
}