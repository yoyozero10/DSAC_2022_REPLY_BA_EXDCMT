/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
using namespace std;

// hàm sàng xuống
template<class T> void siftDown(T* arr, int n, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != index) {
		swap(arr[index], arr[largest]);
		siftDown(arr, n, largest);
	}
}

// hàm hiển thị các phần tử mảng
template<class T> void showElements(T* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// hàm sắp xếp heap sort
template<class T> void heapSort(T* arr, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		siftDown(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		showElements(arr, n); // hiển thị kết quả
		siftDown(arr, i, 0);
	}
}

// hàm đọc dữ liệu đầu vào
template<class T> void readInput(T* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int main() {
	int testNumber = 1;
	int t; // số bộ test
	int n;
	cin >> t; // đọc số bộ test
	while (t--) { // khi t > 0
		cin >> n; // đọc số phần tử của mảng
		int* arr = new int[n];
		readInput(arr, n); // đọc các phần tử trong mảng
		heapSort(arr, n); // sắp xếp 
		cout << "Test " << testNumber++ << ":\n"; // hiển thị test thứ mấy
		delete[] arr; // thu hồi bộ nhớ cấp phát động
	}

	return 0;
}
