#include "Pair.h"

Pair::Pair() {
	m_first = 0;
	m_second = 0;
}

Pair::Pair(int first, int second) {
	m_first = first;
	m_second = second;
}

int Pair::getFirst() {
	return m_first;
}

int Pair::getSecond() {
	return m_second;
}

void Pair::setFirst(int f) {
	m_first = f;
}

void Pair::setSecond(int s) {
	m_second = s;
}

Pair Pair::sum(Pair b) {
	Pair result;
	result.setFirst(m_first + m_second);
	result.setSecond(b.m_first + b.m_second);
	return result;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "First? "; cin >> p.m_first;
	cout << "Second? "; cin >> p.m_second;
	return in;
}

ostream& operator<<(ostream& out, Pair& p)
{
	cout << "(" << p.getFirst() << "; " << p.getSecond() << ")" << endl;
	return out;
}

