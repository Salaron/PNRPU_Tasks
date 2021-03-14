// Counting of zeros in number
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	system("chcp 1251>nul");
	int N, K;
	cin >> N >> K;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		int number = i;

		int zeros = 0;
		string result = "";
		while (number != 0) {
			result += to_string((number & 1));
			zeros += !(number & 1);
			number = number >> 1;
		}
		reverse(result.begin(), result.end());
		cout << i << " " << result << endl;

		if (zeros == K) count++;
	}
	cout << count;
	return 0;
}