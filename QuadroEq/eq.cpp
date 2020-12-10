#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    cout << "–ешение квадратных уравнений вида a * x^2 + b * x + c = 0" << endl;
    double a, b, c;
    cout << "¬ведите a: ";
    cin >> a;
    cout << "¬ведите b: ";
    cin >> b;
    cout << "¬ведите c: ";
    cin >> c;
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-1 * b - sqrt(D)) / (2 * a);
        double x2 = (-1 * b + sqrt(D)) / (2 * a);
        cout << "”равнение имеет два корн€: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0) {
        double x = (-1 * b) / (2 * a);
        cout << "”равнение имеет один корень: " << endl;
        cout << "x = " << x;
    }
    else if (D < 0) {
        cout << "–ешений нет" << endl;
    }
    return 0;
}