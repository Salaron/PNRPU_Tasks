#pragma once
#include <vector>
#include <string>
#include "Edge.h"
#include "Tree.h"

class KTree;

class Kommi {
	int m_count;
	std::vector<std::string> m_names;
	std::vector<std::vector<int>> m_matrix;
public:
	bool recompute = false;
	Kommi();
	~Kommi();

	void init();

	void addNode();
	void removeNode();
	void addLine();
	void removeLine();
	
	std::vector<std::string> getNames();
	std::vector<std::vector<int>> getMatrix();

	void PrintMatrix();
	void PrintMatrix(std::vector<std::vector<int>>& matrix);

	KTree* Solve(bool stupidSolution);
	std::string getSolutionPath(KTree* tree);
	bool checkSolution(KTree* tree);

	bool CheckMatrix(std::vector<std::vector<int>> matrix);
	int findMin(std::vector<std::vector<int>>& matrix, int x, int y, bool isRow);
	int Reduct(std::vector<std::vector<int>>& matrix, bool isRow);
	Edge FindEdge(std::vector<std::vector<int>>& matrix);
	bool findLoop(std::vector<std::vector<int>>& matrix, std::vector<Edge>& path);

	int Exclude(std::vector<std::vector<int>>& matrix, Edge edge, std::vector<Edge>& zeros);
	int Include(std::vector<std::vector<int>>& matrix, Edge edge, std::vector<Edge>& zeros);

	static Kommi* instance();

	friend class Graph;
};