/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int countX(string* arr, int n, string x);
int leftMostX(string* arr, int left, int right, string x);
int rightMostX(string* arr, int n, int left, int right, string x);

// hàm tách từ trong chuỗi string
void split(string str, string* data, int& size) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		data[size++] = s;
	}
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
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		string arr[500];
		int n = 0;
		string inputStr;
		string x;
		cin >> x;
		cin.ignore(); // loại bỏ bộ nhớ đệm
		getline(cin, inputStr);
		transform(inputStr.begin(), inputStr.end(), inputStr.begin(),
			[](unsigned char c) { return tolower(c); });
		transform(x.begin(), x.end(), x.begin(),
			[](unsigned char c) { return tolower(c); });
		split(inputStr, arr, n);
		mergeSort(arr, 0, n - 1);
		cout << countX(arr, n, x) << endl;
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
		if ((mid == 0 || arr[mid - 1].compare(x) < 0) && arr[mid].compare(x) == 0) {
			return mid;
		}
		if (arr[mid].compare(x) <= 0) { // tìm phía bên phải
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
		if ((mid == n - 1 || arr[mid + 1].compare(x) > 0) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid].compare(x) <= 0) { // tìm phía bên phải
			return rightMostX(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostX(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}