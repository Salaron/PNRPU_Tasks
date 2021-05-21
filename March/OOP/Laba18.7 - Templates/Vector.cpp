#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_
#include "Vector.h"
#include <assert.h>

using namespace std;

template <class T>
Vector<T>::Vector(int size, T k) {
	m_size = size;
	m_container = new T[size];
	for (int i = 0; i < size; i++) {
		m_container[i] = k;
	}
}

template <class T>
Vector<T>::Vector(const Vector& a) {
	m_size = a.m_size;
	m_container = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
}

template <class T>
Vector<T>::~Vector() {
	delete[] m_container;
}

template <class T>
void Vector<T>::push(T val) {
	T* a = new T[m_size + 1];
	for (int i = 0; i < m_size; i++) {
		a[i] = m_container[i];
	}
	delete m_container;
	m_container = a;
	m_size++;
	m_container[m_size - 1] = val;
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& a) {
	if (this == &a) return *this;
	m_size = a.m_size;
	if (m_container != nullptr) delete m_container;
	m_container = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_container[i] = a.m_container[i];
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index) {
	assert(index < m_size);
	return m_container[index];
}

template <class T>
int Vector<T>::operator () () {
	return m_size;
}

template <class T>
Vector<T> Vector<T>::operator * (const int k) {
	Vector temp(m_size, m_container[0]);
	for (int i = 0; i < m_size; ++i)
		temp.m_container[i] = m_container[i] * k;
	return temp;
}
#endif