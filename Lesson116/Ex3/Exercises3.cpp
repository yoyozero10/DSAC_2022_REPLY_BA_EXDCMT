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

// thuật toán floydWarshall
void floydWarshall(vector<Edge> edges, int** dist, int** next, int size) {
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (i != j) {
				dist[i][j] = SHRT_MAX;
				next[i][j] = -1;
			}
			else {
				dist[i][j] = 0;
				next[i][j] = i;
			}
		}
	}
	for (Edge e : edges)
	{
		dist[e.start][e.end] = e.weight;
		next[e.start][e.end] = e.end;
	}
	for (int k = 1; k <= size; k++)
	{
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				int alt = dist[i][k] + dist[k][j];
				if (alt < dist[i][j]) {
					dist[i][j] = alt;
					next[i][j] = next[i][k];
				}
			}
		}
	}
}

void minPath(int** next, vector<int>& path, int u, int v) {
	if (next[u][v] == -1) {
		return;
	}
	path.push_back(u);
	while (u != v) {
		u = next[u][v];
		path.push_back(u);
	}
}

void showPath(vector<int> path, int target) {
	for (size_t i = 0; i < path.size(); i++) {
		cout << path[i] << (i < path.size() - 1 ? " -> " : "");
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
			vector<int> path;
			int** next = new int* [n + 1];
			int** dist = new int* [n + 1];
			for (int i = 0; i <= n; i++) {
				dist[i] = new int[n + 1]();
				next[i] = new int[n + 1]();
			}
			floydWarshall(edges, dist, next, n);
			minPath(next, path, source, target);
			cout << dist[source][target] << endl;
			showPath(path, target);

			// thu hồi bộ nhớ
			for (int i = 0; i <= n; i++)
			{
				delete[] next[i];
				delete[] dist[i];
			}
			delete[] dist;
			delete[] next;
		}
		ifs.close(); // close the file after read data from it
	}

	return 0;
}