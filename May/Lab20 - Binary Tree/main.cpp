#include <iostream>
#include "GL/freeglut.h"
#include "Tree.h"
#include "Node.h"
#include <vector>
#include "glbag.h"

using namespace std;

extern int WINDOW_WIDTH = 960;
extern int WINDOW_HEIGHT = 640;

Tree tree;

void initGL() {
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void onReshape(int w, int h)
{
	// don't allow to resize the window
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

char action = ' ';
bool inCollectMode = false;
string str = "";
string message = "";
void onKeyboardAction(unsigned char key, int x, int y) {
	if (inCollectMode && key != 13 && key >= '0' && key <= '9') {
		cout << key;
		str += key;
		message += key;
		if (key == 8) { // backspace
			cout << " \b";
			str = str.substr(0, str.size() - 2);
			message = message.substr(0, message.size() - 2);
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
		cout << "\n";
	}
	else if (!inCollectMode) {
		switch (key) {
		case 'h':
		case 'р':
			cout << "help lol" << endl;
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

		case 'и':
		case 'b':
			cout << "Convert to binary search tree!" << endl;
			tree.convertToBinary();
			break;

		case 'т':
		case 'n':
			cout << "Convert to balanced tree!" << endl;
			tree.convertToBalanced();
		}
	}
	glutPostRedisplay();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	tree.draw(); // draw treeeeeeee
	drawText(WINDOW_WIDTH - 70, WINDOW_HEIGHT - 18, "Laws: " + to_string(tree.getLeafCount()), GLUT_BITMAP_TIMES_ROMAN_24);
	if (message.length() > 0) {
		drawText(123, WINDOW_HEIGHT - 18, message, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	glutSwapBuffers();
}


void onMouseMove(int x, int y) {
	tree.markHovered(x, WINDOW_HEIGHT - y);
	glutPostRedisplay(); // redraw
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Test");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	//glutIdleFunc(display); // never do like this
	glutKeyboardFunc(onKeyboardAction);
	glutPassiveMotionFunc(onMouseMove);
	glutMainLoop();
	return 0;
}