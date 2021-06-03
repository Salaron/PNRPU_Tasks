#include "Dijkstra.h"
#include <iostream>
#include <queue>

using namespace std;

Dijkstra::Dijkstra() {

}

Dijkstra::~Dijkstra() {

}

void Dijkstra::Init(vector<vector<int>> matrix, vector<string> names) {
	m_names = names;
	m_matrix = matrix;
}

bool check(bool* arr, int count) {
	for (int i = 0; i < count; i++) {
		if (arr[i] == false) return false;
	}
	return true;
}

void Dijkstra::Work(string name) {
    int top = 0;
    queue<int> line;
    line.push(top);
    int result[6] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX, INT_MAX };
    bool visited[6] = { 0, 0, 0, 0, 0, 0 };
    result[0] = 0;
    while (!line.empty()) {
        int vertex = line.front();
        line.pop();
        for (int i = 0; i < this->m_matrix[vertex].size(); i++) {
            if (!visited[i] && m_matrix[vertex][i] > 0 && (m_matrix[vertex][i] + result[vertex] < result[i])) {
                result[i] = m_matrix[vertex][i] + result[vertex];
                line.push(i);
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << m_names[i] << ": " << result[i] << endl;
    }
}

