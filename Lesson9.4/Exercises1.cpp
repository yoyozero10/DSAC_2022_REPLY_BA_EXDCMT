/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

// thuật toán sắp xếp chèn
template<class T> void insertionSort(T* arr, int size) {
	for (int i = 1; i < size; i++)
	{
		T target = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > target) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = target;
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
		insertionSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}