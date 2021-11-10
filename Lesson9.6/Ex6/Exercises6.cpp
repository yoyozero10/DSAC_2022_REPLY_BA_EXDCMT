/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// thuật toán trộn
template<class T> void merge(T* arr, int& n, T* arr1, int n1, T* arr2, int n2) {
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (arr1[i] <= arr2[j]) {
			arr[n++] = arr1[i++];
		}
		else {
			arr[n++] = arr2[j++];
		}
	}
	while (i < n1) {
		arr[n++] = arr1[i++];
	}
	while (j < n2)
	{
		arr[n++] = arr2[j++];
	}
}

// hàm hiển thị các phần tử mảng bất kì
template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T> void readData(T* arr, int& size) {
	cin >> size; // đọc số phần tử của mảng
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n1 = 0;
		int n2 = 0;
		int n = 0;
		double arr1[500];
		double arr2[500];
		double arr[500];
		readData(arr1, n1);
		readData(arr2, n2);
		merge(arr, n, arr1, n1, arr2, n2);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
	}
	return 0;
}