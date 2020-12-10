#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Coordinate {
	int x;
	int y;
};

void solve()
{
	int m, n, x, y;
	cout << "Количество строк: ";
	cin >> m;
	cout << "Количество столбцов: ";
	cin >> n;
	cout << "Координаты коня: ";
	cin >> x >> y;
	
	vector<Coordinate> Coordinates;
	if (m >= 100 || n >= 100)
		cout.setstate(std::ios_base::failbit);


	cout << setfill(' ') << setw(to_string(m).length() + 2);
	for (int i = 0; i < n * 2 + 1; i++) {
		cout << "-";
	}
	cout << endl;

	/*
	---------------
	| | |x| |x| | |
	| |x| | | |x| |
	| | | |K| | | |
	| |x| | | |x| |
	| | |x| |x| | |
	---------------
	*/
	for (int i = m; i >= 1; i--) {
		cout << setfill(' ') << setw(to_string(m).length()) << i << " ";
		for (int j = 1; j <= n; j++) {
			cout << "|";
			if (i == y && j == x) {
				cout << "K";
			}
			else {
				bool founded = false;
				// x - 2 => y - 1 | y + 1
				// x - 1 => y - 2 | y + 2
				// x + 1 => y - 2 | y + 2
				// x + 2 => y - 1 | y + 1
				// -> abs(x) != abs(y)
				for (int k = -2; k <= 2; k++) {
					if (k == 0) continue;
					for (int l = -2; l <= 2; l++) {
						if (l == 0 || (abs(l) == abs(k))) continue;
						if (j + k == x && i + l == y) {
							founded = true;
							cout << "X";
							Coordinates.insert(Coordinates.end(), { j, i });
						}
					}
				}
				if (!founded)
					cout << " ";
			}
		}
		cout << "|" << endl;
	}

	cout << setfill(' ') << setw(to_string(m).length() + 2);
	for (int i = 0; i < n * 2 + 1; i++) {
		cout << "-";
	}
	cout << endl;

	// lower bar
	for (int i = 0; i < to_string(m).length(); i++) {
		cout << setfill(' ') << setw(to_string(m).length() + 3);
		cout << " ";
		for (int j = 1; j <= n; j++) {
			if (!to_string(j)[i]) {
				cout << "  ";
			}
			else {
				cout << to_string(j)[i] << " ";
			}
			
		}
		cout << endl;
	}
	cout << endl;

	if (m > 100 || n > 100)
		cout.clear();

	cout << "Количество точек: " << Coordinates.size() << " ";
	for (int i = 0; i < Coordinates.size(); i++) {
		cout << "(" << Coordinates[i].x << "; " << Coordinates[i].y << ") ";
	}
	cout << endl;
}

int main()
{
	setlocale(NULL, "RU");
	int t;
	cout << "Количество тестов: ";
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}