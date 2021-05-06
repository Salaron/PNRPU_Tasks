#include "Tree.h"

KTree::KTree(void) {

}

KNode*& KTree::insert(KNode* node, vector<vector<int>> matrix, int value) {
	if (root == nullptr) {
		root = new KNode(matrix, value);
		return root;
	}
	else {
		if (value > node->value && node->right == nullptr) {
			node->right = new KNode(node, matrix, value);
			node->right->parent = node;
			return node->right;
		}
		else {
			node->left = new KNode(node, matrix, value);
			node->left->parent = node;
			return node->left;
		}
	}
	update();
}

KNode* KTree::getMin() {
	return getMin(root);
}

KNode* KTree::getMin(KNode* node) {
	if (node == nullptr) return nullptr;

	if (node->left != nullptr && node->right != nullptr) {
		KNode* r1 = getMin(node->left);
		KNode* r2 = getMin(node->right);
		if (r1 != nullptr && r2 != nullptr) {
			if (r1->value > r2->value) {
				return r2;
			}
			else {
				return r1;
			}
		}
		return r1 == nullptr ? r2 : r1;
	}
	else {
		KNode* child = node->left == nullptr ? node->right : node->left;
		if (child != nullptr && node->value > child->value) {
			return child;
		}
		else {
			return node;
		}
	}
}

void KTree::draw() {
	update();
	draw(root);
}

int KTree::getHeight() {
	return getHeight(root);
}

int KTree::getHeight(KNode* node) {
	if (node == nullptr) return 0;
	return fmax(getHeight(node->left) + 1, getHeight(node->right) + 1);
}

void KTree::update() {
	int levels = getHeight();
	if (levels == 0) return; // to prevent dividing by zero if there is no any node
	levelHeight = WINDOW_HEIGHT / getHeight();
	nodeRadius = fmin(
		fmin(((WINDOW_WIDTH / pow(2, levels) * 1.0) / 2) * 0.8, ((WINDOW_HEIGHT / levels) / 2) * 0.8)
		, MAX_RADIUS);
	nodeRadius = fmax(nodeRadius, MIN_RADIUS);

	update(root, 1);
}

void KTree::update(KNode* node, int col) {
	if (node == nullptr) return;
	if (node->parent == nullptr) {
		node->level = 1;
		int absCol = col - pow(2, node->level - 1) + 1;
		double ww = ((WINDOW_WIDTH) / pow(2, node->level - 1));

		node->x = ww * (absCol - 1) + ww / 2;
		node->y = WINDOW_HEIGHT - (node->level * levelHeight - levelHeight / 2);
	}
	else {
		node->level = node->parent->level + 1;
		node->y = node->parent->y - 70;
		node->x = col % 2 == 0 ? node->parent->x - 40 : node->parent->x + 40;
	}

	update(node->left, col << 1);
	update(node->right, (col << 1) | 1);
}

void KTree::draw(KNode* node) {
	if (node == nullptr) return;
	node->draw();
	draw(node->left);
	draw(node->right);
}

bool KTree::isInSolution(int i, int j) {
	for (auto const edge : solution) {
		if (edge.from == i && edge.to == j) return true;
	}
	return false;
}