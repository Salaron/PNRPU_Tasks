#pragma once
#include "../Lab20 - Binary Tree/Tree.h"
#include "Node.h"
#include <vector>
#include "Edge.h"

class KNode;

class KTree : public Tree<int> {
public:
	KTree();
	KNode* root = nullptr;

	int wayLen = 0;
	std::vector<Edge> solution;

	bool isInSolution(int i, int j);

	int getHeight();
	int getHeight(KNode* node);

	void draw();
	void draw(KNode* node);
	KNode*& insert(KNode* node, std::vector<std::vector<int>> matrix, int value);

	KNode* getMin();
	KNode* getMin(KNode* node);

	void update();
	void update(KNode* node, int col);
};