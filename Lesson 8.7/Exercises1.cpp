/**
*	@author:	Branium Academy
*	@version:	2022.06
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> T findMax(T* arr, int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<class T> void bucketSort(T* arr, int n, int k) {
    if (k < 0) {
        cout << "Gia tri phan vung khong hop le.\n";
        return;
    }
    vector<T>* buckets = new vector<T>[k + 1];
    T max = findMax(arr, n);
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = (int)(arr[i] * k / max);
        buckets[bucketIndex].push_back(arr[i]);
    }
    for (int i = 0; i <= k; i++)
    {
        if (buckets[i].size() > 0) {
            sort(buckets[i].begin(), buckets[i].end());
        }
    }
    int index = 0;
    for (int i = 0; i <= k; i++)
    {
        size_t bSize = buckets[i].size();
        for (size_t j = 0; j < bSize; j++)
        {
            arr[index++] = buckets[i][j];
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
		double* arr = new double[n];
		readData(arr, n);
		bucketSort(arr, n, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
		delete[] arr;
	}
	return 0;
}