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
		cout << "Name: "; cin >> tmp;
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

void Kommi::addNode() {
	string tmp;
	cout << "Name: "; cin >> tmp;
	m_names.push_back(tmp);
	m_count++;
	vector<int> t;

	for (int i = 0; i < m_count - 1; i++)
	{
		int tmp;
		cin >> tmp;
		m_matrix[i].push_back(tmp);
	}

	for (int i = 0; i < m_count - 1; i++) {
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	t.push_back(-1);
	m_matrix.push_back(t);
	recompute = true;
}

void Kommi::removeNode() {
	if (m_matrix.size() == 0) return;
	string tmp;
	cout << "Name: "; cin >> tmp;
	vector<string>::iterator it = find(m_names.begin(), m_names.end(), tmp);
	if (it != m_names.end()) {
		int ind = distance(m_names.begin(), it);
		m_count--;

		// remove from names
		m_names.erase(it);

		// remove from matrix
		m_matrix.erase(m_matrix.begin() + ind);
		for (int i = 0; i < m_count; i++) {
			m_matrix[i].erase(m_matrix[i].begin() + ind);
		}
		recompute = true;
	}
	else {
		cout << "Node with name '" << tmp << "' doesn't exist";
	}
}

void Kommi::addLine() {
	string from, to;
	cout << "From: "; cin >> from;
	vector<string>::iterator itFrom = find(m_names.begin(), m_names.end(), from);
	if (itFrom == m_names.end()) {
		cout << "Node with name '" << from << "' doesn't exist";
		return;
	}
	
	cout << "To: "; cin >> to;
	vector<string>::iterator itTo = find(m_names.begin(), m_names.end(), to);
	if (itTo == m_names.end()) {
		cout << "Node with name '" << to << "' doesn't exist";
		return;
	}
	int ind = distance(m_names.begin(), itFrom);
	int ind2 = distance(m_names.begin(), itTo);

	int dist;
	cout << "Distance"; cin >> dist;
	m_matrix[ind][ind2] = dist;
	recompute = true;
}

void Kommi::removeLine() {
	string from, to;
	cout << "From: "; cin >> from;
	vector<string>::iterator itFrom = find(m_names.begin(), m_names.end(), from);
	if (itFrom == m_names.end()) {
		cout << "Node with name '" << from << "' doesn't exist";
		return;
	}

	cout << "To: "; cin >> to;
	vector<string>::iterator itTo = find(m_names.begin(), m_names.end(), to);
	if (itTo == m_names.end()) {
		cout << "Node with name '" << to << "' doesn't exist";
		return;
	}
	int ind = distance(m_names.begin(), itFrom);
	int ind2 = distance(m_names.begin(), itTo);

	m_matrix[ind][ind2] = -1;
	recompute = true;
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

int Kommi::Exclude(vector<vector<int>>& matrix, Edge edge, vector<Edge>& zeros) {
	// исключение ребра производится исключением данного элемента
	matrix[edge.from][edge.to] = -1;
	findLoop(matrix, zeros);
	int q1 = Reduct(matrix, true);
	int q2 = Reduct(matrix);

	if (CheckMatrix(matrix)) return -1;

	return q1 + q2 + findMin(matrix, edge.from, edge.to) + findMin(matrix, edge.from, edge.to, true);
}

int Kommi::Include(vector<vector<int>>& matrix, Edge edge, vector<Edge>& zeros) {
	// для оценки маршрута, включающего данное ребро
	// строку и столбец исключаем
	// а также исключаем симметричный ему элемент
	matrix[edge.to][edge.from] = -1;
	for (int i = 0; i < m_count; i++) {
		matrix[edge.from][i] = -1;
		matrix[i][edge.to] = -1;
	}
	findLoop(matrix, zeros);
	// приводим матрицу и вычисляем сумму констант приведения
	int q1 = Reduct(matrix, true);
	int q2 = Reduct(matrix);

	if (CheckMatrix(matrix)) return -1;

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

bool Kommi::findLoop(vector<vector<int>>& matrix, vector<Edge>& path) {
	vector<Edge> pathCopy = path;
	for (int i = 0; i < path.size(); i++) {
		int row = path[i].from;
		int col = path[i].to;
		matrix[col][row] = -1;

		for (int j = 0; j < pathCopy.size(); j++) {
			int rowCopy = pathCopy[j].from;
			int colCopy = pathCopy[j].to;

			if (row == colCopy) {
				for (vector<Edge>::iterator it = path.begin(); it != path.end(); ) {
					if ((*it).from == rowCopy) {
						(*it).to = col;
					}
					if ((*it).from == row) {
							it = path.erase(it);
					}
					else {
						it++;
					}
				}
				matrix[rowCopy][col] = -1;
				matrix[col][rowCopy] = -1;
				cout << "[" << rowCopy << "; " << col << "]" << endl;
				return findLoop(matrix, path);
			}
		}
	}
	return false;
}

KTree* Kommi::Solve(bool onlyInclude = false) {
	vector<vector<int>> tmpMatrix = m_matrix;
	vector<Edge> result;
	vector<Edge> zeros;
	KTree* tree = new KTree; // дерево решений
	int q1 = Reduct(tmpMatrix, true);
	int q2 = Reduct(tmpMatrix);
	KNode* parent = tree->insert(nullptr, tmpMatrix, q1 + q2);
	int wayLen = 0;
	while (parent->solution.size() != m_count) {
		wayLen = parent->value;
		int q1 = Reduct(parent->m_matrix, true);
		int q2 = Reduct(parent->m_matrix);
		wayLen += q1 + q2;

		Edge edge = FindEdge(parent->m_matrix);

		// разбиение на два подмножества: включающее найденное ребро и не включающее его
		vector<vector<int>> tmp1 = parent->m_matrix;
		int inclu = Include(tmp1, edge, zeros);
		int way1 = inclu + wayLen;
		vector<vector<int>> tmp2 = parent->m_matrix;
		int exclu = Exclude(tmp2, edge, zeros);
		int way2 = exclu + wayLen;
		zeros.push_back(edge);

		bool forceExclude = inclu == -1 && exclu != -1;
		KNode* node1 = tree->insert(parent, tmp1, way1);
		node1->solution = parent->solution;
		node1->solution.push_back(edge);
		node1->solvable = inclu != -1;
		node1->edge = edge;
		KNode* node2 = tree->insert(parent, tmp2, way2);
		node2->solution = parent->solution;
		node2->solvable = exclu != -1;
		node2->excluded = true;
		node2->edge = edge;

		KNode* minimalWay = tree->getMin();
		if (minimalWay == nullptr) {
			tree->haveSolution = false;
			break;
		}
		if (minimalWay->value < way1 && minimalWay->value < way2 && !onlyInclude) {
			zeros = {};
			parent = minimalWay;
			KNode* t = parent;
			while(t != nullptr && t != tree->root) {
				zeros.push_back(t->edge);
				t = t->parent;
			}
		}
		else if (inclu == -1 && exclu == -1 && node1->solution.size() != m_count) {
			zeros = {};
			parent = minimalWay;
			KNode* t = parent;
			while (t != nullptr && t != tree->root) {
				zeros.push_back(t->edge);
				t = t->parent;
			}
		}
		else if (edge.from != edge.to) {
			if (way1 <= way2 && !forceExclude) {
				parent = node1;
			}
			else {
				parent = node2;
			}
		}
	}

	printVector<Edge>(parent->solution);
	tree->solution = parent->solution;
	tree->wayLen = wayLen;
	checkSolution(tree);
	return tree;
}

bool Kommi::checkSolution(KTree* tree) {
	// check for looping
	if (tree->solution.size() == 0) {
		return (tree->haveSolution = false);
	}
	int i = 0;
	Edge beggining = tree->solution[0];
	Edge current = tree->solution[0];
	tree->haveSolution = true;
	while (i < m_count && tree->haveSolution == true) {
		bool have = false;
		for (int j = 0; j < tree->solution.size(); j++) {
			Edge next = tree->solution[j];
			if (current.to == next.from){
				i++;
				have = true;
				break;
			}
		}
		tree->haveSolution = have;
	}
	return tree->haveSolution;
}

string Kommi::getSolutionPath(KTree* tree) {
	if (!tree->haveSolution) return "";
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

	return result.substr(0, result.length() - 3); // cut out part of beginning
}

std::vector<std::vector<int>> Kommi::getMatrix() {
	return m_matrix;
}

std::vector<std::string> Kommi::getNames() {
	return m_names;
}

Kommi* Kommi::instance() {
	static Kommi instance;
	return &instance;
}