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
	int sum = 0;
	int reserv = N;
	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}
	cout << "� ����� " << reserv << " ����� ���� ����� " << sum << endl;
	return 0;
}