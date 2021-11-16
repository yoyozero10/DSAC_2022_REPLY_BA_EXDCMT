/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <queue>
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
	adjMatrix[end][start] = value;
}

// thuật toán bfs
bool bfs(Vertex* vertices, bool adjMatrix[][MAX], int size, int index) {
	int count = 0; // đếm số đỉnh đã duyệt
	queue<int> mQueue;
	vertices[index].visited = true;
	mQueue.push(index);
	while (!mQueue.empty())
	{
		index = mQueue.front();
		mQueue.pop();
		count++;
		for (int i = 0; i < size; i++)
		{
			if (adjMatrix[index][i] && !vertices[i].visited) {
				vertices[i].visited = true;
				mQueue.push(i);
			}
		}
	}
	return count == size; // nếu duyệt hết size đỉnh thì đồ thị liên thông
}

int main() {
	ifstream ifs("input1.txt");
	if (ifs) {
		int t; // số bộ test của bài ra
		ifs >> t;
		for (int test = 1; test <= t; test++) {
			int n;
			ifs >> n; // đọc số đỉnh
			// tạo nhãn cho các đỉnh
			Vertex vertices[MAX];
			for (int i = 0; i < n; i++)
			{
				string label = to_string(i + 1);
				addVertex(vertices, label, i);
			}
			// đọc ma trận kề
			bool adjMatrix[MAX][MAX] = { false };
			int value;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ifs >> value;
					addEdge(adjMatrix, i, j, value);
				}
			}
			// Hiển thị kết quả ra màn hình
			cout << "Test " << test << ": \n";
			if (bfs(vertices, adjMatrix, n, 0)) {
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
