#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"
#include "GL/freeglut.h"
#include "math.h"
#include "glbag.h"
#include <string.h>
#include "colors.h"

template <typename T>
Node<T>::Node(T value) {
	this->value = value;
}

template <typename T>
Node<T>::Node(Node<T>* parent, T value) {
	this->parent = parent;
	this->value = value;
}

template <typename T>
Node<T>::~Node() {
	// remove childrens
	if (left) delete left;
	if (right) delete right;
}

template <typename T>
void Node<T>::drawTriangle(Node<T>* child) {
	double vx = x - child->x;
	double vy = y - child->y;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	int x1 = child->x + radius * vx;
	int y1 = child->y + radius * vy;

	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
}

template <typename T>
void Node<T>::draw() {
	// draw line to childrens
	glLineWidth(5);
	if (left) {
		drawLine(x, y, left->x, left->y, lineColor);
		drawTriangle(left);
	}
	if (right) {
		drawLine(x, y, right->x, right->y, lineColor);
		drawTriangle(right);
	}


	// draw main circle
	if (hovered) {
		glLineWidth(3);
	}
	else {
		glLineWidth(1);
	}
	drawCircle(x, y, radius, circleColor, hovered ? hoverColor : strokeColor);

	// draw node value
	drawText(x, y, std::to_string(value), GLUT_BITMAP_TIMES_ROMAN_24);
}

template <typename T>
bool Node<T>::isHovered(int x, int y) {
	return pow(x - this->x, 2) + pow(y - this->y, 2) <= pow(radius, 2);
}
#endif