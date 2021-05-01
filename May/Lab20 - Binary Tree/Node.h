#pragma once
class Node {
public:
	Node(int value);
	Node(Node* parent, int value);
	~Node();

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	int value;
	int level = 1;
	int radius = 80;
	bool hovered = false;

	double x;
	double y;

	void draw();
	bool isHovered(int x, int y);
};