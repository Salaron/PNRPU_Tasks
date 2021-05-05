#pragma once
#include "GL/freeglut.h"
#include <string>
#include <vector>
#include <sstream>

#define PI 3.14159265358979323846

struct Color {
	double red;
	double green;
	double blue;
};

enum ALIGN {
	GL_TEXT_ALIGN_LEFT = 1,
	GL_TEXT_ALIGN_CENTER = 2
};

inline void drawText(double x, double y, std::string text, void* font, ALIGN align = GL_TEXT_ALIGN_CENTER) {
	glColor3f(0, 0, 0);

	auto strings = std::vector<std::string>{};
	auto ss = std::stringstream{ text };

	for (std::string line; std::getline(ss, line, '\n');)
		strings.push_back(line);
			
	int count = 0;
	for (auto const& str : strings) {
		int j = str.length();
		double textWidth = 0;
		for (int i = 0; i < j; i++) {
			textWidth += glutBitmapWidth(font, str[i]);
		}

		int cx = x;
		if (align == GL_TEXT_ALIGN_CENTER) {
			cx -= textWidth / 2;
		}

		glRasterPos2f(cx, y - 4 - (count * 20));
		for (int i = 0; i < j; i++) {
			glutBitmapCharacter(font, str[i]);
		}
		count++;
	}
}

inline void drawCircle(double x, double y, int radius, Color main, Color stroke) {
	int iterations = 1000;
	glColor3f(main.red, main.green, main.blue);
	glBegin(GL_POLYGON);
	for (int i = 0; i < iterations; i++) {
		double x1 = radius * cos(2 * PI * (i / (iterations * 1.0))) + x;
		double y1 = radius * sin(2 * PI * (i / (iterations * 1.0))) + y;
		glVertex2f(x1, y1);
	}
	glEnd();
	
	glColor3f(stroke.red, stroke.green, stroke.blue);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 1000; i++) {
		double x1 = radius * cos(2 * PI * (i / (iterations * 1.0))) + x;
		double y1 = radius * sin(2 * PI * (i / (iterations * 1.0))) + y;
		glVertex2f(x1, y1);
	}
	glEnd();
}

inline void drawLine(double x1, double y1, double x2, double y2, Color color) {
	glColor3f(color.red, color.green, color.blue);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

