#include <iostream>

using namespace std;

int main()
{
	setlocale(NULL, "Russian");
	double b;
	cout << "������� �������� b: ";
	cin >> b;
	while (b > 7) {
		cout << "�������� b �� ������ ��������� 7!" << endl << "������� �������� b: ";
		cin >> b;
	}

	if (b > 1) {
		double z1 = (sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4))) / (sqrt(pow(b, 2) - 4) + b + 2);
		cout << "z1 = " << z1 << endl;
	}
	else {
		cout << "z1 �� ���������� -- ���������� ����������� ����� �� �������������� �����" << endl;
	}
	if (b > -2) {
		double z2 = 1 / (sqrt(b + 2));
		cout << "z2 = " << z2 << endl;
	}
	else if (b == -2) {
		cout << "z2 �� ���������� -- ������� �� ����" << endl;
	}
	else {
		cout << "z2 �� ���������� -- ���������� ����������� ����� �� �������������� �����" << endl;
	}

	return 0;
}