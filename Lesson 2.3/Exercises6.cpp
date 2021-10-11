/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

void showRect(string** rect, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << rect[i][j];
		}
		cout << endl;
	}
}

void drawRect(int m, int n) {
	string** rect = new string * [m];
	for (int i = 0; i < m; i++)
	{
		rect[i] = new string[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// chỉ vẽ dấu * ở viền ngoài
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				rect[i][j] = " * ";
			}
			else { // còn lại là dấu cách
				rect[i][j] = "   ";
			}
		}
	}
	showRect(rect, m, n);
	for (int i = 0; i < m; i++)
	{
		delete[] rect[i];
	}
	delete[] rect;
}

int main() {
	int m, n;
	cin >> m >> n;
	if (m > 0 && n > 0) {
		drawRect(m, n);
	}
	else {
		cout << "ERROR\n";
	}
}
