#pragma once
#ifndef NODE_HEADER
#define NODE_HEADER
template <typename T>
class Node {
public:
	Node(T value);
	Node(Node<T>* parent, T value);
	~Node();

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	T value;
	int level = 1;
	int radius = 80;
	bool hovered = false;

	double x;
	double y;

	void draw();
	bool isHovered(int x, int y);
protected:
	void drawTriangle(Node<T>* child);
};

#include "Node.cpp"
#endif