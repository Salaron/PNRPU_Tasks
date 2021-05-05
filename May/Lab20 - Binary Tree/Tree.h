#pragma once
#ifndef TREE_HEADER
#define TREE_HEADER
#include "Node.h"
#include <vector>

using namespace std;

template <typename T>
class Tree {
public:
	Tree();

	Node<T>* root = nullptr;
	int nodeRadius = 1;
	int levelHeight = 0;

	void reset();
	virtual void insertNode(Node<T>* node);
	virtual void insertBalanced(T value);
	virtual void insert(T value);
	virtual bool remove(T value);
	virtual Node<T>* find(T value);

	void update();
	void update(Node<T>* node, int col);
	void draw();
	void draw(Node<T>* node);

	void markHovered(int x, int y);
	void markHovered(Node<T>* node, int x, int y);

	int getLeafCount();
	int getLeafCount(Node<T>* node);

	int getHeight();
	int getHeight(Node<T>* node);


	void convertToBalanced();
	void convertToSearch();

	vector<T> getArray();
private:
	bool isSearch = false;

	void getArrayRecurcive(Node<T>*, vector<T>& res);
	Node<T>* getLast(Node<T>*, int, int);
	Node<T>* findRecurcive(Node<T>* node, T value);
};

#include "Tree.cpp"
#endif