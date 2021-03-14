#include <iostream>
#include <string>

using namespace std;

struct Writter {
	string name;
	string surname;
	string middlename;
	int bookCount;
};

void shellSort(Writter* a, int size) {

}

void qsort(Writter* a, int first, int last) {
	int i = first;
	int j = last;
	Writter x = a[(first + last) / 2];

	do {

	} while (i <= j);

	if (i < last)
		qsort(a, i, last);
	if (first < j) {
		qsort(a, first, j);
	}
}

int main()
{
	system("chcp 1251>nul");

	return 0;
}