#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	for (;;) {
		cout << "������� ���������� ����� � ������������������: ";
		cin >> n;
		if (n > 0) break;
		cout << "���������� ����� ������ ���� ������ ����!" << endl;
	}
	int z = 0;
	cout << "������� �����, ������� ����� �����: ";
	cin >> z;

	bool exists = false;
	while (n--) {
		int a;
		cin >> a;
		if (a == z) exists = true;
	}

	if (exists) {
		cout << "����� " << z << " ������������ � ������������������" << endl;
	}
	else {
		cout << "����� " << z << " ��� � ������ ������������������" << endl;
	}

	return 0;
}