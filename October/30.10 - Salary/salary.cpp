#include <iostream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int z, s;
	cout << "Зарплата в рублях: ";
	cin >> z;
	while (z < 0) {
		cout << "Зарплата не может быть отрицательной!" << "Зарплата в рублях: ";
		cin >> z;
	}
	cout << "Стаж работы: ";
	cin >> s;
	while (z < 0) {
		cout << "Стаж работы не может быть отрицательным!" << "Стаж работы: ";
		cin >> z;
	}

	cpr::Response r = cpr::Get(cpr::Url{ "https://api.exchangeratesapi.io/latest?base=USD" });
	auto j3 = nlohmann::json::parse(r.text);
	cout << "Текущий курс доллара: " << j3["rates"]["RUB"] << endl;

	float koef = 0;
	switch (s) {
		case 1:
		case 2: {
			koef = 0.5;
			break;
		}
		case 3:
		case 4: {
			koef = 0.6;
			break;
		}
		case 5:
		case 6:
		case 7: {
			koef = 0.8;
			break;
		}
		default: {
			koef = 1.0;
		}
	}

	float rub = z * koef;
	float d = rub / j3["rates"]["RUB"];
	cout << "На больничном выплачивается " << rub << " рублей или " << d << " долларов" << endl;

	return 0;
}