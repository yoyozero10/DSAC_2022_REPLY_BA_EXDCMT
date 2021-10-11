/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;
// khai báo nguyên mẫu hàm
void getInput(int** matrix, int m, int n);
void showMatrix(int** matrix, int m, int n);

int main() {
	int m, n;
	cin >> m >> n;
	if (m > 0 && n > 0) {
		// cấp phát động
		int** matrix = new int* [m];
		for (int i = 0; i < m; i++)
		{
			matrix[i] = new int[n];
		}
		// gọi thao tác nhập và hiển thị ma trận
		getInput(matrix, m, n);
		showMatrix(matrix, m, n);
		// thu hồi bộ nhớ
		for (int i = 0; i < m; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	else {
		cout << "ERROR\n";
	}
	return 0;
}
// hàm nhập ma trận
void getInput(int** matrix, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
// hàm hiển thị ma trận
void showMatrix(int** matrix, int m, int n) {
	cout << m << ' ' << n << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}