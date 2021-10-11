#include <iostream>
using namespace std;
// khai báo nguyên mẫu hàm
void getInput(float** matrix, int m, int n);
void showMatrix(float** matrix, int m, int n);
void convert(float** matrix, float** result, int m, int n);

int main() {
	int m, n;
	cin >> m >> n;
	if (m > 0 && n > 0) {
		// cấp phát động
		float** matrix = new float* [m];
		float** traMatrix = new float* [n];
		for (int i = 0; i < m; i++)
		{
			matrix[i] = new float[n];
		}
		for (int j = 0; j < n; j++)
		{
			traMatrix[j] = new float[m];
		}
		// gọi thao tác nhập và hiển thị ma trận
		getInput(matrix, m, n);
		convert(matrix, traMatrix, m, n);
		showMatrix(matrix, m, n);
		showMatrix(traMatrix, n, m);
		// thu hồi bộ nhớ
		for (int i = 0; i < m; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		delete[] traMatrix;
	}
	else {
		cout << "ERROR\n";
	}
	return 0;
}
// hàm nhập ma trận
void getInput(float** matrix, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
// hàm hiển thị ma trận
void showMatrix(float** matrix, int m, int n) {
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
// hàm chuyển đổi ma trận thường->chuyển vị
void convert(float** matrix, float** result, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[j][i] = matrix[i][j];
		}
	}
}