#pragma once
#include<iostream>
#include <queue>
using namespace std;
template <typename Type>
class VectorQueue
{
	queue<Type> container;
	int len;
public:
	VectorQueue() { len = 0; };
	VectorQueue(int n)
	{
		Type obj;
		for (int i = 0; i < n; i++) {
			obj = ((rand() % 100) * 0.1);
			container.push(obj);
		}
		len = container.size();
	}
	void Print()
	{
		queue<Type>temp;
		temp = container;
		while (!temp.empty()) {
			cout << temp.front() << "; ";
			temp.pop();
		}
		cout << endl;
	}
	VectorQueue operator+(const Type newElement)
	{
		VectorQueue<Type>tmp;
		for (int i = 0; i < len; i++) {
			container.front() += newElement;
			tmp.container.push(container.front());
			container.pop();
		}
		return tmp;
	}
	int get_size()
	{
		return len;
	}
	int FindAverageValue()
	{
		int length = len;
		queue<Type>tmp = container;
		int result = 0, count = 0;
		for (int i = 0; i < length; i++) {
			result += tmp.front();
			count++;
			tmp.pop();
		}
		result = result / count;
		return result;
	}
};