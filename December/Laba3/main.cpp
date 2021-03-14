#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double F(double x) { return exp(x) - exp(x * -1) - 2; }
inline double FF(double x) { return exp(x * -1) + exp(x); } // производная

double halfDivision(double A, double B, double eps)
{
    double x = (A + B) / 2;
    while (abs(F(x)) > eps) {
        x = (A + B) / 2;
        if (F(A) * F(x) < 0)
            B = x;
        else
            A = x;
    }
    return x;
}

double newton(double A, double B, double eps)
{
    double x = (A + B) / 2;
    while (abs(F(x)) > eps) {
        x -= F(x) / FF(x);
    }
    return x;
}

double iteration(double A, double B, double eps)
{
    double x0, x = (A + B) / 2;
    do
    {
        x0 = x;
        x = log(1 + sqrt(2));
    } while (abs(x - x0) > eps);
    return x;
}

int main()
{
	system("chcp 1251>nul");
    cout << "Решение нелинейного уравнения e^x - e^-x - 2 = 0" << endl;
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

    cout << fixed << setprecision(4);
    cout << "Решение методом половинного деление: " << halfDivision(A, B, eps) << endl;
    cout << "Решение методом Ньютона: " << newton(A, B, eps) << endl;
    cout << "Решение методом итераций: " << iteration(A, B, eps) << endl;

    return 0;
}