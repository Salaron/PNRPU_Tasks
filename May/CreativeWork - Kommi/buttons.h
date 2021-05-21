#pragma once
#include <string>
#include <vector>
#include "GL/freeglut.h"
using namespace std;

typedef void (*cb)();

class Button {
	int x, y;
	int width, height;
	std::string text;
	cb callback;
	bool hovered = false;
public:
	Button(int x, int y, int width, int h, string text, void* callback) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = h;
		this->text = text;
		this->callback = static_cast<cb>(callback);
	}

	void draw() {
		if (hovered) {
			glColor3f(0, 1, 1);
		}
		else {
			glColor3f(0, 0, 0);
		}
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2i(x, y);
		glVertex2i(x + width, y);
		glVertex2i(x + width, y - height);
		glVertex2i(x, y - height);
		glEnd();

		const int midX = x + width / 2;
		const int midY = y - height / 2 - glutBitmapHeight(GLUT_BITMAP_HELVETICA_18) / 4;

		drawText(midX, midY, text, GLUT_BITMAP_HELVETICA_18, GL_TEXT_ALIGN_CENTER, Color{ 0,0,0 });
		glLineWidth(1);
	}

	void onClick(int clickX, int clickY) {
		// check if click is inside button
		if (isInside(clickX, clickY)) {
			// call callback
			if (this->callback != nullptr) {
				this->callback();
			}
		}
	}

	void onHover(int mouseX, int mouseY) {
		hovered = isInside(mouseX, mouseY);
	}

private:
	bool isInside(int pointX, int pointY) {
		if (pointX >= x && pointX <= x + width && pointY <= y && pointY >= y - height) {
			return true;
		}
		return false;
	}
};

class Buttons {
public:
	vector<Button*> btns;
	static bool hide;

	
	static string result;
	cb onKeyboardFinish;
	void static keyboardInput(unsigned char key, int x, int y) {
		if (key != 13) {
			result += key;
		}
		if (key == 13) {
			//on enter
			
		}
	}

	void static addNode() {
		hide = true;
		Kommi::instance()->addNode();
		hide = false;
	}

	void static removeNode() {
		Kommi::instance()->removeNode();
	}

	void static addLine() {
		Kommi::instance()->addLine();
	}

	void static removeLine() {
		Kommi::instance()->removeLine();
	}

	void create() {
		Buttons::hide = false;
		Buttons::result = "";
		btns.push_back(new Button(15, 570, 150, 50, "Add Node", (void*)this->addNode));
		btns.push_back(new Button(15, 500, 150, 50, "Remove Node", (void*)this->removeNode));
		btns.push_back(new Button(15, 430, 150, 50, "Add Line", (void*)this->addLine));
		btns.push_back(new Button(15, 360, 150, 50, "Remove Line", (void*)this->removeLine));
	}
	void draw() {
		if (hide) return;
		for (const auto& button : btns) {
			button->draw();
		}
	}
	void onClick(int x, int y) {
		if (hide) return;
		for (const auto& button : btns) {
			button->onClick(x, y);
		}
	}

	void onHover(int x, int y) {
		if (hide) return;
		for (const auto& button : btns) {
			button->onHover(x, y);
		}
	}
};

bool Buttons::hide = false;
string Buttons::result = "";