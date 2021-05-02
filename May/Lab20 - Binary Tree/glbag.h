#pragma once
#include "GL/freeglut.h"
#include <string>
#include <vector>
#include <sstream>

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