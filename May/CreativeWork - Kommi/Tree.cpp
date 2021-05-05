#include "Tree.h"

tree::tree(void) {

}

KNode* tree::insert(KNode* node, vector<vector<int>> matrix, int value) {
	if (root == nullptr) {
		root = new KNode(matrix, value);
		return root;
	}
	else {
		if (value > node->value && node->right == nullptr) {
			node->right = new KNode(node, matrix, value);
			return node->right;
		}
		else {
			node->left = new KNode(node, matrix, value);
			return node->left;
		}
	}
}

KNode* tree::getMin() {
	return getMin(root);
}

KNode* tree::getMin(KNode* node) {
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
