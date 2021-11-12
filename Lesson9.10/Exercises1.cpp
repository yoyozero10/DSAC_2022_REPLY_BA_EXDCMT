/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <algorithm>
using namespace std;

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
		sort(arr, arr + n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}