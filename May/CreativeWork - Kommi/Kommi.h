#pragma once
#include <vector>
#include <string>
#include <iostream>

class Edge {
public:
	int from;
	int to;

	friend std::ostream& operator <<(std::ostream& out, Edge& edge) {
		out << edge.from + 1 << " -> " << edge.to + 1;
		return out;
	}
};

class Kommi {
	int m_count;
	std::vector<std::string> m_names;
	std::vector<std::vector<int>> m_matrix;
public:
	Kommi();
	~Kommi();

	void init();
	
	void PrintMatrix();
	void PrintMatrix(std::vector<std::vector<int>>& matrix);


	// easy method: find all Edges
	// don't check cost
	std::vector<Edge> SolveEasy();
	std::vector<Edge> SolveHard();

	bool CheckMatrix(std::vector<std::vector<int>> matrix);


	int findMin(std::vector<std::vector<int>>& matrix, int x, int y, bool isRow);
	int Reduct(std::vector<std::vector<int>>& matrix, bool isRow);
	Edge FindEdge(std::vector<std::vector<int>>& matrix);

	int Exclude(std::vector<std::vector<int>>& matrix, Edge edge);
	int Include(std::vector<std::vector<int>>& matrix, Edge edge);
};