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

// hàm hiển thị các phần tử mảng bất kì
template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// hàm tách từ trong chuỗi string
void split(string str, string* data, int& size) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		data[size++] = s;
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		string arr[500];
		int n = 0;
		string inputStr;
		getline(cin, inputStr);
		split(inputStr, arr, n);
		mergeSort(arr, 0, n - 1);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
	}
	return 0;
}