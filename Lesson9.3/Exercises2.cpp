/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

template<class T> void selectionSort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t maxIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		swap(arr[i], arr[maxIndex]);
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
		selectionSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}