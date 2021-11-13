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
template<class T> int count(T* arr, int size, T x) {
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x) { // nếu tìm thấy x trong mảng
			counter++;
		}
	}
	return counter; // không tìm thấy
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		int x;
		cin >> n >> x;
		int* arr = new int[n];
		readData(arr, n);
		sort(arr, arr + n);
		cout << "Test " << i << ":\n";
		cout << count(arr, n, x) << endl;
		delete[] arr;
	}
	return 0;
}