#pragma once
#include <vector>
#include "../Lab20 - Binary Tree/Node.h"
#include "Kommi.h"
#include "Edge.h"

class KNode: public Node<int> {
public:
	using Node<int>::Node;
	KNode(KNode* node, std::vector<std::vector<int>> matrix, int w);
	KNode(std::vector<std::vector<int>> matrix, int w);
	~KNode();

	void draw();

	KNode* parent = nullptr;
	KNode* left = nullptr;
	KNode* right = nullptr;

	bool excluded = false;

	Edge edge;

	std::vector<std::vector<int>> m_matrix;
};