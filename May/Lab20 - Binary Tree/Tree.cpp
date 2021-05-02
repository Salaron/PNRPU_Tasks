#include "Tree.h"
#include "Node.h"
#include <math.h>
#include <algorithm>
#include <iostream>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

const int MIN_RADIUS = 20;
const int MAX_RADIUS = 80;

Tree::Tree(void) {

}

void Tree::insertNode(Node* node) {
	if (root == nullptr) {
		root = node;
	}
	else {
		Node* lastNode = getLast(root, 1, getHeight());
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

void Tree::insertBalanced(int value) {
	if (root == nullptr) {
		root = new Node(value);
	}
	else {
		int h = getHeight();
		Node* cur = getLast(root, 1, h);
		if (cur == nullptr) {
			cur = root;
			while (cur->left != nullptr) {
				cur = cur->left;
			}
		}
		
		if (cur->left == nullptr) {
			cur->left = new Node(cur, value);
		}
		else if (cur->right == nullptr) {
			cur->right = new Node(cur, value);
		}
	}
	update();
}

Node* Tree::getLast(Node* node, int level, int lastLevel) {
	if (level == lastLevel)
		return nullptr;
	if (level < lastLevel && node->left == nullptr || node->right == nullptr)
		return node;
	Node* tmp = getLast(node->left, level + 1, lastLevel);
	if (tmp != nullptr) return tmp;
	return getLast(node->right, level + 1, lastLevel);
}

void Tree::insert(int value) {
	Node* r = root;
	Node* current = root;
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
		root = new Node(value);
	}
	else {
		current = new Node(r, value);
		if (value < r->value) {
			r->left = current;
		}
		else {
			r->right = current;
		}
	}

	update();
}

bool Tree::remove(int value) {
	Node* node = find(value);
	if (node == nullptr) {
		return false;
	}

	Node* parent = node->parent;
	Node* left = node->left;
	Node* right = node->right;
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
		Node*& test = parent->left == node ? parent->left : parent->right;
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

void Tree::reset() {
	delete root;
	root = nullptr;
}

Node* Tree::find(int value) {
	return findRecurcive(root, value);
}

Node* Tree::findRecurcive(Node* node, int value) {
	if (node == nullptr) return nullptr;
	if (node->value == value) return node;
	Node* tmp = findRecurcive(node->left, value);
	if (tmp != nullptr) return tmp;
	return findRecurcive(node->right, value);
}

void Tree::convertToBalanced() {
	vector<int> tree = getArray();
	sort(tree.begin(), tree.end());
	delete root;
	root = nullptr;
	isSearch = false;
	for (int i = 0; i < tree.size(); i++) {
		insertBalanced(tree[i]);
	}
}

void Tree::convertToSearch() {
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
		root = new Node(tree[middle]);
		for (int i = 0; i < middle; i++) {
			insert(tree[i]);
		}
		for (int i = middle + 1; i < tree.size(); i++) {
			insert(tree[i]);
		}
		update();
	}
}

vector<int> Tree::getArray() {
	vector<int> result;
	getArrayRecurcive(root, result);
	return result;
}

void Tree::getArrayRecurcive(Node* cur, vector<int>& arr) {
	if (cur == nullptr) return;
	getArrayRecurcive(cur->left, arr);
	arr.push_back(cur->value);
	getArrayRecurcive(cur->right, arr);
}

void Tree::draw() {
	drawRecurcive(root);
}

void Tree::drawRecurcive(Node* node) {
	if (node == nullptr) return;
	node->draw();

	drawRecurcive(node->left);
	drawRecurcive(node->right);
}

int Tree::getHeight() {
	return getHeightRecurcive(root);
}

int Tree::getHeightRecurcive(Node* node) {
	if (node == nullptr) return 0;
	return fmax(getHeightRecurcive(node->left) + 1, getHeightRecurcive(node->right) + 1);
}

void Tree::update() {
	// update root node
	int levels = getHeight();
	if (levels == 0) return; // to prevent dividing by zero if there is no any node
	levelHeight = WINDOW_HEIGHT / getHeight();
	nodeRadius = fmin(
		fmin(((WINDOW_WIDTH / pow(2, levels) * 1.0) / 2) * 0.8, ((WINDOW_HEIGHT / levels) / 2) * 0.8)
		, MAX_RADIUS);
	nodeRadius = fmax(nodeRadius, MIN_RADIUS);

	updateRecurcive(root, 1);
}

void Tree::updateRecurcive(Node* node, int col) {
	if (node == nullptr) return;
	if (node->parent == nullptr) {
		node->level = 1;
	}
	else {
		node->level = node->parent->level + 1;
	}
	node->radius = nodeRadius;
	
	int absCol = col - pow(2, node->level - 1) + 1;
	double ww = ((WINDOW_WIDTH - 50) / pow(2, node->level - 1));

	node->x = ww * (absCol - 1) + ww / 2;
	node->y = WINDOW_HEIGHT - (node->level * levelHeight - levelHeight / 2);

	updateRecurcive(node->left, col << 1);
	updateRecurcive(node->right, (col << 1) | 1);
}

void Tree::markHovered(int x, int y) {
	markHoveredRecurcive(root, x, y);
}

void Tree::markHoveredRecurcive(Node* node, int x, int y) {
	if (node == nullptr) return;

	node->hovered = node->isHovered(x, y);
	markHoveredRecurcive(node->left, x, y);
	markHoveredRecurcive(node->right, x, y);
};

int Tree::getLeafCount() {
	return getLeafCountRecurcive(root);
}

int Tree::getLeafCountRecurcive(Node* node) {
	if (node == nullptr) return 0;
	int count = 0;
	if (node->left == nullptr && node->right == nullptr) {
		count += 1;
	}
	count += getLeafCountRecurcive(node->left);
	count += getLeafCountRecurcive(node->right);
	return count;
}