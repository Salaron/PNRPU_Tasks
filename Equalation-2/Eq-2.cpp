#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double F(double x) { return exp(x) - exp(-1 * x) - 2; }
inline double FF(double x) { return exp(x) - exp(-1 * x); } // �����������

int main()
{
    setlocale(LC_ALL, "");
    cout << "������� ����������� ��������� e^x - e^-x - 2 = 0 ������� �������" << endl;
    double left, right;
    cout << "������� ����� ������� �������: ";
    cin >> left;
    cout << "������� ������ ������� �������: ";
    cin >> right;
    double eps = 0.000001; // 10 ^ -6

    if (F(left) * F(right) > 0) {
        cout << "�� ��������� ������� ��� �����!" << endl;
        return 0;
    }

    double x = (left + right) / 2;
    while (abs(F(x)) > eps) {
        x -= F(x) / (FF(x) || 1);
    }

    cout << fixed << setprecision(4);
    cout << "�����: " << x << endl;
}