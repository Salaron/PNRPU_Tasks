#include <iostream>
#include "GL/freeglut.h"
#include <vector>
#include "../Lab20 - Binary Tree/glbag.h"

using namespace std;

// you know from where these values come
extern int WINDOW_WIDTH = 1138;
extern int WINDOW_HEIGHT = 640;

void initGraph() {
	
}

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

void onKeyboardAction(unsigned char key, int x, int y) {
	glutPostRedisplay();
}

string debugMessage = "";
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawText(10, 10, debugMessage, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	glutSwapBuffers();
}

void onMouseMove(int x, int y) {
#ifdef _DEBUG
	debugMessage = to_string(x) + " " + to_string(WINDOW_HEIGHT - y);
#endif
	glutPostRedisplay(); // redraw
}

int main(int argc, char* argv[]) {
	initGraph();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Graph");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	//glutIdleFunc(display); // never do like this
	glutKeyboardFunc(onKeyboardAction);
	glutPassiveMotionFunc(onMouseMove);
	cout << "Note: press buttons in the main window, not console!" << endl;
	glutMainLoop();
	return 0;
}