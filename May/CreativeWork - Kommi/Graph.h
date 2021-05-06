#pragma once
#include "Kommi.h"
#include "Tree.h"

struct O {
	int x;
	int y;
};

class Graph {
public:
	Graph();
	~Graph();


	void draw(Kommi*, KTree*);
	void markHovered(int x, int y);
private:
	int m_count;
	std::vector<int> m_hover;
	std::vector<O> m_coord;
	void set(int i, int n);
	void drawLine(int w, int x1, int y1, int x2, int y2, int direction, bool isSolution);
	void drawMatrix(Kommi*);
};