#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    cout << "������� ���������� ��������� ���� a * x^2 + b * x + c = 0" << endl;
    double a, b, c;
    cout << "������� a: ";
    cin >> a;
    cout << "������� b: ";
    cin >> b;
    cout << "������� c: ";
    cin >> c;
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-1 * b - sqrt(D)) / (2 * a);
        double x2 = (-1 * b + sqrt(D)) / (2 * a);
        cout << "��������� ����� ��� �����: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        double x = (-1 * b) / (2 * a);
        cout << "��������� ����� ���� ������: " << endl;
        cout << "x = " << x;
    }
    else if (D < 0) {
        cout << "������� ���" << endl;
    }
    return 0;
}