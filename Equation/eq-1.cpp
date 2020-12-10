#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double F(double x) { return 3 * x - 4 * log(x) - 5; }

int main()
{
    setlocale(LC_ALL, "");
    cout << "Решение нелинейного уравнения e^x - e^-x - 2 = 0 методом половинного деления" << endl;
    double A, B;
    cout << "Введите левую границу отрезка: ";
    cin >> A;
    cout << "Введите правую границу отрезка: ";
    cin >> B;
    double eps = 0.000001; // 10 ^ -6
    if (F(A) * F(B) > 0) {
        cout << "На указанном отрезке нет корня!" << endl;
        return 0;
    }

    double x = (A + B) / 2;
    while (abs(F(x)) > eps) {
        x = (A + B) / 2;
        if (F(A) * F(x) < 0)
            B = x;
        else
            A = x;
    }
     
    cout << fixed << setprecision(4);
    cout << "Ответ: " << x << endl;
}