#include <iostream>
#include "Kommi.h"
#include <sstream>

using namespace std;

extern int WINDOW_WIDTH = 1138;
extern int WINDOW_HEIGHT = 640;

Kommi kommi;

int main(int argc, char* argv[]) {
	stringstream ss{ "5 1 2 3 4 5 20 18 12 8 5 14 7 11 12 18 6 11 11 17 11 12 5 5 5 5" };
	system("chcp 1251>nul");
	cin.rdbuf(ss.rdbuf());
	kommi.init();
	kommi.PrintMatrix();
	kommi.SolveEasy();
	kommi.SolveHard();
	return 0;
}