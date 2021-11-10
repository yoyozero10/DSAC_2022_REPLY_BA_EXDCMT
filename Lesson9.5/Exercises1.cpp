/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

// thuật toán sắp xếp shell
template<class T> void shellSort(T* arr, int size) {
	int interval = 1;
	while (interval < size / 3) {
		interval = interval * 3 + 1;
	}
	while (interval > 0) {
		for (int outer = interval; outer < size; outer++)
		{
			T target = arr[outer];
			int inner = outer;
			while (inner > interval - 1 && arr[inner - interval] >= target) {
				arr[inner] = arr[inner - interval];
				inner = inner - interval;
			}
			arr[inner] = target;
		}
		interval = (interval - 1) / 3;
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
		shellSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}