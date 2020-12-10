#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    cout << "Решение квадратных уравнений вида a * x^2 + b * x + c = 0" << endl;
    double a, b, c;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-1 * b - sqrt(D)) / (2 * a);
        double x2 = (-1 * b + sqrt(D)) / (2 * a);
        cout << "Уравнение имеет два корня: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        double x = (-1 * b) / (2 * a);
        cout << "Уравнение имеет один корень: " << endl;
        cout << "x = " << x;
    }
    else if (D < 0) {
        cout << "Решений нет" << endl;
    }
    return 0;
}