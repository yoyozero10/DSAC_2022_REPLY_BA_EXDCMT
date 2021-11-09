/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

// sắp xếp theo buble sort tăng dần
template<class T> void bubbleSort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

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

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		int* arr = new int[n];
		readData(arr, n);
		bubbleSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}