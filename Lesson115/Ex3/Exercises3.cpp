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
		dist[i] = SHRT_MAX; // gán bằng giá trị max của kiểu short để đảm bảo dòng 35 không tràn số->sai kq
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

void showPath(int* path, int source, int target) {
	stack<int> result;
	result.push(target);
	int prevVertex = path[target];
	while (true) {
		result.push(prevVertex);
		if (prevVertex == source) {
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
	cout << endl;
}

int main() {
	ifstream ifs("weight3.dat");
	if (ifs) {
		int n;
		ifs >> n;
		vector<Edge> edges;

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
		int test;
		ifs >> test;
		for (int i = 1; i <= test; i++)
		{
			int source, target;
			ifs >> source >> target;
			int* path = new int[n + 1]();
			int* dist = new int[n + 1]();
			bellmanFord(edges, path, dist, n, source);
			cout << dist[target] << endl;
			showPath(path, source, target);
			// thu hồi bộ nhớ
			delete[] dist;
			delete[] path;
		}
		ifs.close(); // close the file after read data from it
	}

	return 0;
}