#pragma once
#include "../Lab20 - Binary Tree/Tree.h"
#include "Node.h"
#include <vector>

class tree : public Tree<int> {
public:
	tree();
	KNode* root = nullptr;

	KNode* insert(KNode* node, std::vector<std::vector<int>> matrix, int value);

	KNode* getMin();
	KNode* getMin(KNode* node);
};