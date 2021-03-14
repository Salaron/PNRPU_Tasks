#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

enum LETTERS {
	LETTER_A = -32, // а
	LETTER_I = -24, // и
	LETTER_K = -22, // к
	LETTER_M = -20, // м
	LETTER_N,		// н
	LETTER_O,		// о
	LETTER_P = -16, // р
	LETTER_T = -14, // т
	LETTER_F = -12	// ф
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	char letter;
	cout << "Введите букву: ";
	cin >> letter;

	if (letter >= -64 && letter < -32) letter += 32;


	switch (letter) {
	case LETTER_A:
	case LETTER_I:
	case LETTER_K:
	case LETTER_M:
	case LETTER_N:
	case LETTER_O:
	case LETTER_P:
	case LETTER_T:
	case LETTER_F: {
		cout << "В слове \"Информатика\" есть буква \"" << letter << "\"!" << endl;
		break;
	}
	default: {
		cout << "В слове \"Информатика\" нет буквы " << letter << endl;
	}
	}

	return 0;
}