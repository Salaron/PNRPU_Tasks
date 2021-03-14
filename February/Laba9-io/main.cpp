#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int SafeInput(bool strict = true) {
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ���������� �����!" << endl;
	}
	cin.get();
	return result;
}

void generateFile(const char* fileName)
{
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "������ �������� ����� " << fileName << endl;
		exit(0);
	}
	cout << "������� ���������� �����, ������� ���������� �������� � ����: ";
	int N = SafeInput();
	for (int i = 1; i <= N; i++) {
		cout << "������� " << i << " ������: ";
		string buf;
		getline(cin, buf);
		file << buf << endl;
	}
	file.close();
}

void printFile(const char* fileName)
{
	ifstream file(fileName);
	string buf;
	while (getline(file, buf)) {
		cout << buf << endl;
	}
	file.close();
}

void copyFile(const char* fileName1, const char* fileName2)
{
	// ����������� �� ����� f1 � f2 ��� ������, � ������� ���������� ������ ���� �����
	ifstream f1(fileName1);
	ofstream f2(fileName2);

	string buf;
	while (getline(f1, buf)) {
		bool hasWhitespace = false;
		for (int i = 0; i < buf.length(); i++) {
			if (buf[i] == ' ') {
				hasWhitespace = true;
			}
		}
		if (!hasWhitespace) {
			f2 << buf << endl;
		}
	}

	f1.close();
	f2.close();
}

void solve(const char* fileName)
{
	// ���������� ����� �����, � ������� ������ ����� ��������� ����
	ifstream file(fileName);

	string dict = "������������������������������������������BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";
	int maxCnt = 0;
	int maxWordIndex = 0;
	int wordCount = 0;
	string result;
	while (!file.eof()) {
		string word;
		wordCount++;
		int cnt = 0;
		file >> word;
		for (int i = 0; i < word.length(); i++) {
			if (dict.find(word[i]) != -1) cnt++;
		}
		if (cnt > maxCnt) {
			maxCnt = cnt;
			result = word;
			maxWordIndex = wordCount;
		}
	}
	if (maxCnt == 0) {
		cout << "� ����� ��� ���� � ���������� �������" << endl;
	}
	else {
		cout << "� ����� \"" << result << "\" ��� ������� " << maxWordIndex << " ��������� ������ ����� ��������� ���� (" << maxCnt << ")" << endl;
	}
	file.close();
}

int main()
{
	system("chcp 1251>nul");
	remove("F1");
	remove("F2");
	generateFile("F1");
	cout << "���������� ���� F1: " << endl;
	printFile("F1");
	cout << endl;
	copyFile("F1", "F2");
	cout << "���� F2 ����� ����������� �� F1: " << endl;
	printFile("F2");
	cout << endl;
	solve("F1");
	return 0;
}