#include "iostream"
#include "string"

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;

		for (int i = 0; i < n; i++) {
			cout << (char)('a' + (i % b));
		}
		cout << endl;
	}

	return 0;
}