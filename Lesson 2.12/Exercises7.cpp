#include <iostream>
#include <array>
using namespace std;
const int N = 100;

void findResult(array<int, N>& arr, int n, int k) {
	for (int i = 0; i <= n - k; i++)
	{
		int max = arr[i];
		for (int j = i; j < i + k; j++)
		{
			if (max < arr[j]) {
				max = arr[j];
			}
		}
		cout << max << ' ';
	}
	cout << endl;
}

int main() {
	array<int, N> arr{};
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		findResult(arr, n, k);
	}
	return 0;
}