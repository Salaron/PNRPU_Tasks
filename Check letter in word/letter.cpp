#include <iostream>
#include <string>

using namespace std;

enum LETTERS {
	LETTER_A = -32, // �
	LETTER_I = -24, // �
	LETTER_K = -22, // �
	LETTER_M = -20, // �
	LETTER_N,		// �
	LETTER_O,		// �
	LETTER_P = -16, // �
	LETTER_T = -14, // �
	LETTER_F = -12	// �
};

int main()
{
	setlocale(LC_ALL, "");
	char letter;
	cout << "������� �����: ";
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
		cout << "� ����� \"�����������\" ���� ����� \"" << letter << "\"!" << endl;
		break;
	}
	default: {
		cout << "� ����� \"�����������\" ��� ����� " << letter << endl;
	}
	}

	return 0;
}