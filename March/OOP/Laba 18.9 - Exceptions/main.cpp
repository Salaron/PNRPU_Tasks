#include <iostream>
#include "Exception.h"
#include "Vector.h"

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

int main() {
	system("chcp 1251>nul");
	try {
		int size;
		cout << "Введите размер вектора: "; cin >> size;
		Vector v(size);
		cin >> v;
		cout << "Элементы вектора: " << endl << v;
		int ind;
		cout << "Введите индекс элемента, который хотите вывести: "; cin >> ind;
		int a = v[ind];
		cout << a << endl;
		v--;
		cout << v;
		--v;
		cout << v;
	}
	catch (BaseException& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}