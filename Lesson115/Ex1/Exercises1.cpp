#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
using namespace std;

class Edge {
public:
	int start;
	int end;
	int weight;

	Edge(int s = 0, int e = 0, int w = 0) {
		this->start = s;
		this->end = e;
		this->weight = w;
	}
};

void addEdge(vector<Edge>& edges, int start, int end, int weight) {
	edges.push_back(Edge(start, end, weight));
}

// thuật toán Bellman-Ford
int bellmanFord(vector<Edge> edges, int* prev, int* dist, int size, int source) {
	for (int i = 1; i <= size; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[source] = 0;
	int k = 1;
	while (k < size) {
		for (Edge e : edges)
		{
			int alt = dist[e.start] + e.weight;
			if (alt < dist[e.end]) {
				dist[e.end] = alt;
				prev[e.end] = e.start;
			}
		}
		k++;
	}
	// kiểm tra chu trình âm
	for (Edge e : edges)
	{
		int alt = dist[e.start] + e.weight;
		if (alt < dist[e.end]) {
			cout << "Do thi co chu trinh am.\n";
			return -1;
		}
	}
	return 0;
}

void showPath(int* path, int target) {
	stack<int> result;
	result.push(target);
	int prevVertex = path[target];
	while (true) {
		result.push(prevVertex);
		if (prevVertex == 1) {
			break;
		}
		prevVertex = path[prevVertex];
	}
	// hiển thị kết quả đường đi
	while (!result.empty()) {
		cout << result.top();
		result.pop();
		cout << (result.empty() ? "" : " -> ");
	}
}

int main() {
	ifstream ifs("weight.dat");
	if (ifs) {
		int n, target;
		ifs >> n >> target;
		vector<Edge> edges;
		int* path = new int[n + 1]();
		int* dist = new int[n + 1]();
		// đọc vào ma trận trọng số
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int value;
				ifs >> value;
				if (value != 0) {
					edges.push_back(Edge(i, j, value));
				}
			}
		}
		ifs.close(); // close the file after read data from it
		bellmanFord(edges, path, dist, n, 1);
		cout << dist[target] << endl;
		showPath(path, target);

		// thu hồi bộ nhớ
		delete[] dist;
		delete[] path;
	}

	return 0;
}