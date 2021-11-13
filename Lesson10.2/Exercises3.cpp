/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

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

// đếm các từ bắt đầu bởi chữ cái x
int count(string* arr, int size, char x) {
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].at(0) == x || tolower(arr[i].at(0)) == tolower(x)) { // nếu tìm thấy x trong mảng
			counter++;
		}
	}
	return counter;
}

int main() {
	int t;
	cin >> t;
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		string arr[500];
		int n = 0;
		string inputStr;
		char x;
		cin >> x;
		cin.ignore(); // loại bỏ bộ nhớ đệm
		getline(cin, inputStr);
		split(inputStr, arr, n);
		cout << count(arr, n, x) << endl;
	}
	return 0;
}