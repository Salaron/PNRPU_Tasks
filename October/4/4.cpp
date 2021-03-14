// K from A < M from B
#include <iostream>

using namespace std;

int main() {
	system("chcp 1251>nul");
	int n1, n2, k, m;
	cin >> n1 >> n2 >> k >> m;

	int* a = new int[n1];
	int* b = new int[n2];
	for (int i = 0; i < n1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> b[i];
	}
	if (a[k - 1] < b[n2 - m]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}