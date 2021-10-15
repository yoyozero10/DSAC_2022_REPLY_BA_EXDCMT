#include <iostream>
#include <array>
using namespace std;
const int N = 100;

int sum(array<int, N>& arr, int n) {
	int s = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] > arr[i]) {
			s += arr[i + 1];
		}
	}
	return s;
}

int main() {
	array<int, N> arr{};
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int result = sum(arr, n);
		cout << result << endl;
	}
	return 0;
}