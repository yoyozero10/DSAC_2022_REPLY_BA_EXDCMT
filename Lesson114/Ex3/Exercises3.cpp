#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

void addEdge(int** weightMatrix, int start, int end, int weight) {
	weightMatrix[start][end] = weight;
}

int findMinWeightVertex(int* dist, bool* unvisited, int size) {
	int index = 1;
	for (int i = 1; i <= size; i++)
	{
		if (unvisited[i]) {
			index = i;
			break;
		}
	}
	int minWeight = dist[index];
	for (int i = index; i <= size; i++)
	{
		if (unvisited[i] && dist[i] < minWeight) {
			index = i;
			minWeight = dist[i];
		}
	}
	return index;
}

bool empty(bool* unvisited, size_t size) {
	for (size_t i = 1; i <= size; i++)
	{
		if (unvisited[i]) {
			return false;
		}
	}
	return true;
}

int dijkstra(int** weightMatrix, int* prev, int size, int source, int target) {
	bool* unvisited = new bool[size + 1]();
	int* dist = new int[size + 1]();
	for (int i = 1; i <= size; i++)
	{
		dist[i] = INT_MAX;
		unvisited[i] = true;
	}
	dist[source] = 0;
	while (!empty(unvisited, size)) {
		int u = findMinWeightVertex(dist, unvisited, size);
		if (u == target) {
			return dist[u];
		}
		unvisited[u] = false;
		for (int v = 1; v <= size; v++)
		{
			int weight = weightMatrix[u][v];
			if (weight != 0 && (unvisited[v] == true)) {
				int alt = dist[u] + weight;
				if (alt < dist[v]) {
					dist[v] = alt;
					prev[v] = u;
				}
			}
		}
	}
	return -1;
}

void showPath(int* path, int start, int target) {
	stack<int> result;
	result.push(target);
	int prevVertex = path[target];
	while (true) {
		result.push(prevVertex);
		if (prevVertex == start) {
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
		int n, target;
		ifs >> n;
		// mảng lưu ma trận trọng số
		int** weightMatrix = new int* [n + 1];
		for (int i = 1; i <= n; i++)
		{
			weightMatrix[i] = new int[n + 1]();
		}
		// đọc vào ma trận trọng số
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ifs >> weightMatrix[i][j];
			}
		}
		int* path = new int[n + 1]();
		// số bộ test
		int test;
		ifs >> test; // đọc số bộ test
		for (int i = 1; i <= test; i++)
		{
			int start, end;
			ifs >> start >> end;
			int weight = dijkstra(weightMatrix, path, n, start, end);
			cout << weight << endl;
			showPath(path, start, end);
		}
		ifs.close(); // close the file after read data from it
		// thu hồi bộ nhớ
		for (int i = 1; i <= n; i++)
		{
			delete[] weightMatrix[i];
		}
		delete[] weightMatrix;
		delete[] path;
	}

	return 0;
}