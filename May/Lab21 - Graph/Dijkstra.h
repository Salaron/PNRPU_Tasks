#pragma once
#include <vector>
#include <string>

class Dijkstra {
	int m_count;
	std::vector<std::string> m_names;
	std::vector<std::vector<int>> m_matrix;
public:
	Dijkstra();
	~Dijkstra();

	void Init(std::vector<std::vector<int>> matrix, std::vector<std::string> names);
	void Work(std::string startName);
};