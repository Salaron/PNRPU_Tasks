#include <iostream>
#include <time.h>
#include <cstdarg>

using namespace std;

struct POINT {
	int x;
	int y;
};

double len(struct POINT a, struct POINT b)
{
	return sqrt(pow(b.x - a.x, 2) - pow(b.y - a.y, 2));
}

// (7; 7) (11; 1) (2; 2) (7;3)
bool belong(struct POINT a, struct POINT b, struct POINT c, struct POINT m)
{
	bool f1 = signbit((double)(a.x - m.x) * (b.y - a.y) - (b.x - a.x) * (a.y - m.y));
	bool f2 = signbit((double)(b.x - m.x) * (c.y - b.y) - (c.x - b.x) * (b.y - m.y));
	bool f3 = signbit((double)(c.x - m.x) * (a.y - c.y) - (a.x - c.x) * (c.y - m.y));
	return f1 == f2 && f2 == f3;
}

bool belong(struct POINT m, int argc, ...)
{
	va_list ap;

	bool res = false;
	POINT last;

	va_start(ap, argc);
	for (int i = 0; i < argc; i++) {
		if (i + 2 == argc) {
			last.x = va_arg(ap, int);
			last.y = va_arg(ap, int);
		}
	}
	va_end(ap);

	va_start(ap, argc);
	for (int i = 0; i < argc; i += 2) {
		POINT p;
		p.x = va_arg(ap, int);
		p.y = va_arg(ap, int);
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

int main()
{
	setlocale(LC_ALL, "");
/*	DOT a, b;
	cout << "Введите начальную координату X стороны: ";
	a.x = GetInt();
	cout << "Введите начальную координату Y стороны: ";
	a.y = GetInt();
	b.x = GetInt();
	b.y = GetInt();

	cout << len(a, b) << endl;

	DOT t1, t2, t3, m;
	t1.x = GetInt();
	t1.y = GetInt();
	t2.x = GetInt();
	t2.y = GetInt();
	t3.x = GetInt();
	t3.y = GetInt();
	m.x  = GetInt();
	m.y  = GetInt();
	cout << (belong(t1, t2, t3, m) == true ? "Принадлежит" : "Не принадлежит"); */

	cout << "Введите количество точек в многоугольнике: ";
	int count = GetInt();
	tuple<int, int> test;
	for (int i = 0; i < count; i++) {
		POINT p;
		p.x = 1;
		p.y = 2;
		test = std::tuple_cat(test, std::make_tuple('a'));


		belong(p, count);
	}



	return 0;
}