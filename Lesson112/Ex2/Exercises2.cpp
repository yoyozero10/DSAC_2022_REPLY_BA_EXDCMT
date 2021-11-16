/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 100;

class Vertex {
public:
	string label;
	bool visited;

	Vertex(string label = "", bool visited = false) {
		this->label = label;
		this->visited = visited;
	}

	bool operator == (const Vertex& v) const {
		return label.compare(v.label) == 0;
	}
};

void addVertex(Vertex* vertices, string label, int index) {
	vertices[index] = Vertex(label);
}

void addEdge(bool adjMatrix[][MAX], int start, int end, bool value) {
	adjMatrix[start][end] = value;
}

void dfs(Vertex* vertices, bool adjMatrix[][MAX], int size, int index) {
	vertices[index].visited = true;
	for (int i = 0; i < size; i++)
	{
		if (adjMatrix[index][i] && !vertices[i].visited) {
			dfs(vertices, adjMatrix, size, i);
		}
	}
}

void fillOrder(Vertex* vertices, int n,
	bool adjMatrix[][MAX], int v, stack<Vertex>& stack) {
	vertices[v].visited = true;
	for (int i = 0; i < n; i++) {
		if (adjMatrix[v][i] && !vertices[i].visited) {
			fillOrder(vertices, n, adjMatrix, i, stack);
		}
	}
	stack.push(vertices[v]);
}

void transpose(bool adjMatrix[][MAX], int size, bool revAdjMatrix[][MAX]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (adjMatrix[i][j]) {
				revAdjMatrix[j][i] = true;
			}
		}
	}
}

int findSCComponents(Vertex* vertices, bool adjMatrix[][MAX], int n) {
	stack<Vertex> stack;
	for (int i = 0; i < n; i++)
	{
		if (!vertices[i].visited) {
			fillOrder(vertices, n, adjMatrix, i, stack);
		}
	}
	// tạo một ma trận kề biểu diễn hướng đi đảo ngược
	bool revAdjMatrix[MAX][MAX] = {false};
	transpose(adjMatrix, n, revAdjMatrix);
	// đánh dấu lại các đỉnh là chưa được thăm
	for (int i = 0; i < n; i++) {
		vertices[i].visited = false;
	}
	
	int counter = 0;
	while (!stack.empty()) {
		Vertex v = stack.top();
		stack.pop();
		if (!vertices[stoi(v.label) - 1].visited) {
			dfs(vertices, revAdjMatrix, n, stoi(v.label) - 1);
			counter++;
		}
	}
	return counter;
}

int main() {
	ifstream ifs("input2.txt");
	if (ifs) {
		int t;
		ifs >> t;
		for (int test = 1; test <= t; test++) {
			int n, edge;
			ifs >> n >> edge; // đọc số đỉnh và số cạnh
			// tạo nhãn cho các đỉnh
			Vertex vertices[MAX];
			for (int i = 0; i < n; i++)
			{
				string label = to_string(i + 1);
				addVertex(vertices, label, i);
			}
			// đọc tập cạnh
			bool adjMatrix[MAX][MAX] = {false};
			int start, end;
			for (int i = 0; i < edge; i++) {
				ifs >> start >> end;
				addEdge(adjMatrix, start - 1, end - 1, true);
			}
			// liệt kê số thành phần liên thông
			cout << "Test " << test << ": " << findSCComponents(vertices, adjMatrix, n) << endl;
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file.\n";
	}

	return 0;
}
