#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Date {
	int Day, Month, Year;
};

struct Human {
	string fio;
	Date BirthDate;
	long long phone;
	void Show()
	{
		cout << "\nФИО: " << fio << endl;
		cout << "Дата рождения: " << BirthDate.Day << "." << BirthDate.Month << "." << BirthDate.Year << endl;
		cout << "Телефон: " << phone << endl;
	}
	string key;
	void keyforming()
	{
		if (BirthDate.Day < 10)
			key += "0";
		key += to_string(BirthDate.Day);
		if (BirthDate.Month < 10)
			key += "0";
		key += to_string(BirthDate.Month);
		key += to_string(BirthDate.Year);
	}
	int Hash;
	void createHash(int M)
	{
		float A = 0.45457;
		float tmp = stoi(key) * A;
		float intpart;
		float floatpart;
		floatpart = modf(tmp, &intpart);
		Hash = trunc((M * floatpart));
	}
};
struct HashTable {
	vector<Human> human_list;
	string key;
	int Hash;
	void Add_list(Human person)
	{
		human_list.push_back(person);
	}
};

void InsertionSort(vector<HashTable>& HashTable)
{
	for (int i = 0; i < HashTable.size(); i++) {
		for (int j = i; j > 0 && HashTable[j - 1].Hash > HashTable[j].Hash; j--) {
			swap(HashTable[j - 1], HashTable[j]);
		}
	}
}

vector<Human> MakeArr(int size)
{
	string firstname[] = { "Врублевский", "Филатов", "Исламов", "Худаев", "Шамай", "Сабуров", "Попов", "Нефёдов" };
	string secondnames[] = { "Андрей", "Александр", "Сергей", "Максим", "Анатолий", "Никита", "Тимофей" };
	string thirdnames[] = { "Сергеевич", "Андреевич", "Данилович", "Артёмович", "Анатольевич", "Витальевич" };
	vector <Human> result;
	for (int i = 0; i < size; i++) {
		Human NewPerson;
		NewPerson.fio = firstname[rand() % 8] + " " + secondnames[rand() % 7] + " " + thirdnames[rand() % 6];
		NewPerson.BirthDate.Day = 1 + rand() % 30;
		NewPerson.BirthDate.Month = 1 + rand() % 12;
		NewPerson.BirthDate.Year = 1000 + rand() % 1000;
		NewPerson.phone = rand() % 100000;
		result.push_back(NewPerson);
	}
	return result;
}
void createHashTable(vector<HashTable>& Table, vector<Human> spisok, int kol)
{
	for (int i = 0; i < spisok.size(); i++) {
		HashTable tmp;
		spisok[i].keyforming();
		spisok[i].createHash(spisok.size());
		tmp.Hash = spisok[i].Hash;
		tmp.key = spisok[i].key;
		tmp.Add_list(spisok[i]);
		Table.push_back(tmp);
	}
	InsertionSort(Table);
	for (int i = 0; i < kol - 1;) {
		if (Table[i].Hash == Table[i + 1].Hash) {
			Table[i].human_list.push_back(Table[i + 1].human_list[0]);
			Table.erase(Table.begin() + i + 1);
			kol--;
		}
		else
			i++;
	}
}
string ConvertKey(int Day, int Month, int Year)
{
	string key1;
	if (Day < 10)
		key1 += "0";
	key1 += to_string(Day);
	if (Month < 10)
		key1 += "0";
	key1 += to_string(Month);
	key1 += to_string(Year);
	return key1;
}

void Show(vector<HashTable>& Table)
{
	for (int i = 0; i < Table.size(); i++) {
		cout << "\nХеш: " << Table[i].Hash << endl;
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			Table[i].human_list[j].Show();
		}
		if (Table[i].human_list.size() > 1)
			cout << "\nКоличество коллизий: " << Table[i].human_list.size() << endl;
		cout << "=====================================" << endl;
	}
}

Human* Seeking(vector<HashTable>& Table, string _key)
{
	Human* element = NULL;
	for (int i = 0; i < Table.size(); i++) {
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			if (Table[i].human_list[j].key == _key)
				element = &Table[i].human_list[j];
		}
	}
	return element;
}

int main()
{
	system("chcp 1251>nul");
	srand(time(0));
	int count = -1, day, month, year;
	while (count < 1) {
		cout << "Введите количество элементов: ";
		cin >> count;
	}
	vector<Human> spisok = MakeArr(count);
	vector<HashTable>Table;
	createHashTable(Table, spisok, count);
	Show(Table);
	cout << "\n\nВведите ключ (дату) для поиска: ";
	cin >> day >> month >> year;
	string keyToFind = ConvertKey(day, month, year);
	Human* element = Seeking(Table, keyToFind);
	cout << endl;
	if (element == NULL) {
		cout << "Такого элемента нет!!!!!!!!!!!!!!!!!!!";
	}
	else {
		element->Show();
	}
}