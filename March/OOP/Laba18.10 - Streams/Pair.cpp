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

bool Pair::operator != (Pair other)
{
	return m_first != other.m_first && m_second != other.m_second;
}

istream& operator>>(istream& in, Pair& p)
{
	in >> p.m_first >> p.m_second;
	return in;
}

ostream& operator<<(ostream& out, Pair& p)
{
	out << p.getFirst() << " " << p.getSecond() << endl;
	return out;
}

