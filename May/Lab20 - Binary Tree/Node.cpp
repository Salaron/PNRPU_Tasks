#include "Node.h"
#include "GL/freeglut.h"
#include "math.h"
#include "glbag.h"
#include <string.h>

#define PI 3.14159265358979323846

Node::Node(int value) {
	this->value = value;
}

Node::Node(Node* parent, int value) {
	this->parent = parent;
	this->value = value;
}

Node::~Node() {
	// remove childrens
	if (left) delete left;
	if (right) delete right;
}

void Node::draw() {
	// draw line to childrens
	glColor3f(0, 1, 1);
	glLineWidth(5);
	if (left) {
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(left->x, left->y);
		glEnd();
	}
	if (right) {
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(right->x, right->y);
		glEnd();
	}

	// draw main circle
	int iterations = 1000;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < iterations; i++) {
		double x1 = radius * cos(2 * PI * (i / (iterations * 1.0))) + x;
		double y1 = radius * sin(2 * PI * (i / (iterations * 1.0))) + y;
		glVertex2f(x1, y1);
	}
	glEnd();

	// draw line around
	if (hovered) {
		glColor3f(0.0, 0.0, 1.0f);
		glLineWidth(3);
	}
	else {
		glColor3f(0, 0, 0);
		glLineWidth(1);
	}
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 1000; i++) {
		double x1 = radius * cos(2 * PI * (i / (iterations * 1.0))) + x;
		double y1 = radius * sin(2 * PI * (i / (iterations * 1.0))) + y;
		glVertex2f(x1, y1);
	}
	glEnd();

	// draw node value
	drawText(x, y, std::to_string(value), GLUT_BITMAP_TIMES_ROMAN_24);
}

bool Node::isHovered(int x, int y) {
	return pow(x - this->x, 2) + pow(y - this->y, 2) <= pow(radius, 2);
}