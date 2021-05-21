#pragma once
#include "Vector.h"
#include "Exception.h"

Vector::Vector(int size, int k) {
	m_size = size;
	m_container = new int[size];
	for (int i = 0; i < size; i++) {
		m_container[i] = k;
	}
}

Vector::Vector(const Vector& a) {
	m_size = a.m_size;
	m_container = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
}

Vector& Vector::operator = (const Vector& a) {
	if (this == &a) return *this;
	m_size = a.m_size;
	if (m_container != nullptr) delete m_container;
	m_container = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
	return *this;
}

Vector::~Vector() {
	delete[] m_container;
}

int& Vector::operator[](int index) {
	if (index >= m_size || index < 0) throw IndexException("Invalid index!");
	return m_container[index];
}


int Vector::operator () () {
	return m_size;
}

ostream& operator << (ostream& out, Vector& a) {
	if (a.m_size == 0) cout << "EMPTY" << endl;
	for (int i = 0; i < a(); ++i)
		out << a.m_container[i] << " ";
	out << endl;
	return out;
}

istream& operator >> (istream& in, Vector& a) {
	for (int i = 0; i < a(); ++i)
		in >> a.m_container[i];
	return in;
}


// --x
Vector& Vector::operator --() {
	if (m_size == 0) throw EmptyException("Vector is empty!");
	for (int i = 0; i < m_size - 1; i++) {
		m_container[i] = m_container[i + 1];
	}
	m_size--;
	return *this;
}

// x--
Vector Vector::operator --(int) {
	if (m_size == 0) throw EmptyException("Vector is empty!");
	m_size--; // just ignore last element lol
	return *this;
}