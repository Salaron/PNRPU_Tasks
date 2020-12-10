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
		cout << "Введите номер месяца: ";
		cin >> num;
	}

	switch (num) {
	case MONTH_JANUARY:		cout << "Январь" << endl;
	case MONTH_FEBRUARY:	cout << "Февраль" << endl;
	case MONTH_MARCH:		cout << "Март" << endl;
	case MONTH_APRIL:		cout << "Апрель" << endl;
	case MONTH_MAY:			cout << "Май" << endl;
	case MONTH_JUNE:		cout << "Июнь" << endl;
	case MONTH_JULY:		cout << "Июль" << endl;
	case MONTH_AUGUST:		cout << "Август" << endl;
	case MONTH_SEPTEMBER:	cout << "Сентябрь (горит)" << endl;
	case MONTH_OCTOBER:		cout << "Октябрь" << endl;
	case MONTH_NOVEMBER:	cout << "Ноябрь" << endl;
	case MONTH_DECEMBER:	cout << "Декабрь" << endl;
	}
	

	return 0;
}