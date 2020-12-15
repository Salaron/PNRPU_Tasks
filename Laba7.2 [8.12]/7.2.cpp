#include <iostream>
#include <time.h>
#include <cstdarg>
#include <windows.h>

using namespace std;

double len(POINT a, POINT b)
{
	return sqrt(abs(pow(b.x - a.x, 2) - pow(b.y - a.y, 2)));
}

// (7; 7) (11; 1) (2; 2) (7;3)
bool belong(POINT a, POINT b, POINT c, POINT m)
{
	bool f1 = signbit((double)(a.x - m.x) * (b.y - a.y) - (b.x - a.x) * (a.y - m.y));
	bool f2 = signbit((double)(b.x - m.x) * (c.y - b.y) - (c.x - b.x) * (b.y - m.y));
	bool f3 = signbit((double)(c.x - m.x) * (a.y - c.y) - (a.x - c.x) * (c.y - m.y));
	return f1 == f2 && f2 == f3;
}

bool belong(POINT m, int argc, ...)
{
	va_list ap;

	bool res = false;
	POINT last;

	va_start(ap, argc);
	for (int i = 0; i < argc; i++) {
		if (i + 1 == argc) {
			last = va_arg(ap, POINT);
		}
		else {
			POINT l = va_arg(ap, POINT);
		}
	}
	va_end(ap);

	va_start(ap, argc);
	for (int i = 0; i < argc; i++) {
		POINT p = va_arg(ap, POINT);
		if ((((p.y <= m.y) && (m.y < last.y)) || ((last.y <= m.y) && (m.y < p.y))) &&
			(((last.y - p.y) != 0) && (m.x > ((last.x - p.x) * (m.y - p.y) / (last.y - p.y) + p.x))))
			res = !res;
	}
	va_end(ap);
	return res;
}


int GetInt()
{
	int res;
	if (!(cin >> res) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите целое число" << endl;
	}
	return res;
}

void PrintCoord(POINT p) {
	cout << "(" << p.x << "; " << p.y << ") ";
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	cout << "Вычисление длины стороны по координатам её точек" << endl;
	POINT a, b;
	cout << "Введите координату X первой точки: ";
	a.x = GetInt();
	cout << "Введите координату Y первой точки: ";
	a.y = GetInt();
	cout << "Введите координату X второй точки: ";
	b.x = GetInt();
	cout << "Введите координату Y второй точки: ";
	b.y = GetInt();

	cout << "Длина стороны = " << len(a, b) << endl << endl;

	cout << "Проверка принадлежности точки М треугольнику" << endl;
	POINT t1, t2, t3, m;
	cout << "Введите координату X первой точки треугольника: ";
	t1.x = GetInt();
	cout << "Введите координату Y первой точки треугольника: ";
	t1.y = GetInt();
	cout << "Введите координату X второй точки треугольника: ";
	t2.x = GetInt();
	cout << "Введите координату Y второй точки треугольника: ";
	t2.y = GetInt();
	cout << "Введите координату X третьей точки треугольника: ";
	t3.x = GetInt();
	cout << "Введите координату Y третьей точки треугольника: ";
	t3.y = GetInt();
	cout << "Введите координату X точки М: ";
	m.x  = GetInt();
	cout << "Введите координату Y точки М: ";
	m.y  = GetInt();
	cout << "Точка М";
	PrintCoord(m);
	cout << (belong(t1, t2, t3, m) == true ? "принадлежит " : "не принадлежит ")
		 << "треугольнику с координатами A";
	PrintCoord(t1);
	cout << "B";
	PrintCoord(t2);
	cout << "C";
	PrintCoord(t3);
	cout << endl << endl;

	cout << "Принадлежит ли точка М (5; 3) выпуклому многоугольнику с координатами: " << endl;

	POINT points[5];
	points[0].x = 2;
	points[0].y = 1;
	points[1].x = 4;
	points[1].y = 6;
	points[2].x = 7;
	points[2].y = 7;
	points[3].x = 6;
	points[3].y = 4;
	points[4].x = 4;
	points[4].y = 1;

	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0: cout << "A"; break;
		case 1: cout << "B"; break;
		case 2: cout << "C"; break;
		case 3: cout << "D"; break;
		case 4: cout << "E"; break;
		}
		PrintCoord(points[i]);
	}
	
	m.x = 5;
	m.y = 3;
	bool res = belong(m, 5, points[0], points[1], points[2], points[3], points[4]);
	cout << endl << "Точка " << (belong(m, 5, points[0], points[1], points[2], points[3], points[4]) == true ? "принадлежит " : "не принадлежит ");
	return 0;
}