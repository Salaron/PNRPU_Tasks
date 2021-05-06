#include "GL/freeglut.h"
#include "Graph.h"
#include <string>
#include "../Lab20 - Binary Tree/glbag.h"

int R = 50;

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::draw(Kommi* kommi, KTree* tree) {
	if (m_hover.size() != kommi->m_count) {
		for (int i = 0; i < kommi->m_count; i++) m_hover.push_back(false);
	}
	m_coord = {};
	m_count = kommi->m_count;
	for (int i = 0; i < m_count; i++) {
		set(i, kommi->m_count);
	}
	for (int i = 0; i < m_count - 1; i++) {
		for (int j = i+1; j < kommi->m_count; j++) {
			if (i == j) continue;
			if (kommi->m_matrix[i][j] > 0)
				drawLine(kommi->m_matrix[i][j], m_coord[j].x, m_coord[j].y, m_coord[i].x, m_coord[i].y, -1, tree->isInSolution(i, j));
			if (kommi->m_matrix[j][i] > 0)
				drawLine(kommi->m_matrix[j][i], m_coord[i].x, m_coord[i].y, m_coord[j].x, m_coord[j].y, 1, tree->isInSolution(j, i));
		}
	}
	for (int i = 0; i < kommi->m_count; i++) {
		glLineWidth(m_hover[i] == true ? 3 : 1);
		drawCircle(m_coord[i].x, m_coord[i].y, R, circleColor, m_hover[i] == true ?  hoverColor : strokeColor);
		drawText(m_coord[i].x, m_coord[i].y, kommi->m_names[i], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	glLineWidth(1);
	drawMatrix(kommi);
	drawText(WINDOW_WIDTH - 5, WINDOW_HEIGHT - 20, "Way: " + kommi->getSolutionPath(tree) + "\nLen: " + to_string(tree->wayLen), GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_RIGHT);
}

void Graph::set(int i, int n) {
	int R_;
	int x0 = WINDOW_WIDTH / 2;
	int y0 = WINDOW_HEIGHT / 2;
	if (WINDOW_WIDTH > WINDOW_HEIGHT)
	{
		R = 5 * (WINDOW_WIDTH / 13) / n;
		R_ = WINDOW_HEIGHT / 2 - R - 10;
	}
	else {
		R = 5 * (WINDOW_WIDTH / 13) / n;
		R_ = WINDOW_HEIGHT / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;
	O coord{ x1, y1 };
	m_coord.push_back(coord);
}

void Graph::drawLine(int w, int x1, int y1, int x2, int y2, int direction, bool isSolution) {
	Color normal{ 1, 0, 0 };
	Color normal2{ 0, 0, 1 };
	Color normal3{ 0.1f, 0.5f, 0.1f };
	double gap = 0;
	Color color = normal;
	if (direction < 0) {
		color = normal2;
		gap = 20;
	}
	if (isSolution) {
		color = normal3;
		glLineWidth(2);
	}
	else {
		glLineWidth(1);
	}
	glColor3f(color.red, color.green, color.blue);

	double vx = x2 - x1;
	double vy = y2 - y1;
	double len = sqrt(vx * vx + vy * vy);
	double uvx = vx / len;
	double uvy = vy / len;

	glBegin(GL_LINES);
	if (direction > 0) {
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	}
	else {
		x1 -= uvy * gap;
		y1 += uvx * gap;
		x2 = x1 + vx;
		y2 = y1 + vy;
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	}
	glEnd();

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

void Graph::drawMatrix(Kommi* kommi) {
	int n = 0;
	for (int i = 0; i < kommi->m_matrix.size(); i++) {
		for (int j = 0; j < kommi->m_matrix[i].size(); j++) {
			string t = to_string(kommi->m_matrix[i][j]);
			if (t.length() > n) n = t.length();
		}
	}
	string res = "   ";
	for (int i = 0; i < kommi->m_names.size(); i++)
	{
		for (int j = 0; j < n - 1; j++) res += "  ";
		res += kommi->m_names[i] + " ";
	}
	res += "\n";

	for (int i = 0; i < kommi->m_count; i++)
	{
		res += kommi->m_names[i] + " ";
		for (int j = 0; j < kommi->m_count; j++)
		{
			if (kommi->m_matrix[i][j] == -1) {
				for (int k = 0; k < n - 1; k++) res += "  ";
				res += "*";
			}
			else {
				for (int k = 0; k < n - to_string(kommi->m_matrix[i][j]).length(); k++) res += "  ";
				res += to_string(kommi->m_matrix[i][j]);
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