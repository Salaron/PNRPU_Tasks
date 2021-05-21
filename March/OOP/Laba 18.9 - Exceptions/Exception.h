#include <iostream>

using namespace std;

class BaseException {
	string m_what;
public:
	BaseException() {}
	BaseException(string what) {
		m_what = what;
	}
	string what() {
		return m_what;
	}
};

class IndexException : public BaseException {
public:
	IndexException(string what) : BaseException(what) {}
};

class EmptyException : public BaseException {
public:
	EmptyException(string what) : BaseException(what) {}
};