#include "Node.h"
#include "GL/freeglut.h"

using namespace std;

KNode::KNode(vector<vector<int>> matrix, int min): Node(min) {
	m_matrix = matrix;
	value = min;
}

KNode::KNode(KNode* parent, vector<vector<int>> matrix, int min): KNode(matrix, min) {
	this->parent = parent;
}

KNode::~KNode() {

}

void KNode::draw() {
	glColor3f(0, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x + 50, y);
	glVertex2i(x + 50, y - 30);
	glVertex2i(x, y - 30);
	glEnd();
}