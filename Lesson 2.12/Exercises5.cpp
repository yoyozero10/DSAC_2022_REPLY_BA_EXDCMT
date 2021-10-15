/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <array>
using namespace std;
const int N = 100;

void remove(array<int, N>& arr, int& n, int x) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) {
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
			i--; // xét xem phần tử mới tại vị trí i có bị xóa không
		}
	}
}

void showElements(array<int, N> arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	array<int, N> arr{};
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		remove(arr, n, x);
		showElements(arr, n);
	}
	return 0;
}