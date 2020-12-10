#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

int findPos(int* list, int n, int element, int curPos) {
	if (curPos > n) return -1;
	if (list[curPos] == element) return curPos;
	return findPos(list, n, element, curPos + 1);
}

int GetInt(bool sign)
{
	int res;
	while (!(cin >> res) || (cin.peek() != '\n') || (sign == false && res < 1))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ����� �����, ������� ������ ����!" << endl;
	}
	return res;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "������� ���������� ����� � ������: ";
	int n = GetInt(false);
	int* list = new int[n];
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 1000 + 1;
	}
	sort(list, list + n);

	cout << "��� ������������� ������ �����: " << endl;
	for (int i = 0; i < n; i++) {
		cout << list[i] << "\t";
	}
	cout << endl;
	
	int idx = -1;
	while (idx == -1) {
		cout << "������� �������� ��������, ������� �������� ����� �����: ";
		int neededElement = GetInt(true);
		idx = findPos(list, n, neededElement, 0);
		if (idx == -1) {
			cout << "������� " << neededElement << " ���������� � ������ ������" << endl;
		}
		else {
			cout << "������� " << neededElement << " ����� ������� " << idx + 1 << endl;
		}
	}

	return 0;
}