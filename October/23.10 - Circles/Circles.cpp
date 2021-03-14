#include <iostream>
#include <math.h>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double D = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (r1 + r2 < D || abs(r1 - r2) > D) {
		cout << "Окружности не имеют точек пересечения!" << endl;
	}
	else if (x1 == x2 && y1 == y2 && r1 == r2) {
		cout << "Окружности совпадают" << endl;
	}
	else {
		bool multiDot = false;
		if (r1 + r2 == D || abs(r1 - r2) == D) {
			cout << "Окружности пересекаются в одной точке: ";
		}
		else {
			cout << "Окружности пересекаются в двух точках: ";
			multiDot = true;
		}
		
		double a = (pow(r1, 2) - pow(r2, 2) + pow(D, 2)) / (2 * D);
		double h = sqrt(pow(r1, 2) - pow(a, 2));

		double x3 = x1 + (a / D) * (x2 - x1);
		double y3 = y1 + (a / D) * (y2 - y1);

		double x4 = x3 + (h / D) * (y2 - y1);
		double y4 = y3 - (h / D) * (x2 - x1);

		cout << fixed;
		cout << setprecision(4);
		cout << "(" << x4 << "; " << y4 << ") ";

		if (multiDot) {
			double x5 = x3 - (h / D) * (y2 - y1);
			double y5 = y3 + (h / D) * (x2 - x1);
			cout << "(" << x5 << "; " << y5 << ")" << endl;
		}
	}

	return 0;
}