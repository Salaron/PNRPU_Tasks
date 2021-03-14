#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double F(double x)  { return exp(x) - exp(-1 * x) - 2; }

int main()
{
	system("chcp 1251>nul");
    cout << "Решение нелинейного уравнения e^x - e^-x - 2 = 0 методом итераций" << endl;
    double left, right;
    cout << "Введите левую границу отрезка: ";
    cin >> left;
    cout << "Введите правую границу отрезка: ";
    cin >> right;
    double eps = 0.000001; // 10 ^ -6
    if (F(left) * F(right) > 0) {
        cout << "На указанном отрезке нет корня!" << endl;
        return 0;
    }

    double x = left;
    double x0 = right;
    for (;;) {
        x = log(1 + sqrt(2));
        if (abs(x - x0) < eps) break;
        x0 = x;
    }
    cout << fixed << setprecision(4);
    cout << "Ответ: " << x << endl;
}