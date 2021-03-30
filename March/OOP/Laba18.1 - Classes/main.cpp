#include <iostream>

using namespace std;

class Range {
	double m_left;
	double m_right;
public:
	void Init(double left, double right) {
		if (left > right) {
			int tmp = left;
			left = right;
			right = tmp;
		}
		m_left = left;
		m_right = right;
	}
	void Read() {
		cout << "Введите левую границу: "; cin >> m_left;
		cout << "Введите правую границу: "; cin >> m_right;
		if (m_left > m_right) {
			int tmp = m_left;
			m_left = m_right;
			m_right = tmp;
		}
	}

	void Show() {
		cout << "Left: " << m_left << endl;
		cout << "Right: " << m_right << endl;
	}

	bool rangecheck(double x) {
		return x >= m_left && x <= m_right;
	}
};

Range make_Range(double left, double right) {
	Range result;
	result.Init(left, right);
	return result;
}

int main() {
	system("chcp 1251>nul");
	Range A;
	A.Init(-123.4, 256.6);
	A.Show();
	bool res = A.rangecheck(-255.1);
	cout << "A.rangecheck(-255.1) =>";
	if (res) {
		cout << " принадлежит" << endl;
	}
	else {
		cout << " не принадлежит" << endl;
	}
	cout << endl;

	Range B;
	B.Read();
	B.Show();
	res = B.rangecheck(-10.1);
	cout << "B.rangecheck(-10.1) =>";
	if (res) {
		cout << " принадлежит" << endl;
	}
	else {
		cout << " не принадлежит" << endl;
	}
	cout << endl;

	Range* C = new Range;
	C->Init(1, 2);
	C->Show();
	res = C->rangecheck(1.5);
	cout << "C.rangecheck(1.5) =>";
	if (res) {
		cout << " принадлежит" << endl;
	}
	else {
		cout << " не принадлежит" << endl;
	}
	cout << endl;

	double left, right, x;
	cout << "Введите левую границу: "; cin >> left;
	cout << "Введите правую границу: "; cin >> right;
	cout << "Введите X: "; cin >> x;
	Range F = make_Range(left, right);
	F.Show();
	res = F.rangecheck(x);
	cout << "F.rangecheck(" << x << ") =>";
	if (res) {
		cout << " принадлежит" << endl;
	}
	else {
		cout << " не принадлежит" << endl;
	}
	return 0;
}