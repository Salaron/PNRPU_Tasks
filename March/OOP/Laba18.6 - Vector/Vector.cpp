#pragma once
#include "Vector.h"
#include <assert.h>

Vector::Vector(int size, int k) {
	m_size = size;
	m_container = new int[size];
	for (int i = 0; i < size; i++) {
		m_container[i] = k;
	}
	m_begin.m_pCurrent = &m_container[0];
	m_end.m_pCurrent = &m_container[size];
}

Vector::Vector(const Vector& a) {
	m_size = a.m_size;
	m_container = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
	m_begin.m_pCurrent = &m_container[0];
	m_end.m_pCurrent = &m_container[m_size];
}

Vector& Vector::operator = (const Vector& a) {
	if (this == &a) return *this;
	m_size = a.m_size;
	if (m_container != nullptr) delete m_container;
	m_container = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
	m_begin.m_pCurrent = &m_container[0];
	m_end.m_pCurrent = &m_container[m_size];
	return *this;
}

Vector::~Vector() {
	delete[] m_container;
}

int& Vector::operator[](int index) { 
	assert(index < m_size);
	return m_container[index];
}

Vector Vector::operator * (const int k){
	Vector temp(m_size);
	for (int i= 0 ;i < m_size;++i)
		temp.m_container[i] = m_container[i] * k;
	return temp;
}

int Vector::operator () () { 
	return m_size;
}

ostream& operator << (ostream& out, Vector& a) { 
	for (int i = 0; i < a(); ++i)
		out << a.m_container[i] << " ";
	return out; 
}

istream& operator >> (istream& in, Vector& a) {
	for (int i = 0; i < a(); ++i)
		in >> a.m_container[i];
	return in; 
}
