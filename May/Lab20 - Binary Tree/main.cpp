#include <iostream>
#include "GL/freeglut.h"
#include "Tree.h"
#include "Node.h"
#include <vector>
#include "glbag.h"
#include "colors.h"

using namespace std;

extern int WINDOW_WIDTH = 1138;
extern int WINDOW_HEIGHT = 640;

Tree<int> tree;

void initGL() {
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glClearColor(bgColor.red, bgColor.green, bgColor.blue, 1);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void onReshape(int w, int h)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
	tree.update();
	glutPostRedisplay();
}

string help = "+	Add element to tree\n-	Remove element from tree\ns	Convert to binary search tree\nb	Convert to balanced tree\nr	Reset tree\nh	Show this message";
char action = ' ';
bool inCollectMode = false;
string str = "";
string message = help;
void onKeyboardAction(unsigned char key, int x, int y) {
	if (inCollectMode && key != 13 && (key >= '0' && key <= '9' || key == 8)) {
		if (key == 8 && str.length() > 0) { // backspace			
			cout << "\b \b";
			str = str.substr(0, str.size() - 1);
			message = message.substr(0, message.size() - 1);
		}
		else {
			cout << key;
			str += key;
			message += key;
		}
	}
	if (inCollectMode && key == 13) {
		switch (action) {
		case '+':
			tree.insertBalanced(atoi(str.c_str()));
			break;
		case '-':
			tree.remove(atoi(str.c_str()));
			break;
		}
		message = str = "";
		action = ' ';
		inCollectMode = false;
		cout << endl;
	}
	else if (!inCollectMode) {
		switch (key) {
		case 'h':
		case 'р':
			message = help;
			cout << help << endl;
			break;

		case '+':
			message = "Enter a value: ";
			cout << message;
			inCollectMode = true;
			action = '+';
			break;
		case '-':
			message = "Enter a value: ";
			cout << message;
			inCollectMode = true;
			action = '-';
			break;

		case 'ы':
		case 's':
			message = "Binary search tree";
			cout << message << endl;
			tree.convertToSearch();
			break;

		case 'и':
		case 'b':
			message = "Balanced tree";
			cout << message << endl;
			tree.convertToBalanced();
			break;
		case 'r':
			message = "Reset tree";
			cout << message << endl;
			tree.reset();
			break;
		}
	}
	glutPostRedisplay();
}

string debugMessage = "";
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	tree.draw(); // draw treeeeeeee
	drawText(WINDOW_WIDTH - 5, WINDOW_HEIGHT - glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24), "Laws: " + to_string(tree.getLeafCount()), GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_RIGHT);
	if (message.length() > 0) {
		drawText(5, WINDOW_HEIGHT - glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24), message, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	}
	drawText(5, 5, debugMessage, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	glutSwapBuffers();
}

void onMouseMove(int x, int y) {
	tree.markHovered(x, WINDOW_HEIGHT - y);
#ifdef _DEBUG
	debugMessage = to_string(x) + " " + to_string(WINDOW_HEIGHT - y);
#endif
	glutPostRedisplay(); // redraw
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Binary Tree");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(onKeyboardAction);
	glutPassiveMotionFunc(onMouseMove);
	cout << "Note: press buttons in the main window, not console!" << endl;
	cout << help << endl;
	glutMainLoop();
	return 0;
}