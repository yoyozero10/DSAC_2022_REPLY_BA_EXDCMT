/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
using namespace std;

// hàm tìm giá trị lớn nhất
int findMax(char* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
// thuật toán sắp xếp đếm
void countingSort(char* input, int size) {
	int k = findMax(input, size);
	int* output = new int[size];
	int* count = new int[k + 1]();
	for (int i = 0; i < size; i++)
	{
		int j = input[i];
		count[j]++;
	}
	for (int i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int j = input[i];
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

int main() {
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++) {
		char arr[500];
		cin.getline(arr, 500);
		cout << "Test " << i << ":\n";
		countingSort(arr, strlen(arr));
		cout << arr << endl;
	}
	return 0;
}