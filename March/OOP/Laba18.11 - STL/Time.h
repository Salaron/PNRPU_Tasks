#pragma once
#include <iostream>
using namespace std;

class Time {
	int m_mins;
	int m_secs;

	void correctOverflow() {
		int mins = 0;
		while (m_secs >= 60) {
			m_secs -= 60;
			mins += 1;
		}
		m_mins += mins;
	}
public:
	Time();
	Time(int min, int sec);

	void addSeconds(int seconds) {
		m_secs += seconds;
		correctOverflow();
	}

	int getSecs() {
		return m_mins * 60 + m_secs;
	}

	Time& operator =(const Time&);
	Time& operator ++();
	Time operator ++(int);

	friend bool operator >(Time& t1, Time& t2) { return (t1.getSecs() > t2.getSecs()); }
	friend bool operator <(Time& t1, Time& t2) { return (t1.getSecs() < t2.getSecs()); }

	Time operator +(const Time&);

	friend ostream& operator <<(ostream&, Time&);
	friend istream& operator >>(istream&, Time&);
};