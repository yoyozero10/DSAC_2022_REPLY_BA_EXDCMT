#include <iostream>
using namespace std;
// khai báo nguyên mẫu hàm
void getInput(int** matrix, int m, int n);
void showMatrix(int** matrix, int m, int n);
void add(int** first, int** last, int** sum, int m, int n);

int main() {
	int m, n, l, k;
	cin >> m >> n >> l >> k;
	if (m > 0 && n > 0 && m == l && n == k) {
		// cấp phát động
		int** matrix1 = new int* [m];
		int** matrix2 = new int* [m];
		int** sum = new int* [m];
		for (int i = 0; i < m; i++)
		{
			matrix1[i] = new int[n];
			matrix2[i] = new int[n];
			sum[i] = new int[n];
		}
		// gọi thao tác nhập và hiển thị ma trận
		getInput(matrix1, m, n);
		getInput(matrix2, m, n);
		add(matrix1, matrix2, sum, m, n);
		showMatrix(sum, m, n);
		// thu hồi bộ nhớ
		for (int i = 0; i < m; i++)
		{
			delete[] matrix1[i];
			delete[] matrix2[i];
			delete[] sum[i];
		}
		delete[] matrix1;
		delete[] matrix2;
		delete[] sum;
	}
	else {
		cout << "INVALID ACTION\n";
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
// hàm tính tổng hai ma trận
void add(int** first, int** last, int** sum, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum[i][j] = first[i][j] + last[i][j];
		}
	}
}