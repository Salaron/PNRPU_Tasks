#include "Kommi.h"
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "Tree.h"
#include "Node.h"

using namespace std;

Kommi::Kommi() {
	m_count = 0;
	m_matrix = {};
	m_names = {};
}

Kommi::~Kommi() {

}

void Kommi::init() {
	m_names = {};
	m_matrix = {};
	cout << "Count: "; cin >> m_count;

	for (int i = 0; i < m_count; i++) {
		string tmp;
		cin >> tmp;
		m_names.push_back(tmp);
	}

	for (int i = 0; i < m_count; i++)
	{
		vector<int> t;
		for (int j = 0; j < m_count; j++)
		{
			if (i == j)
				t.push_back(-1);
			else
			{
				int in;
				cout << m_names[i] << " => " << m_names[j] << ": "; cin >> in;
				t.push_back(in);
			}
		}
		m_matrix.push_back(t);
	}
}

void Kommi::PrintMatrix() {
	PrintMatrix(m_matrix);
}

void Kommi::PrintMatrix(vector<vector<int>>& matrix) {
	cout << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(2) << m_names[i] << ' ';
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == -1)
				cout << " * ";
			else
				cout << setw(2) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int Kommi::Reduct(vector<vector<int>>& matrix, bool isRow = false) {
	int total = 0;
	for (int i = 0; i < matrix.size(); i++) {
		int min = INT_MAX;

		for (int j = 0; j < matrix[i].size(); j++) {
			int k = i;
			int l = j;
			if (!isRow) swap(k, l);
			if (matrix[k][l] < min && matrix[k][l] >= 0) 
				min = matrix[k][l];
		}


		if (min != INT_MAX) {
			for (int j = 0; j < matrix[i].size(); j++) {
				int k = i;
				int l = j;
				if (!isRow) swap(k, l);
				if (matrix[k][l] >= 0)
					matrix[k][l] -= min;
			}
			total += min;
		}
	}
	return total;
}

int Kommi::findMin(vector<vector<int>>& matrix, int x, int y, bool isRow = false) {
	int min = INT_MAX;

	for (int i = 0; i < m_count; i++) {
		if (isRow && i != y) {
			if (matrix[x][i] < min && matrix[x][i] >= 0)
				min = matrix[x][i];
		}
		else if (!isRow && i != x) {
			if (matrix[i][y] < min && matrix[i][y] >= 0)
				min = matrix[i][y];
		}
	}
	if (min == INT_MAX) return 0;

	return min;
}

Edge Kommi::FindEdge(vector<vector<int>>& matrix) {
	int max = -1;
	Edge edge{ 0, 0 };

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				int t = findMin(matrix, i, j) + findMin(matrix, i, j, true);
				if (t > max) {
					max = t;
					edge.from = i;
					edge.to = j;
				}
			}
		}
	}
	return edge;
}

int Kommi::Exclude(vector<vector<int>>& matrix, Edge edge) {
	// исключение ребра производится исключением данного элемента
	matrix[edge.from][edge.to] = -1;
	int q1 = Reduct(matrix, true);
	int q2 = Reduct(matrix);

	return q1 + q2 + findMin(matrix, edge.from, edge.to) + findMin(matrix, edge.from, edge.to, true);
}

int Kommi::Include(vector<vector<int>>& matrix, Edge edge) {
	// для оценки маршрута, включающего данное ребро
	// строку и столбец исключаем
	// а также исключаем симметричный ему элемент
	matrix[edge.to][edge.from] = -1;
	for (int i = 0; i < m_count; i++) {
		matrix[edge.from][i] = -1;
		matrix[i][edge.to] = -1;
	}
	// приводим матрицу и вычисляем сумму констант приведения
	int q1 = Reduct(matrix, true);
	int q2 = Reduct(matrix);

	return q1 + q2 + findMin(matrix, edge.from, edge.to) + findMin(matrix, edge.from, edge.to, true);
}

bool Kommi::CheckMatrix(vector<vector<int>> matrix) {
	int count = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] >= 0) count++;
		}
	}
	return count == 0;
}

KTree* Kommi::Solve(bool stupidSolution = false) {
	vector<vector<int>> tmpMatrix = m_matrix;
	vector<Edge> result;
	KTree* tree = new KTree; // дерево решений

	// прелюдия
	int q1 = Reduct(tmpMatrix, true);
	int q2 = Reduct(tmpMatrix);
	KNode* parent = tree->insert(nullptr, tmpMatrix, q1 + q2);
	int wayLen = 0;
	while (!CheckMatrix(tmpMatrix)) {
		tmpMatrix = parent->m_matrix;
		wayLen = parent->value;
		int q1 = Reduct(tmpMatrix, true);
		int q2 = Reduct(tmpMatrix);
		wayLen += q1 + q2;

		Edge edge = FindEdge(tmpMatrix);

		// разбиение на два подмножества: включающее найденное ребро и не включающее его
		vector<vector<int>> tmp1 = tmpMatrix;
		int way1 = Include(tmp1, edge) + wayLen;
		vector<vector<int>> tmp2 = tmpMatrix;
		int way2 = Exclude(tmp2, edge) + wayLen;

		KNode* node1 = tree->insert(parent, tmp1, way1);
		node1->edge = edge;
		KNode* node2 = tree->insert(parent, tmp2, way2);
		node2->excluded = true;
		node2->edge = edge;

		KNode* minimalWay = tree->getMin();
		if (minimalWay->value < way1 && minimalWay->value < way2 && !stupidSolution) {
			parent = minimalWay;
			result = {};
			KNode* t = parent;
			while (t != nullptr) {
				if (t->excluded != true && t != tree->root) {
					result.push_back(t->edge);
				}
				t = t->parent;
			}
			reverse(result.begin(), result.end());
		}
		else if (edge.from != edge.to) {
			if (way1 <= way2) {
				parent = node1;
				result.push_back(edge);
			}
			else {
				parent = node2;
			}
		}
	}
	printVector<Edge>(result);
	tree->solution = result;
	tree->wayLen = wayLen;
	return tree;
}

string Kommi::getSolutionPath(KTree* tree) {
	string result = "";

	Edge current = tree->solution[0];
	result += m_names[current.from] + "->" + m_names[current.to];
	int count = 0;
	while (count < m_count) {
		for (int i = 0; i < tree->solution.size(); i++) {
			Edge next = tree->solution[i];
			if (current.to == next.from) {
				count++;
				result += "->" + m_names[next.to];
				current = next;
				break;
			}
		}
	}

	return result.substr(0, result.length() - 3); // cut out part of begging
}
