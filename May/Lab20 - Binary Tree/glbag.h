#pragma once
#include "GL/freeglut.h"
#include <string>

inline void drawText(double x, double y, std::string str, void* font) {
	glColor3f(0, 0, 0);
	int j = str.length();
	double textWidth = 0;
	for (int i = 0; i < j; i++) {
		textWidth += glutBitmapWidth(font, str[i]);
	}

	glRasterPos2f(x - textWidth / 2, y - 4);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(font, str[i]);
	}
}