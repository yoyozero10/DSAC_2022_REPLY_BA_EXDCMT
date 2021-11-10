/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

template<class T> void showArrayElements(T* arr, size_t size);

template<class T> void selectionSort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
		showArrayElements(arr, size);
	}
}

// hàm hiển thị kết quả
template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// hàm đọc dữ liệu đầu vào từ bàn phím
template<class T> void readData(T* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		int* arr = new int[n];
		readData(arr, n);
		cout << "Test " << i << ":\n";
		selectionSort(arr, n);
		delete[] arr;
	}
	return 0;
}