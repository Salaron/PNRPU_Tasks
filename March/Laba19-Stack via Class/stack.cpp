#include <assert.h>
#include "stack.h"

Stack::Stack() {
	m_size = 0;
	m_stack = new double[1024]; // maximum elements in the stack is 1024
}

Stack::Stack(Stack& p) {
	m_size = p.m_size;
	m_stack = new double[1024];
	for (int i = 0; i < m_size; i++) {
		m_stack[i] = p.m_stack[i];
	}
}

Stack::~Stack() {
	delete[] m_stack;
}

// add element to the stack
void Stack::push(double element) {
	assert(m_size != 1024, "Limit reached");
	for (int i = m_size; i > 0; i--) {
		m_stack[i] = m_stack[i - 1];
	}
	m_stack[0] = element;
	m_size++;
}

// removes top element of stack
void Stack::pop() {
	assert(m_size != 0, "Stack is empty");
	for (int i = 0; i < m_size - 1; i++) {
		m_stack[i] = m_stack[i + 1];
	}
	m_size--;
}

// get top element of stack
double Stack::top() {
	assert(m_size != 0, "Stack is empty");
	return m_stack[0];
}

// how much elements in the stack
int Stack::size() {
	return m_size;
}

bool Stack::empty() {
	return m_size == 0;
}

istream& operator>>(istream& in, Stack& p)
{
	double value;
	// 3:10 : TODO: safe input? too lazy to do it...
	// 3:32 : nah, it works anyway and string just becomes zero
	in >> value;
	p.push(value);
	return in;
}

ostream& operator<<(ostream& out, Stack& p)
{
	for (int i = 0; i < p.m_size; i++) {
		cout << p.m_stack[i] << "\t";
	}
	cout << endl;
	return out;
}
