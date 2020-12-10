#include <iostream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

using namespace std;

int main()
{
	setlocale(NULL, "RU");
	int z, s;
	cout << "�������� � ������: ";
	cin >> z;
	while (z < 0) {
		cout << "�������� �� ����� ���� �������������!" << "�������� � ������: ";
		cin >> z;
	}
	cout << "���� ������: ";
	cin >> s;
	while (z < 0) {
		cout << "���� ������ �� ����� ���� �������������!" << "���� ������: ";
		cin >> z;
	}

	cpr::Response r = cpr::Get(cpr::Url{ "https://api.exchangeratesapi.io/latest?base=USD" });
	auto j3 = nlohmann::json::parse(r.text);
	cout << "������� ���� �������: " << j3["rates"]["RUB"] << endl;

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
	cout << "�� ���������� ������������� " << rub << " ������ ��� " << d << " ��������" << endl;

	return 0;
}