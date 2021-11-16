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
};

void addVertex(Vertex* vertices, string label, int index) {
	Vertex v(label);
	vertices[index] = v;
}

void addEdge(bool adjMatrix[][MAX], int start, int end, bool value) {
	adjMatrix[start][end] = value;
	adjMatrix[end][start] = value;
}

bool dfs(Vertex* vertices, bool adjMatrix[][MAX], int size, int index) {
	int count = 0;
	stack<int> stack;
	stack.push(index);
	while (!stack.empty()) {
		index = stack.top();
		stack.pop();
		if (!vertices[index].visited) {
			vertices[index].visited = true;
			count++;
			for (int i = 0; i < size; i++)
			{
				if (adjMatrix[index][i]) {
					stack.push(i);
				}
			}
		}
	}
	return count == size;
}

void reset(Vertex* vertices, int n) {
	for (int i = 0; i < n; i++)
	{
		vertices[i].visited = false;
	}
}

int main() {
	ifstream ifs("input1.txt");
	if (ifs) {
		int t;
		ifs >> t;
		for (int test = 1; test <= t; test++) {
			int n;
			ifs >> n;
			// tạo nhãn cho các đỉnh
			Vertex vertices[MAX];
			for (int i = 0; i < n; i++)
			{
				string label = to_string(i + 1);
				addVertex(vertices, label, i);
			}
			// đọc ma trận kề
			bool adjMatrix[MAX][MAX];
			int value;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
				{
					ifs >> value;
					addEdge(adjMatrix, i, j, value);
				}
			}
			cout << "Test " << test << ": \n";
			// kiểm tra tính liên thông
			if (dfs(vertices, adjMatrix, n, 0)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file.\n";
	}

	return 0;
}
