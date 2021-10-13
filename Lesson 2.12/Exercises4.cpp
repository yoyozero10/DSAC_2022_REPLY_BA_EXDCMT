#include <iostream>
#include <array>
using namespace std;
const int N = 100;

void insert(array<int, N>& arr, int& n, int k, int x) {
	if (k >= n) {
		arr[n++] = x;
	}
	else {
		if (k < 0) {
			k = 0;
		}
		for (int i = n; i > k; i--) {
			arr[i] = arr[i - 1];
		}
		arr[k] = x;
		n++;
	}
}

void showResult(array<int, N>& arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k, x;
		cin >> n >> k >> x;
		array<int, N> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		insert(arr, n, k, x);
		showResult(arr, n);
	}
	return 0;
}