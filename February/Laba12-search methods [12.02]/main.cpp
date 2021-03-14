#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>
#include "utils.h"

using namespace std;

void insertionSort(DATA*& arr, int size)
{
	for (int i = 1; i < size; i++) {
		DATA k = arr[i];
		int j = i;
		for (j = i; j > 0 && arr[j - 1].number > k.number; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = k;
	}
}

void generate(DATA*& str, int count) {
	if (str != nullptr) delete[] str;
	str = new DATA[count];
	for (int i = 0; i < count; i++) {
		string names[] = { "Аюбур", "Саин", "Джавган", "Мисаил", "Валихана", "Канзилбанат", "Хвигар", "Иваш", "Корки", "Бэлфор", "Аванда", "Филли", "Алижон", "Асрер", "Стэффорд", "Палладин", "Флорентин", "Ивсталия", "Евнения", "Аристарь", "Шерелл", "Сафо", "Пион", "Азархан", "Гроздана", "Каллиса", "Анизя", "Мариян", "Гетер", "Бэрри", "Маргот", "Ганзия", "Айджамал", "Йишмаэл", "Дилсуз", "Рева", "Вландин", "Мабрура", "Шарм", "Энрике", "Эвета", "Седрак", "Умрайган", "Сэулет", "Махлиё", "Астик", "Сосифей", "Чилдерс", "Абдисуюн", "Листар", "Гусей", "Аркий", "Безгнева", "Гараоглан", "Изосима", "Волк", "Девин", "Данк", "Декабрист", "Джалали", "Тилда", "Алиям", "Хушбирде", "Нарчечек", "Арес", "Аббаш", "Флор", "Стенли", "Палинарий", "Шавали", "Саторнил", "Аландра", "Элёр", "Анфиста", "Бидзина", "Давлетбирде", "Аине", "Делси", "Аркалий", "Эмметт", "Тавифа", "Симус", "Розалво", "Огонь", "Лорика", "Бибинур", "Велиора", "Абело", "Гузелия", "Балтан", "Неолина", "Искендар", "Беактриса", "Валдас", "Ардольон", "Буслав", "Фозил", "Савда", "Думрия", "Гамза" };
		string surnames[] = { "Мазырев", "Мятликова", "Ганибалов", "Разсанова", "Шайхайдаров", "Заглодеева", "Сидловская", "Ахмежанова", "Эхсанова", "Помошникова", "Затямина", "Гапченко", "Слабчук", "Мустакова", "Кожанчиков", "Хасвинулина", "Вовси", "Саханская", "Зыкалин", "Земекова", "Калыхалов", "Полуновский", "Карро", "Дунашова", "Фаратов", "Вихляев", "Новоблаговещенская", "Винчи", "Калакова", "Стюк", "Шахрамьян", "Малявкин", "Адамантова", "Затишов", "Бохсан", "Семенчинская", "Солодцкий", "Бржестовский", "Бузько", "Кошовкин", "Смичельская", "Барамидзе", "Абкадыров", "Котелкин", "Тароненко", "Токалев", "Фесков", "Сапфирова", "Каненкова", "Астонович", "Тунгусков", "Занечина", "Жагланова", "Эйланбекова", "Гомонилова", "Володченко", "Азаренко", "Артомошкин", "Рудаковская", "Демещенко", "Дружиновский", "Люстарнова", "Миглац", "Комех", "Червин", "Хаврученко", "Кабицева", "Чужайкина", "Чепелевский", "Вотякова", "Семиошин", "Нижанская", "Суровый", "Герберг", "Цицанкина", "Брегетова", "Колюбинская", "Артисов", "Рыськова", "Долголаптев", "Снеговая", "Трипалин", "Евласьева", "Холобаев", "Шаркова", "Женно", "Гряхнева", "Колыманов", "Аханькова", "Ильеняев", "Сычкин", "Валковой", "Юрченко", "Кипоренко", "Пусбарнек", "Балобанов", "Каратовский", "Сельдимурова", "Явных", "Чурадаев" };
		string midnames[] = { "Нугзаровна", "Ризаевна", "Рестемович", "Елизаровна", "Аврамовна", "Титовна", "Суфьянович", "Нигматович", "Латипович", "Умат-Гиреевич", "Дзантемирович", "Севанович", "Арамбиевич", "Альгирдасович", "Ахмедага Оглы", "Айказовна", "Тарашиевна", "Исхаковна", "Апетович", "Абдулгалимович", "Карам Оглы", "Юлаевна", "Никогосович", "Насретдинович", "Мулланурович", "Фэритович", "Алекбер Оглы", "Гариевна", "Джапарович", "Ануровна", "Галиаскарович", "Магаррам Оглы", "Хамзяевич", "Алиса Оглы", "Владиковна", "Мехди Оглы", "Чингисович", "Абдунабиевич", "Убайдулаевич", "Шаехович", "Исмаиловна", "Керимовна", "Алимханович", "Нажмудинович", "Салахутдинович", "Мусович", "Султангалеевич", "Абдулмеджидович", "Хабирович", "Никитович", "Кимсанович", "Амлетович", "Яшарович", "Мухиддинович", "Рузибоевич", "Багаутдиновна", "Вагиф Кызы", "Оданович", "Ядулла Оглы", "Габдулханович", "Михакович", "Эркиновна", "Тюлегенович", "Бариевич", "Заирович", "Муратбековна", "Арамовна", "Фларидович", "Ломалиевич", "Анастасовна", "Серожович", "Шириновна", "Шахидовна", "Фидаилевна", "Тимергалиевич", "Ибраевич", "Артамонович", "Алевтинович", "Джемалиевич", "Казибекович", "Корюнович", "Шарифулловна", "Алексндровна", "Аршалуйсовна", "Асланович", "Гумяровна", "Кутбидинович", "Ряшидович", "Вольфовна", "Эльчинович", "Дмитревич", "Хазраиловна", "Султановна", "Сосоевич", "Нурлыгаяновна", "Сальманович", "Аврамовна", "Намсараевна", "Зафаровна", "Миннурович" };
		str[i].fio = names[getRandomInt(0, 99)] + " " + surnames[getRandomInt(0, 99)] + " " + midnames[getRandomInt(0, 99)];
		str[i].birth = to_string(getRandomInt(1, 30)) + "." + to_string(getRandomInt(1, 12)) + "." + to_string(getRandomInt(1940, 2021));
		str[i].number = getRandomInt(100000, 999999);
	}
	insertionSort(str, count);
}

int load(DATA*& str, int* count) {
	if (str != nullptr) delete[] str;
	*count = 0;
	ifstream input("data.bin", ios::binary);
	int result = 1; // ok by default

	input.read((char*)count, sizeof(int));
	if (*count != 0) {
		str = new DATA[*count];
		for (int i = 0; i < *count; i++) {
			size_t fio_size, birth_size;
			input.read((char*)&fio_size, sizeof(string::size_type));
			str[i].fio.resize(fio_size);
			input.read((char*)&str[i].fio[0], fio_size);
			input.read((char*)&birth_size, sizeof(string::size_type));
			str[i].birth.resize(birth_size);
			input.read((char*)&str[i].birth[0], birth_size);
			input.read((char*)&str[i].number, sizeof(int));
		}
	}
	else {
		result = -1; // fail
	}

	input.close();
	return result;
}

int save(DATA* str, int count) {
	ofstream out_bin("data.bin", ios::binary);
	ofstream out_txt("data.txt");
	int result = 0;
	if (!out_bin.is_open() || !out_txt.is_open() || count == 0) {
		result = -1;
	}
	else {
		out_bin.write((char*)&count, sizeof(int));
		for (int i = 0; i < count; i++) {
			if (str[i].removed) continue;
			// binary
			size_t fio_size = str[i].fio.size();
			size_t birth_size = str[i].birth.size();
			out_bin.write((char*)&fio_size, sizeof(string::size_type));
			out_bin.write((char*)str[i].fio.c_str(), fio_size);
			out_bin.write((char*)&birth_size, sizeof(string::size_type));
			out_bin.write((char*)str[i].birth.c_str(), birth_size);
			out_bin.write((char*)&str[i].number, sizeof(int));
			// text
			out_txt << "[" << i << "] = " << endl;
			out_txt << "ФИО:          \t" << str[i].fio << endl;
			out_txt << "Дата рождения:\t" << str[i].birth << endl;
			out_txt << "Номер паспорта:\t" << str[i].number << endl;
			result += 1;
		}
	}
	out_bin.close();
	out_txt.close();
	return result;
}

void print(DATA* str, int count) {
	if (count == 0) {
		cout << "Пусто" << endl;
	}
	else {
		for (int i = 0; i < count; i++) {
			if (str[i].removed) continue;
			str[i].print();
		}
	}
}

int lineSearch(DATA* str, int size, int passportNumber) {
	for (int i = 0; i < size; i++) {
		if (str[i].number == passportNumber) return i;
	}
	return -1;
}

int binarySearch(DATA* str, int size, int passportNumber) {
	int L = 0;
	int R = size - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (str[mid].number == passportNumber) return mid;
		if (str[mid].number > passportNumber) R = mid - 1;
		if (str[mid].number < passportNumber) L = mid + 1;
	}
	return -1;
}

int interpolarSearch(DATA* arr, int size, int passportNumber) {
	int mid;
	int low = 0;
	int high = size - 1;

	while (arr[low].number < passportNumber && arr[high].number > passportNumber) {
		if (arr[high].number == arr[low].number) // Защита от деления на 0
			break;
		mid = low + ((passportNumber - arr[low].number) * (high - low)) / (arr[high].number - arr[low].number);

		if (arr[mid].number < passportNumber)
			low = mid + 1;
		else if (arr[mid].number > passportNumber)
			high = mid - 1;
		else
			return mid;
	}

	if (arr[low].number == passportNumber)
		return low;
	if (arr[high].number == passportNumber)
		return high;

	return -1;
}

bool markAsRemoved(DATA* arr, int* size, int value, bool index = false) {
	bool removed = false;
	for (int i = 0; i < *size; i++) {
		if (index && i == value || arr[i].number == value) {
			arr[i].removed = true;
			removed = true;
		}
	}
	return removed;
}

int main()
{
	srand(time(0));
	system("chcp 1251>nul");
	int elementsCount = 0;
	DATA* data = nullptr;

	int choise = -1;
	bool loop = true;
	while (loop) {
		cout << endl << "Выберите действие:" << endl << "1) Сгенерировать массив данных" << endl << "2) Сохранить данные в файл" << endl << "3) Загрузить данные из файла" << endl
			 << "4) Вывести список данных" << endl << "5) Удалить элемент из массива" << endl << "6) Поиск по номеру паспорта" << endl << "7) Выйти из программы" << endl;
		choise = getSafeInt();
		switch (choise) {
		case MENU_GENERATE: {
			cout << "Введите количество элементов: ";
			elementsCount = getSafeInt(true);
			generate(data, elementsCount);
			break;
		}
		case MENU_SAVE: {
			if (elementsCount != 0) {
				int result = save(data, elementsCount);
				if (result == -1) {
					cout << "Не удалось сохранить данные в файл :(" << endl;
				}
				else {
					cout << "В файл было записано " << result << " элементов" << endl;
				}
			}
			else {
				cout << "Нет элементов для сохранения!" << endl;
			}
			break;
		}
		case MENU_LOAD: {
			int result = load(data, &elementsCount);
			if (elementsCount == 0 || result == -1) {
				cout << "Не удалось загрузить данные из файла" << endl;
			}
			else {
				cout << "Из файла было загружено " << elementsCount << " элементов" << endl;
			}
			break;
		}
		case MENU_PRINT: {
			print(data, elementsCount);
			break;
		}
		case MENU_REMOVE: {
			if (elementsCount != 0) {
				cout << "Введите номер паспорта: ";
				int number = getSafeInt(true);
				bool result = markAsRemoved(data, &elementsCount, number);
				if (result) {
					cout << "Элемент был успешно удалён" << endl;
				}
				else {
					cout << "В списке нет элемента с данным номером паспорта!" << endl;
				}
			}
			else {
				cout << "Невозможно выполнить деление: список пуст" << endl;
			}
			break;
		}
		case MENU_SEARCH: {
			if (elementsCount != 0) {
				cout << "Введите номер паспорта: ";
				int number = getSafeInt(true);
				cout << "Введите метод поиска: " << endl;
				cout << "1) Интерполяционный" << endl << "2) Бинарный" << endl << "3) Линейный" << endl;
				int method = getSafeInt(true);
				while (method > 3) method = getSafeInt(true);
				int idx = -1;
				if (method == 1) idx = interpolarSearch(data, elementsCount, number);
				if (method == 2) idx = binarySearch(data, elementsCount, number);
				if (method == 3) idx = lineSearch(data, elementsCount, number);

				if (idx == -1 || data[idx].removed) {
					cout << "Человека с данным номером паспорта нет в нашем списке :(" << endl;
				}
				else {
					data[idx].print();
				}
			}
			else {
				cout << "Невозможно выполнить поиск: список пуст" << endl;
			}

			break;
		}
		case MENU_EXIT: loop = false; break;
		default: {
			cout << "Неверный выбор" << endl;
		}
		}
		choise = -1;
	}


	return 0;
}