#pragma once
#include "Node.h"
#include <vector>

using namespace std;

class Tree {
public:
	Tree();

	Node* root = nullptr;
	int nodeRadius = 1;
	int levelHeight = 0;

	void reset();
	void insertNode(Node* node);
	void insertBalanced(int value);
	void insert(int value);
	bool remove(int value);
	Node* find(int value);

	void update();
	void draw();
	void markHovered(int x, int y);


	int getLeafCount();
	int getHeight();

	void convertToBalanced();
	void convertToSearch();

	vector<int> getArray();
private:
	bool isSearch = false;
	void drawRecurcive(Node* node);
	void updateRecurcive(Node* node, int col);
	void markHoveredRecurcive(Node* node, int x, int y);
	int  getLeafCountRecurcive(Node* node);
	int  getHeightRecurcive(Node* node);

	void getArrayRecurcive(Node*, vector<int>& res);

	Node* getLast(Node*, int, int);
	Node* findRecurcive(Node* node, int value);
};