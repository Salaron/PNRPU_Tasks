#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	for(;;) {
		cout << "������� ����� ������� ��������: ";
		cin >> n;
		if (n > 1) break;
		cout << "������� ������ ���� ������������� ������ � ���� ������ 1!" << endl;
	}
	

	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}
	cout << endl;

	for (int i = 1; i <= n - 2; i++) {
		cout << "*";
		for (int j = 1; j <= n - 2; j++) {
			cout << "  ";
		}
		cout << " *" << endl;
	}

	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}
	cout << endl;

	return 0;
}