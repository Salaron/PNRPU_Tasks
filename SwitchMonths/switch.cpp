#include <iostream>
#include <string>

using namespace std;

enum MONTHS {
	MONTH_JANUARY = 1,
	MONTH_FEBRUARY,
	MONTH_MARCH,
	MONTH_APRIL,
	MONTH_MAY,
	MONTH_JUNE,
	MONTH_JULY,
	MONTH_AUGUST,
	MONTH_SEPTEMBER,
	MONTH_OCTOBER,
	MONTH_NOVEMBER,
	MONTH_DECEMBER
};

int main()
{
	setlocale(LC_ALL, "");
	int num = 0;
	while (num <= 0 || num >= 13) {
		cout << "������� ����� ������: ";
		cin >> num;
	}

	switch (num) {
	case MONTH_JANUARY:		cout << "������" << endl;
	case MONTH_FEBRUARY:	cout << "�������" << endl;
	case MONTH_MARCH:		cout << "����" << endl;
	case MONTH_APRIL:		cout << "������" << endl;
	case MONTH_MAY:			cout << "���" << endl;
	case MONTH_JUNE:		cout << "����" << endl;
	case MONTH_JULY:		cout << "����" << endl;
	case MONTH_AUGUST:		cout << "������" << endl;
	case MONTH_SEPTEMBER:	cout << "�������� (�����)" << endl;
	case MONTH_OCTOBER:		cout << "�������" << endl;
	case MONTH_NOVEMBER:	cout << "������" << endl;
	case MONTH_DECEMBER:	cout << "�������" << endl;
	}
	

	return 0;
}