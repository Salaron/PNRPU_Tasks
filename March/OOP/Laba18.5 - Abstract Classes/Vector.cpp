#include "Vector.h"
#include "Object.h"

using namespace std;

Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
Vector::Vector(int size)
{
	beg = new Object * [size];
	current = 0;
	this->size = size;
}
void Vector::push(Object* pointer)
{
	if (current < size) {
		beg[current] = pointer;
		current++;
	}
	else
		cout << "Вектор заполнен" << endl;
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0)
		out << "Вектор пуст" << endl;
	Object** p = v.beg;
	for (int i = 0; i < v.current; i++) {
		(*p)->Show();
		p++;
	}
	return out;
}