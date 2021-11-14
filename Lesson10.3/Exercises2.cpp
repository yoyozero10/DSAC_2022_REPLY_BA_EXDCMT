/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

int countX(string* arr, int n, string x);
int leftMostX(string* arr, int left, int right, string x);
int rightMostX(string* arr, int n, int left, int right, string x);

template<class T> void readData(T* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

template<class T> int countX(T* arr, int size, T x) {
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x) {
			counter++;
		}
	}
	return counter;
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
	for (int i = 1; i <= t; i++)
	{
		int n, x;
		cin >> n >> x;
		int* arr = new int[n];
		readData(arr, n);
		mergeSort(arr, 0, n - 1);
		cout << "Test " << i << ": \n";
		cout << countX(arr, n, x) << endl;
		delete[] arr;
	}
	return 0;
}

int countX(string* arr, int n, string x) {
	int counter = 0;
	// tìm vị trí trái cùng xuất hiện x
	int startPos = leftMostX(arr, 0, n - 1, x);
	if (startPos == -1) { // không tìm thấy x
		return counter;
	}
	// tìm vị trí phải củng xuất hiện x
	int endPos = rightMostX(arr, n, 0, n - 1, x);
	return endPos - startPos + 1;
}

int leftMostX(string* arr, int left, int right, string x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) { // tìm phía bên phải
			return leftMostX(arr, mid + 1, right, x);
		}
		else { // tìm phía trái
			return leftMostX(arr, left, mid - 1, x);
		}
	}
	return -1;
}

int rightMostX(string* arr, int n, int left, int right, string x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid] <= x) { // tìm phía bên phải
			return rightMostX(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostX(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}