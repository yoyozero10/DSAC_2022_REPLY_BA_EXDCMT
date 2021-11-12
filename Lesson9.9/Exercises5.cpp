/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// hàm tìm max
int findMax(string* arr, int n) {
	int max = arr[0].length();
	for (int i = 1; i < n; i++)
	{
		if (arr[i].length() > max) {
			max = arr[i].length();
		}
	}
	return max;
}
// thuật toán counting sort
void countingSort(string* input, int size, int exp) {
	int k = 'z' - 'A' + 1;
	string* output = new string[size]();
	int* count = new int[k + 1]();
	for (int i = 0; i < size; i++)
	{
		int j = (input[i].length() - 1 < exp) ? 0 : (input[i].at(exp) - 'A') + 1;
		count[j]++;
	}
	for (int i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int j = (input[i].length() - 1 < exp) ? 0 : (input[i].at(exp) - 'A') + 1;
		count[j]--;
		output[count[j]] = input[i];
	}
	for (int i = 0; i < size; i++)
	{
		input[i] = output[i];
	}
	delete[] count;
	delete[] output;
}
// thuật toán radix sort
void radixSort(string* arr, int n) {
	int max = findMax(arr, n);
	for (int i = max - 1; i >= 0; i--)
	{
		countingSort(arr, n, i);
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
		radixSort(arr, n);
		cout << "Test " << i << ":\n";
		showArrayElements(arr, n);
	}
	return 0;
}