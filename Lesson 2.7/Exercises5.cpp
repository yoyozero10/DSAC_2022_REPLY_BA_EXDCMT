/**
 * @file Exercises4.cpp
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @brief Update exercises 4 lesson 2.6
 * @version 2.0
 * @date 2022-10-31
 *
 * @copyright Copyright (c) Branium Academy 2022
 *
 */

//Follow the given steps to solve the problem :
//
//Create a recursive function that takes the graph, current index, 
// number of vertices, and output color array.
//If the current index is equal to the number of vertices.
// Print the color configuration in the output array.
//Assign a color to a vertex(1 to m).
//For every assigned color, check if the configuration is safe, 
// (i.e.check if the adjacent vertices do not have the same color) 
// recursively call the function with the next indexand number of vertices
//If any recursive function returns true break the loopand return true
//If no recursive function returns true then return false

#include <iostream>
using namespace std;

// số đỉnh
#define SIZE 4

/* A utility function to check if
   the current color assignment
   is safe for vertex v i.e. checks
   whether the edge exists or not
   (i.e, graph[v][i]==1). If exist
   then checks whether the color to
   be filled in the new vertex(c is
   sent in the parameter) is already
   used by its adjacent
   vertices(i-->adj vertices) or
   not (i.e, color[i]==c)
 */
bool isSafe(int vertex, bool graph[SIZE][SIZE], int* colors, int color) {
	for (int i = 0; i < SIZE; i++) {
		if (graph[vertex][i] && colors[i] == color) {
			return false;
		}
	}
	return true;
}

// hàm đệ quy thực hiện tô màu đồ thị
bool graphColoringUtil(bool graph[SIZE][SIZE], int m, int* colors, int vertex) {
	// nếu tất cả các đỉnh đã đc gán màu => return true
	if (vertex == SIZE) {
		return true;
	}
	// thử tô màu khác cho đỉnh vertex
	for (int c = 1; c <= m; c++) {

		// kiểm tra việc tô màu c cho đỉnh vertex có ok không
		if (isSafe(vertex, graph, colors, c)) {
			colors[vertex] = c;
			// lặp lại việc gán màu cho các đỉnh còn lại của đồ thị
			if (graphColoringUtil(graph, m, colors, vertex + 1) == true) {
				return true;
			}
			// nếu việc gán màu c cho đỉnh vertex không dẫn tới lời giải => xóa bỏ việc gán màu
			colors[vertex] = 0;
		}
	}
	// nếu không màu nào có thể gán cho đỉnh này, return false
	return false;
}

/* This function solves the m Coloring
   problem using Backtracking. It mainly
   uses graphColoringUtil() to solve the
   problem. It returns false if the m
   colors cannot be assigned, otherwise
   return true and prints assignments of
   colors to all vertices. Please note
   that there may be more than one solutions,
   this function prints one of the
   feasible solutions.
*/
bool graphColoring(bool graph[SIZE][SIZE], int m) {
	void printSolution(int* colors); // declare function template
	int* colors = new int[SIZE]();
	if (graphColoringUtil(graph, m, colors, 0) == false) {
		cout << "Khong co loi giai.\n";
		return false;
	}
	printSolution(colors);
	return true;
}

// hàm hiển thị 1 kết quả tìm được
void printSolution(int* colors) {
	cout << "Sau day la 1 loi giai: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << " " << colors[i];
	}
	cout << endl;
}

int main() {
	bool graph[SIZE][SIZE] = {
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0}
	};
	int m = 3; // số lượng các màu cần thử tô
	// khởi tạo tất cả các giá trị màu là 0
	int* colors = new int[SIZE]();
	// gọi hàm
	if (!graphColoring(graph, m)) {
		cout << "Khong ton tai loi giai.\n";
	}
	return 0;
}