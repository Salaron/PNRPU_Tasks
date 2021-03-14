#include "iostream"
#include "string"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int res = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '{') 
			res++;
		else 
			res--;
	}
	if (res == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}