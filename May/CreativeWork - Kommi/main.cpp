#include <iostream>
#include <sstream>
#include "Tree.h"
#include "Kommi.h"
#include "Graph.h"

using namespace std;

extern int WINDOW_WIDTH = 960;
extern int WINDOW_HEIGHT = 640;

Graph graph;
Kommi kommi;
KTree* easy;
KTree* hard;

void initGL() {
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glClearColor(bgColor.red, bgColor.green, bgColor.blue, 1);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void onReshape(int w, int h)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	glViewport(0, 0, (GLsizei)WINDOW_WIDTH, (GLsizei)WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WINDOW_WIDTH, 0, (GLdouble)WINDOW_HEIGHT);
	glutPostRedisplay();
}

void onKeyboardAction(unsigned char key, int x, int y) {

}

string debugMessage = "";
void onMouseMove(int x, int y) {
	graph.markHovered(x, WINDOW_HEIGHT - y);
#ifdef _DEBUG
	debugMessage = to_string(x) + " " + to_string(WINDOW_HEIGHT - y);
#endif
	glutPostRedisplay(); // redraw
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	graph.draw(&kommi, hard);
	//hard->draw(); // draw treeeeeeee

	drawText(10, 10, debugMessage, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	// example matrix
	stringstream ss{ "5 1 2 3 4 5 20 18 12 8 5 14 7 11 12 18 6 11 11 17 11 12 5 5 5 5" };
	stringstream ss2{ "6 1 2 3 4 5 6 26 42 15 29 25 7 16 1 30 25 20 13 35 5 0 21 16 25 18 18 12 46 27 48 5 23 5 5 9 5" }; // TODO: investigate cycle
	stringstream ss3{ "6 a b c 4 5 6 7 16 21 2 17 13 21 15 43 23 25 3 31 17 9 13 10 27 33 12 9 2 19 14 51 42 17 5 9 23" };
	cin.rdbuf(ss3.rdbuf());
	kommi.init();
	kommi.PrintMatrix();
	easy = kommi.Solve(true);
	cout << easy->wayLen << endl;
	cout << kommi.getSolutionPath(easy) << endl;

	hard = kommi.Solve(false);
	cout << hard->wayLen << endl;
	cout << kommi.getSolutionPath(hard) << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Kommi");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(onKeyboardAction);
	glutPassiveMotionFunc(onMouseMove);
	glutMainLoop();
	return 0;
}