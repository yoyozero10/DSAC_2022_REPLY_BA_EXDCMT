/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

template<class T> void showArrayElements(T* arr, size_t size);

// sắp xếp bubble sort tối ưu
template<class T> void bubbleSortOpt(T* arr, size_t size) {
	bool isSwapped;
	size_t i = size - 1;
	while (i > 0) {
		isSwapped = false;
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
				showArrayElements(arr, size);
			}
		}
		if (!isSwapped) {
			break;
		}
		else {
			i--;
		}
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
		bubbleSortOpt(arr, n);
		cout << "Test " << i << ":\n";
		delete[] arr;
	}
	return 0;
}