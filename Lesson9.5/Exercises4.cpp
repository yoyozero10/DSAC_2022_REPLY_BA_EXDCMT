/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
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
			while (inner > interval - 1 && arr[inner - interval] <= target) {
				arr[inner] = arr[inner - interval];
				inner = inner - interval;
			}
			arr[inner] = target;
		}
		interval = (interval - 1) / 3;
	}
}

// hàm hiển thị các phần tử mảng bất kì
template<class T> void showArrayElements(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// hàm tách từ trong chuỗi string
void split(string str, string* data, int& size) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		data[size++] = s;
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		string arr[500];
		int n = 0;
		string inputStr;
		getline(cin, inputStr);
		split(inputStr, arr, n);
		shellSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
	}
	return 0;
}