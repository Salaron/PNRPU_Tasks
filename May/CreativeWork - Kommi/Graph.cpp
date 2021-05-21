#include "GL/freeglut.h"
#include "Graph.h"
#include <string>
#include "../Lab20 - Binary Tree/glbag.h"

const int maxR = 50;
const int minR = 20;
int R = 20;

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::draw(vector<vector<int>> matrix, vector<string> names, KTree* tree) {
	int count = matrix.size();
	if (m_hover.size() != count) {
		m_hover = {};
		for (int i = 0; i < count; i++) m_hover.push_back(false);
	}
	if (m_coord.size() != count) {
		m_coord = {};
		m_count = count;
		for (int i = 0; i < m_count; i++) set(i, m_count);
	}

	for (int i = 0; i < m_count - 1; i++) {
		for (int j = i+1; j < count; j++) {
			if (i == j) continue;
			if (matrix[i][j] > 0)
				drawLine(matrix[i][j], m_coord[j].x, m_coord[j].y, m_coord[i].x, m_coord[i].y, -1, tree->isInSolution(i, j));
			if (matrix[j][i] > 0)
				drawLine(matrix[j][i], m_coord[i].x, m_coord[i].y, m_coord[j].x, m_coord[j].y, 1, tree->isInSolution(j, i));
		}
	}
	for (int i = 0; i < count; i++) {
		glLineWidth(m_hover[i] == true ? 3 : 1);
		drawCircle(m_coord[i].x, m_coord[i].y, R, circleColor, m_hover[i] == true ?  hoverColor : strokeColor);
		drawText(m_coord[i].x, m_coord[i].y, names[i], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	glLineWidth(1);
	drawMatrix(matrix, names);
}

void Graph::set(int i, int n) {
	int R_;
	int x0 = WINDOW_WIDTH / 2;
	int y0 = WINDOW_HEIGHT / 2;
	if (WINDOW_WIDTH > WINDOW_HEIGHT)
	{
		R = min(max(5 * (WINDOW_WIDTH / 13) / n, minR), maxR);
		R_ = WINDOW_HEIGHT / 2 - R - 10;
	}
	else {
		R = min(max(5 * (WINDOW_WIDTH / 13) / n, minR), maxR);
		R_ = WINDOW_HEIGHT / 2 - R - 10;
	}
	float theta = 2.0f * PI * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;
	O coord{ x1, y1 };
	m_coord.push_back(coord);
}

void Graph::drawLine(int w, int x1, int y1, int x2, int y2, int direction, bool isSolution) {
	Color colorFrom{ 1, 0, 0 };
	Color colorTo{ 0, 0, 1 };
	Color colorSolution{ 0.1f, 0.5f, 0.1f };
	double gap = 0;
	Color color = colorFrom;
	if (direction < 0) {
		color = colorTo;
		gap = 20;
	}
	if (isSolution) {
		color = colorSolution;
		glLineWidth(2);
	}
	else {
		glLineWidth(1);
	}

	double vx = x2 - x1;
	double vy = y2 - y1;
	double len = sqrt(vx * vx + vy * vy);
	double uvx = vx / len;
	double uvy = vy / len;

	if (direction < 0) {
		x1 -= uvy * gap;
		y1 += uvx * gap;
		x2 = x1 + vx;
		y2 = y1 + vy;
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	}
	::drawLine(x1, y1, x2, y2, color);

	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;

	int textX = 0;
	int textY = 0;

	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();

	x1 += R * vx / 2;
	y1 += R * vy / 2;
	drawText(x1 - 18, y1 - 5, to_string(w), GLUT_BITMAP_HELVETICA_18, GL_TEXT_ALIGN_LEFT | GL_TEXT_ALIGN_BOTTOM, color);
}

void Graph::drawMatrix(vector<vector<int>> matrix, vector<string> names) {
	int n = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			string t = to_string(matrix[i][j]);
			if (t.length() > n) n = t.length();
		}
	}
	string res = "   ";
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = 0; j < n - 1; j++) res += "  ";
		res += names[i] + " ";
	}
	res += "\n";

	for (int i = 0; i < names.size(); i++)
	{
		res += names[i] + " ";
		for (int j = 0; j < names.size(); j++)
		{
			if (matrix[i][j] == -1) {
				for (int k = 0; k < n - 1; k++) res += "  ";
				res += "*";
			}
			else {
				for (int k = 0; k < n - to_string(matrix[i][j]).length(); k++) res += "  ";
				res += to_string(matrix[i][j]);
			}
			res += " ";
		}
		res += "\n";
	}
	drawText(WINDOW_WIDTH, 5, res, GLUT_BITMAP_HELVETICA_18, GL_TEXT_ALIGN_RIGHT | GL_TEXT_ALIGN_BOTTOM);
}

void Graph::markHovered(int x, int y) {
	for (int i = 0; i < m_count; i++) {
		if (pow(x - m_coord[i].x, 2) + pow(y - m_coord[i].y, 2) <= pow(R, 2)) {
			m_hover[i] = true;
		}
		else {
			m_hover[i] = false;
		}
	}
}

int Graph::getByCoord(int x, int y) {
	for (int i = 0; i < m_count; i++)
		if (pow(x - m_coord[i].x, 2) + pow(y - m_coord[i].y, 2) <= pow(R, 2)) return i;
	return -1;
}

void Graph::setCoord(int index, int x, int y) {
	m_coord[index].x = x;
	m_coord[index].y = y;
}