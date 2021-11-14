/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

template<class T> void readData(T* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

// thuật toán tìm kiếm nhị phân
template<class T> int binarySearch(T* arr, int left, int right, T x) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			return binarySearch(arr, mid + 1, right, x);
		}
		else {
			return binarySearch(arr, left, mid - 1, x);
		}
	}
	return -1; // không tìm thấy
}

// thuật toán trộn
template<class T> void merge(T* arr, int first, int middle, int last) {
	int size1 = middle - first + 1;
	int size2 = last - middle;
	T* leftArr = new T[size1];
	T* rightArr = new T[size2];
	for (int i = 0; i < size1; i++)
	{
		leftArr[i] = arr[first + i];
	}
	for (int j = 0; j < size2; j++)
	{
		rightArr[j] = arr[middle + j + 1];
	}
	int i = 0, j = 0, k = first;
	while (i < size1 && j < size2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}
	while (i < size1) {
		arr[k++] = leftArr[i++];
	}
	while (j < size2)
	{
		arr[k++] = rightArr[j++];
	}
}
// thuật toán sắp xếp trộn
template<class T> void mergeSort(T* arr, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergeSort(arr, first, middle);
		mergeSort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
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
		mergeSort(arr, 0, n - 1);
		cout << "Test " << i << ":\n";
		if (binarySearch(arr, 0, n-1, x) != -1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		delete[] arr;
	}
	return 0;
}