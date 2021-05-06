#pragma once
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