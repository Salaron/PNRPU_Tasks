#include <iostream>
#include <sstream>
#include "GL/freeglut.h"
#include "../Lab20 - Binary Tree/glbag.h"
#include "Graph.h"
#include "Dijkstra.h"

using namespace std;

extern int WINDOW_WIDTH = 960;
extern int WINDOW_HEIGHT = 640;

Graph graph;
Dijkstra dijkstra;

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
	glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

int dragIndex = -1;
void onMouseClick(int button, int state, int x, int y) {
	y = WINDOW_HEIGHT - y;
	cout << x << " " << y << endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && dragIndex == -1) {
		dragIndex = graph.getByCoord(x, y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		dragIndex = -1;
	}
}

string debugMessage = "";
void onMouseMove(int x, int y) {
	y = WINDOW_HEIGHT - y;
	graph.markHovered(x, y);
	if (dragIndex != -1) {
		graph.setCoord(dragIndex, x, y);
	}
#ifdef _DEBUG
	debugMessage = to_string(x) + " " + to_string(y);
#endif
	glutPostRedisplay(); // redraw
}

bool inited = false;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	vector<vector<int>> matrix = {
		{-1, 14, -1, -1, -1, -1},
		{-1, -1, -1, -1, 42, 23},
		{19, -1, -1,  9, -1, -1},
		{-1, -1, -1, -1, -1, 31},
		{-1, -1, 18, -1, -1, -1},
		{28, 23, -1, -1, -1, -1}
	};
	vector<string> names = { "1", "2", "3", "4", "5", "6" };
	graph.draw(matrix, names);
	if (inited == false) {
		dijkstra.Init(matrix, names);
		dijkstra.Work("3");
		inited = true;
	}
	drawText(10, 10, debugMessage, GLUT_BITMAP_TIMES_ROMAN_24, GL_TEXT_ALIGN_LEFT);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Graph");
	initGL();
	glutReshapeFunc(onReshape);
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMotionFunc(onMouseMove);
	glutPassiveMotionFunc(onMouseMove);
	glutMainLoop();
	return 0;
}