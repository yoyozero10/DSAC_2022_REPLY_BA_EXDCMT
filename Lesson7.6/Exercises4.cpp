/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// hàm sàng xuống
template<class T> void siftDown(T* arr, int n, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < n && arr[left] < arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] < arr[largest]) {
		largest = right;
	}
	if (largest != index) {
		swap(arr[index], arr[largest]);
		siftDown(arr, n, largest);
	}
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
		siftDown(arr, i, 0);
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

// hàm tach từ
template<class T> void split(T* arr, string str, int& n) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		arr[n++] = s;
	}
}

int main() {
	int testNumber = 1;
	int t; // số bộ test
	cin >> t; // đọc số bộ test
	cin.ignore(); // bỏ qua kí tự thừa, tức '\n' khi bạn nhấn Enter
	while (t--) { // khi t > 0
		string str;
		getline(cin, str);
		int n = 0;
		string* arr = new string[str.length()];
		split(arr, str, n);
		heapSort(arr, n); // sắp xếp 
		cout << "Test " << testNumber++ << ":\n"; // hiển thị test thứ mấy
		showElements(arr, n); // hiển thị kết quả
		delete[] arr; // thu hồi bộ nhớ cấp phát động
	}

	return 0;
}
