/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <algorithm>
using namespace std;

template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T> void readData(T* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

// thuật toán tìm kiếm tuyến tính
template<class T> int linearSearch(T* arr, int size, T x) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x) { // nếu tìm thấy x trong mảng
			return i; // trả về vị trí đầu tiên xuất hiện x
		}
	}
	return -1; // không tìm thấy
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		float x;
		cin >> n >> x;
		float* arr = new float[n];
		readData(arr, n);
		sort(arr, arr + n);
		cout << "Test " << i << ":\n";
		if (linearSearch(arr, n, x) != -1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		delete[] arr;
	}
	return 0;
}