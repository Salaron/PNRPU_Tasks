#include <iostream>
#include "Object.h"
#include "Pair.h"
#include "Complex.h"
#include "Vector.h"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	Pair a, b;
	int tmp;
	cout << "Введите первую пару" << endl;
	cin >> a;
	tmp = a.getFirst();
	a.setFirst(tmp);
	tmp = a.getSecond();
	a.setSecond(tmp);
	cout << "Введите вторую пару" << endl;
	cin >> b;
	tmp = b.getFirst();
	b.setFirst(tmp);
	tmp = b.getSecond();
	b.setSecond(tmp);
	Pair c = a + b;
	Pair d = a - b;
	cout << endl << "Сумма: " << c << endl;
	cout << "Разность: " << d << endl;

	Complex p(a, b); // создание объекта класса Complex	
	Object* ptr = &a;
	ptr->Show(); // вывод в консоль первой введённой пары
	ptr = &b;
	ptr->Show(); // вывод в консоль второй введённой пары
	cout << "Комплексное число: ";
	ptr = &p;
	ptr->Show(); // вывод в консоль объекта класса Complex
	Vector vec(3);
	vec.push(ptr); // добавление обекта класса Complex в вектор
	vec.push(&a);
	cout << "Вектор: " << vec;
	return 0;
}