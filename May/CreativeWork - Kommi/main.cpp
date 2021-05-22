#include <iostream>
#include <sstream>
#include "Kommi.h"
#include "Tree.h"
#include "Graph.h"
#include "buttons.h"

using namespace std;

extern int WINDOW_WIDTH = 1138;
extern int WINDOW_HEIGHT = 720;

Kommi* kommi = Kommi::instance();
Graph graph;
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
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void onKeyboardAction(unsigned char key, int x, int y) {
}

int dragIndex = -1;
Buttons buttons;

void onMouseClick(int button, int state, int x, int y) {
	y = WINDOW_HEIGHT - y;
	cout << x << " " << y << endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		buttons.onClick(x, y);
	}
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && dragIndex == -1) {
		if (!(x <= 0 || x >= WINDOW_WIDTH || y <= 0 || y >= WINDOW_HEIGHT))
			dragIndex = graph.getByCoord(x, y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		dragIndex = -1;
	}
}

string debugMessage = "";
void onMouseMove(int x, int y) {
	y = WINDOW_HEIGHT - y;
	buttons.onHover(x, y);
	graph.markHovered(x, y);
	if (dragIndex != -1) {
		if (!(x <= 0 || x >= WINDOW_WIDTH || y <= 0 || y >= WINDOW_HEIGHT))
			graph.setCoord(dragIndex, x, y);
	}
#ifdef _DEBUG
	debugMessage = to_string(x) + " " + to_string(y);
#endif
	glutPostRedisplay(); // redraw
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (kommi->recompute == true) {
		//delete easy;
		//easy = kommi.Solve(true);
		delete hard;
		hard = kommi->Solve(false);
		kommi->recompute = false;
	}
	graph.draw(kommi->getMatrix(), kommi->getNames(), hard);
	if (hard->haveSolution) {
		string solution = kommi->getSolutionPath(hard);
		drawText(WINDOW_WIDTH - 5, WINDOW_HEIGHT - 20, kommi->getSolutionPath(hard) + (solution != "No solution" ? "\n" + to_string(hard->wayLen) + " Km" : ""), GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_RIGHT);
	}
	else {
		drawText(WINDOW_WIDTH - 5, WINDOW_HEIGHT, "No solution", GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_RIGHT);
	}
	graph.drawMatrix(kommi->getMatrix(), kommi->getNames());

	buttons.draw();

	drawText(10, 10, debugMessage, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	// example matrix
	stringstream ss{ "5 1 2 3 4 5 20 18 12 8 5 14 7 11 12 18 6 11 11 17 11 12 5 5 5 5" };
	stringstream ss2{ "6 1 2 3 4 5 6 26 42 15 29 25 7 16 1 30 25 20 13 35 5 0 21 16 25 18 18 12 46 27 48 5 23 5 5 9 5" };
	stringstream ss3{ "6 a b c 4 5 6 7 16 21 2 17 13 21 15 43 23 25 3 31 17 9 13 10 27 33 12 9 2 19 14 51 42 17 5 9 23" };
	//cin.rdbuf(ss2.rdbuf()); // auto-input (for debuging)
	kommi->init();
	kommi->PrintMatrix();
	buttons.create();
	KTree* easy = kommi->Solve(true);
	cout << easy->wayLen << endl;
	cout << kommi->getSolutionPath(easy) << endl;

	hard = kommi->Solve(false);
	cout << hard->wayLen << endl;
	cout << kommi->getSolutionPath(hard) << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Kommi");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(onKeyboardAction);
	glutMouseFunc(onMouseClick);
	glutMotionFunc(onMouseMove);
	glutPassiveMotionFunc(onMouseMove);
	glutMainLoop();
	return 0;
}