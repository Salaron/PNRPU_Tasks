#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int getRandomInt(int start, int end) {
	return rand() % (end + 1 - start) + start;
}

struct Item {
	string name;
	int cost;
	void Print() {
		cout << "Название: " << name << endl;
		cout << "Цена: " << cost << endl;
	}
};

void Show(Item* items, int size) {
	for (int i = 0; i < size; i++) {
		items[i].Print();
	}
}

void shellSort(Item* items, int size) {
	for (int step = size / 2; step > 0; step /= 2) {
		for (int i = step; i < size; i++) {
			Item temp = items[i];

			int j = i;
			while (j >= step && items[j - step].cost > temp.cost) {
				items[j] = items[j - step];
				j -= step;
			}
			items[j] = temp;
		}
	}
}

void qsort(Item* a, int first, int last) {
	int i = first;
	int j = last;
	int pivot = a[(i + j) / 2].cost;
	Item temp;

	while (i <= j)
	{
		while (a[i].cost < pivot)
			i++;
		while (a[j].cost > pivot)
			j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (j > first)
		qsort(a, first, j);
	if (i < last)
		qsort(a, i, last);
}

int main()
{
	system("chcp 1251>nul");
	srand(time(0));
	int count = 0;
	while (count <= 0) {
		cout << "Введите количество элементов: ";
		cin >> count;
	}

	Item* items = new Item[count];
	Item* items2 = new Item[count];
	for (int i = 0; i < count; i++) {
		string names[] = { "Стол", "Вилка", "Tesla", "Бумага", "Дерево", "Алмаз", "Дракон", "Игрушка", "Автомобиль", "Мотоцикл" };
		items[i].name = names[getRandomInt(0, 9)];
		items[i].cost = getRandomInt(100, 100000);
		items2[i].name = items[i].name;
		items2[i].cost = items[i].cost;
	}
	cout << "Элементы до сортировки: " << endl;
	Show(items, count);
	cout << endl;
	qsort(items, 0, count - 1);
	cout << "Элементы после быстрой сортировки: " << endl;
	Show(items, count);
	cout << endl;

	shellSort(items2, count);
	cout << "Элементы после сортировки Шелла: " << endl;
	Show(items2, count);
	delete[] items;
	delete[] items2;
	return 0;
}