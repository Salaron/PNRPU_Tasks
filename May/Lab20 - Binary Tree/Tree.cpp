#ifndef TREE_CPP
#define TREE_CPP
#include "Tree.h"
#include "Node.h"
#include <math.h>
#include <algorithm>
#include <iostream>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

const int MIN_RADIUS = 15;
const int MAX_RADIUS = 80;

template <typename T>
Tree<T>::Tree(void) {

}

template <typename T>
void Tree<T>::insertNode(Node<T>* node) {
	if (root == nullptr) {
		root = node;
	}
	else {
		Node<T>* lastNode = getLast(root, 1, getHeight());
		if (lastNode == nullptr) {
			lastNode = root;
			while (lastNode->left != nullptr) {
				lastNode = lastNode->left;
			}
		}

		if (lastNode->left == nullptr) {
			lastNode->left = node;
		}
		else if (lastNode->right == nullptr)
		{
			lastNode->right = node;
		}
		node->parent = lastNode;
	}
	update();
}

template <typename T>
void Tree<T>::insertBalanced(T value) {
	if (root == nullptr) {
		root = new Node<T>(value);
	}
	else {
		int h = getHeight();
		Node<T>* cur = getLast(root, 1, h);
		if (cur == nullptr) {
			cur = root;
			while (cur->left != nullptr) {
				cur = cur->left;
			}
		}
		
		if (cur->left == nullptr) {
			cur->left = new Node<T>(cur, value);
		}
		else if (cur->right == nullptr) {
			cur->right = new Node<T>(cur, value);
		}
	}
	update();
}

template <typename T>
Node<T>* Tree<T>::getLast(Node<T>* node, int level, int lastLevel) {
	if (level == lastLevel)
		return nullptr;
	if (level < lastLevel && node->left == nullptr || node->right == nullptr)
		return node;
	Node<T>* tmp = getLast(node->left, level + 1, lastLevel);
	if (tmp != nullptr) return tmp;
	return getLast(node->right, level + 1, lastLevel);
}

template <typename T>
void Tree<T>::insert(T value) {
	Node<T>* r = root;
	Node<T>* current = root;
	while (current) {
		r = current;
		if (current->value > value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	if (!r) {
		root = new Node<T>(value);
	}
	else {
		current = new Node<T>(r, value);
		if (value < r->value) {
			r->left = current;
		}
		else {
			r->right = current;
		}
	}

	update();
}

template <typename T>
bool Tree<T>::remove(T value) {
	Node<T>* node = find(value);
	if (node == nullptr) {
		return false;
	}

	Node<T>* parent = node->parent;
	Node<T>* left = node->left;
	Node<T>* right = node->right;
	if (parent == nullptr) {
		// this is root node
		// make one of child as root and connect second parent to the new tree 
		bool rootAssigned = false;
		if (left != nullptr) {
			root = left;
			left->parent = nullptr;
			rootAssigned = true;
		}
		if (right != nullptr) {
			if (rootAssigned) {
				insertNode(right);
				// rebuild tree
				if (isSearch)
					convertToSearch();
				else
					convertToBalanced();
			}
			else {
				root = right;
				right->parent = nullptr;
				rootAssigned = true;
			}
		}
		if (!rootAssigned) {
			delete root;
			root = nullptr;
		}
	}
	else {
		// connect parent to childs of the node
		Node<T>*& test = parent->left == node ? parent->left : parent->right;
		if (node->left != nullptr && node->right != nullptr) {
			// the node have 2 childs
			// connect left child to the parent of the node
			// and insert right node to the tree
			parent->left = node->left;
			node->left->parent = parent;
			insertNode(node->right);
			// rebuild tree
			if (isSearch)
				convertToSearch();
			else
				convertToBalanced();
		}
		else if (node->left != nullptr) {
			// connect left child to the parent of the node
			test = node->left;
			node->left->parent = parent;

		}
		else if (node->right != nullptr) {
			// connect right child to the parent of this node
			test = node->right;
			node->right->parent = parent;
		}
		else {
			// node doesn't have childs
			// disconnect it from parent
			test = nullptr;
		}

		// disconnect childs to prevent calling theirs destructors
		node->left = node->right = nullptr;
		// and remove the node
		delete node;
	}

	update();
	return true;
}

template <typename T>
void Tree<T>::reset() {
	delete root;
	root = nullptr;
}

template <typename T>
Node<T>* Tree<T>::find(T value) {
	return findRecurcive(root, value);
}

template <typename T>
Node<T>* Tree<T>::findRecurcive(Node<T>* node, T value) {
	if (node == nullptr) return nullptr;
	if (node->value == value) return node;
	Node<T>* tmp = findRecurcive(node->left, value);
	if (tmp != nullptr) return tmp;
	return findRecurcive(node->right, value);
}

template <typename T>
void Tree<T>::convertToBalanced() {
	vector<int> tree = getArray();
	sort(tree.begin(), tree.end());
	delete root;
	root = nullptr;
	isSearch = false;
	for (int i = 0; i < tree.size(); i++) {
		insertBalanced(tree[i]);
	}
}

template <typename T>
void Tree<T>::convertToSearch() {
	// collect all data to array
	// sort it
	// root is middle
	vector<int> tree = getArray();
	sort(tree.begin(), tree.end());

	// remove current root
	delete root;
	root = nullptr;
	isSearch = true;
	if (tree.size() > 0) {
		int middle = tree.size() / 2;
		root = new Node<T>(tree[middle]);
		for (int i = 0; i < middle; i++) {
			insert(tree[i]);
		}
		for (int i = middle + 1; i < tree.size(); i++) {
			insert(tree[i]);
		}
		update();
	}
}

template <typename T>
vector<T> Tree<T>::getArray() {
	vector<int> result;
	getArrayRecurcive(root, result);
	return result;
}

template <typename T>
void Tree<T>::getArrayRecurcive(Node<T>* cur, vector<T>& arr) {
	if (cur == nullptr) return;
	getArrayRecurcive(cur->left, arr);
	arr.push_back(cur->value);
	getArrayRecurcive(cur->right, arr);
}

template <typename T>
void Tree<T>::draw() {
	draw(root);
}

template <typename T>
void Tree<T>::draw(Node<T>* node) {
	if (node == nullptr) return;
	node->draw();

	draw(node->left);
	draw(node->right);
}

template <typename T>
int Tree<T>::getHeight() {
	return getHeight(root);
}

template <typename T>
int Tree<T>::getHeight(Node<T>* node) {
	if (node == nullptr) return 0;
	return fmax(getHeight(node->left) + 1, getHeight(node->right) + 1);
}

template <typename T>
void Tree<T>::update() {
	// update root node
	int levels = getHeight();
	if (levels == 0) return; // to prevent dividing by zero if there is no any node
	levelHeight = WINDOW_HEIGHT / getHeight();
	nodeRadius = fmin(
		fmin(((WINDOW_WIDTH / pow(2, levels) * 1.0) / 2) * 0.8, ((WINDOW_HEIGHT / levels) / 2) * 0.8)
		, MAX_RADIUS);
	nodeRadius = fmax(nodeRadius, MIN_RADIUS);

	update(root, 1);
}

template <typename T>
void Tree<T>::update(Node<T>* node, int col) {
	if (node == nullptr) return;
	if (node->parent == nullptr) {
		node->level = 1;
	}
	else {
		node->level = node->parent->level + 1;
	}
	node->radius = nodeRadius;
	
	int absCol = col - pow(2, node->level - 1) + 1;
	double ww = ((WINDOW_WIDTH) / pow(2, node->level - 1));

	node->x = ww * (absCol - 1) + ww / 2;
	node->y = WINDOW_HEIGHT - (node->level * levelHeight - levelHeight / 2);

	update(node->left, col << 1);
	update(node->right, (col << 1) | 1);
}

template <typename T>
void Tree<T>::markHovered(int x, int y) {
	markHovered(root, x, y);
}

template <typename T>
void Tree<T>::markHovered(Node<T>* node, int x, int y) {
	if (node == nullptr) return;

	node->hovered = node->isHovered(x, y);
	markHovered(node->left, x, y);
	markHovered(node->right, x, y);
};

template <typename T>
int Tree<T>::getLeafCount() {
	return getLeafCount(root);
}

template <typename T>
int Tree<T>::getLeafCount(Node<T>* node) {
	if (node == nullptr) return 0;
	int count = 0;
	if (node->left == nullptr && node->right == nullptr) {
		count += 1;
	}
	count += getLeafCount(node->left);
	count += getLeafCount(node->right);
	return count;
}
#endif