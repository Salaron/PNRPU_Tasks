#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int m = 0;
	int ind = 0;
	for (int i = 1; i <= 5; i++) {
		int n = -1;
		do {
			cout << "������� ������� ����������� " << i << " �����: ";
			cin >> n;
			if (n >= 0) break;
			cout << "������� ����������� ����� �� ����� ���� �������������" << endl;
		} while (n < 0);
		
		if (n >= m) {
			m = n;
			ind = i;
		}
	}
	cout << "����� ��������� ����� ����� ����� " << ind << " � � ������� ����������� ����� " << m << endl;
	return 0;
}