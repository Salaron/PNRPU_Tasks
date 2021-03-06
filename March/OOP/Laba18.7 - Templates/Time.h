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
	Time(int mins, int secs);

	void addSeconds(int seconds) {
		m_secs += seconds;
		correctOverflow();
	}

	Time& operator =(const Time&);
	Time& operator ++();
	Time operator ++(int);

	Time operator +(const Time&);
	Time operator * (const int k);

	friend ostream& operator <<(ostream&, const Time&);
	friend istream& operator >>(istream&, Time&);
};