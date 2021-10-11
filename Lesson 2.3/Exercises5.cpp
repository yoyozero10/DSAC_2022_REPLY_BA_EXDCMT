#include <iostream>
using namespace std;

// tạo hình chữ nhật
void createRectangle(int** rect, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rect[i][j] = 1;
		}
	}
}
// vẽ hình chữ nhật đặc
void drawRect(int** rect, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rect[i][j] == 1) {
				cout << " * ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	if (m > 0 && n > 0) {
		// cấp phát bộ nhớ
		int** rect = new int* [m];
		for (int i = 0; i < m; i++)
		{
			rect[i] = new int[n];
		}
		// tạo hình chữ nhật
		createRectangle(rect, m, n);
		drawRect(rect, m, n);
		// thu hồi bộ nhớ
		for (int i = 0; i < m; i++)
		{
			delete[] rect[i];
		}
		delete[] rect;
	}
	else {
		cout << "ERROR\n";
	}
}