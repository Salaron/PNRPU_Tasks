#include <iostream>

using namespace std;

class Range {
	double m_left;
	double m_right;
public:
	void Init(double left, double right) {
		m_left = left;
		m_right = right;
	}
	void Read() {
		cout << "Введите левую границу: "; cin >> m_left;
		cout << "Введите правую границу: "; cin >> m_right;
	}
	void Show() {

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
	cout << 
	A.rangecheck(-255.1) << endl;
	Range B;
	B.Read();
	cout << B.rangecheck(0) << endl;

	Range* C = new Range;
	C->Init(1, 2);
	C->rangecheck(1.5);

	// static array
	Range S[3];

	Range* D = new Range[3];

	delete[] D;

	double left, right;
	cout << "Введите левую границу: "; cin >> left;
	cout << "Введите правую границу: "; cin >> right;
	Range F = make_Range(left, right);
	F.rangecheck(123);
	return 0;
}