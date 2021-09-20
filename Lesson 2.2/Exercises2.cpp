#include <iostream>
using namespace std;

bool isSymmetry(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] != arr[n - i - 1]) {
			return false; // k phai so nguyen to
		}
	}
	return true; // n la so nguyen to
}

void readData(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void showResult(int* arr, int n) {
	if (isSymmetry(arr, n)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

int main()
{
	int t; // so bo test
	int n; // so phan tu mang
	cin >> t;
	while (t--) {
		cin >> n;
		int* numbers = new int[n];
		readData(numbers, n);
		showResult(numbers, n);
		delete[] numbers;
	}

	return 0;
}