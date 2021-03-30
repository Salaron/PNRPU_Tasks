#include "Time.h"

using namespace std;

istream& operator >>(istream& in, Time& p)
{
	p.m_mins = -1;
	p.m_secs = -1;
	while (p.m_mins < 0) {
		cout << "Min: ";
		cin >> p.m_mins;
	}
	while (p.m_secs < 0) {
		cout << "Sec: ";
		cin >> p.m_secs;
	}
	p.correctOverflow();
	return in;
}

ostream& operator <<(ostream& out, Time& p)
{
	if (p.m_mins < 10) cout << 0;
	cout << p.m_mins << ":";
	if (p.m_secs < 10) cout << 0;
	cout << p.m_secs << endl;
	return out;
}

Time& Time::operator++()
{
	this->m_secs++;
	this->correctOverflow();
	return *this;
}

Time Time::operator++(int)
{
	Time temp = *this;
	++temp.m_secs;
	temp.correctOverflow();
	return temp;
}

Time Time::operator+(const Time& t)
{
	Time n;
	n.m_mins = m_mins + t.m_mins;
	n.m_secs = m_secs + t.m_secs;
	n.correctOverflow();
	return n;
}

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	m_mins = t.m_mins;
	m_secs = t.m_secs;
	return *this;
}