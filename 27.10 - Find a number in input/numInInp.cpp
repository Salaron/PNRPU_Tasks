#include <iostream>

using namespace std;

int main()
{
	setlocale(NULL, "RU");
	int N = 0;
	cout << "������� ����������� �����: ";
	cin >> N;
	while (N <= 0) {
		cout << "����� ������ ���� �����������!" << endl << "������� ����������� �����: ";
		cin >> N;
	}
	int a;
	cout << "������� ����� �� 0 �� 9, ������� ����� �����: ";
	cin >> a;
	while (a < 0 || a > 9) {
		cout << "����� ������ ���� �� 0 �� 9!" << endl << "������� ����� �� 0 �� 9, ������� ����� �����: ";
		cin >> a;
	}
	int reserv = N;
	bool founded = false;
	while (!founded && N > 0) {
		if (N % 10 == a) {
			founded = true;
		}
		N /= 10;
	}

	if (!founded) {
		cout << "� ����� " << reserv << " ��� ����� " << a << endl;
	}
	else {
		cout << "� ����� " << reserv << " ����� " << a << " ������������" << endl;
	}

	return 0;
}