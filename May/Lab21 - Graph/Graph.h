#pragma once
#include <vector>
#include <string>
struct O {
	int x;
	int y;
};

class Graph {
public:
	Graph();
	~Graph();


	void markHovered(int x, int y);
	int getByCoord(int x, int y);
	void setCoord(int index, int x, int y);
	void draw(std::vector<std::vector<int>> matrix, std::vector<std::string> names);
	void drawMatrix(std::vector<std::vector<int>> matrix, std::vector<std::string> names);
private:
	int m_count;
	std::vector<int> m_hover;
	std::vector<O> m_coord;
	void set(int i, int n);
	void drawLine(int w, int x1, int y1, int x2, int y2, int direction);
};