#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>

using namespace std;

inline double F(double x) { return exp(x) - exp(-1 * x) - 2; }
inline double FF(double x) { return exp(x) - exp(-1 * x); } // производная

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "Решение нелинейного уравнения e^x - e^-x - 2 = 0 методом Ньютона" << endl;
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

    double x = (left + right) / 2;
    while (abs(F(x)) > eps) {
        x -= F(x) / FF(x);
    }

    cout << fixed << setprecision(4);
    cout << "Ответ: " << x << endl;
}