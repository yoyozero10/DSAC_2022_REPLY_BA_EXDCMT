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
	int label;
	bool visited;
	int blocked;

	Vertex(int label = 0, bool visited = false) {
		this->label = label;
		this->visited = visited;
		blocked = false;
	}

	bool operator == (const Vertex& v) const {
		return label == v.label;
	}
};

void addVertex(Vertex* vertices, int label) {
	vertices[label] = Vertex(label);
}

// thuật toán bfs
int bfs(Vertex* vertices, vector<int> adj[], int size, int index) {
	int count = 0; // đếm số đỉnh đã duyệt
	queue<int> mQueue;
	vertices[index].visited = true;
	mQueue.push(index);
	while (!mQueue.empty())
	{
		index = mQueue.front();
		mQueue.pop();
		for (int i = 0; i < adj[index].size(); i++)
		{
			if (vertices[adj[index].at(i)].blocked == 0 && !vertices[adj[index].at(i)].visited) {
				count++;
				vertices[adj[index].at(i)].visited = true;
				mQueue.push(adj[index].at(i));
			}
			else if (!vertices[adj[index].at(i)].visited && vertices[adj[index].at(i)].blocked == 1) {
				count++;
			}
		}
	}
	return count + 1; 
}

int findMax(Vertex* vertices, vector<int> adj[], int n) {
	int max = 1;
	for (int i = 1; i < n; i++) {
		if (vertices[i].blocked == 0 && !vertices[i].visited) {
			int result = bfs(vertices, adj, n, i);
			if (result > max) {
				max = result;
			}
		}
	}
	return max;
}

int main() {
	ifstream ifs("input2.txt");
	if (ifs) {
		int n;
		ifs >> n; // đọc số đỉnh
		// tạo nhãn cho các đỉnh
		Vertex vertices[MAX];
		for (int i = 1; i <= n; i++)
		{
			addVertex(vertices, i);
		}
		// vector chứa danh sách kề của từng đỉnh
		vector<int> adj[MAX];
		// thêm các đỉnh kề vào danh sách
		int start, end;
		for (int i = 1; i < n; i++) {
			ifs >> start >> end;
			adj[start].push_back(end);
			adj[end].push_back(start);
		}
		// đọc trạng thái ống nước của thành phố thứ i
		for (int i = 1; i <= n; i++) {
			int state;
			ifs >> state;
			vertices[i].blocked = state;
		}
		// Hiển thị kết quả ra màn hình
		cout << findMax(vertices, adj, n) << endl;
	}
	else {
		cout << "Khong mo duoc file.\n";
	}

	return 0;
}
