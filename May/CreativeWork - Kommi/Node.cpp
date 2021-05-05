#include "Node.h"

using namespace std;

KNode::KNode(vector<vector<int>> matrix, int min): Node(min) {
	m_matrix = matrix;
	value = min;
}

KNode::KNode(KNode* parent, vector<vector<int>> matrix, int min): KNode(matrix, min) {
	this->parent = parent;
}

KNode::~KNode() {

}