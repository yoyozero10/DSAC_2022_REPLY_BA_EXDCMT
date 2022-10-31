/**
 * @file Exercises4.cpp
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @brief Update exercises 4 lesson 2.6
 * @version 2.0
 * @date 2022-10-31
 *
 * @copyright Copyright (c) Branium Academy 2022
 *
 */
#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int findMax(int index, int prevIndex, int n, int* arr, int** dp) {
	if (index == n) {
		return 0;
	}
	if (dp[index][prevIndex + 1] != 0) {
		return dp[index][prevIndex + 1];
	}
	int first = findMax(index + 1, prevIndex, n, arr, dp);
	int second = -1;
	if (prevIndex == -1 || arr[index] > arr[prevIndex]) {
		second = 1 + findMax(index + 1, index, n, arr, dp);
	}
	return dp[index][prevIndex + 1] = max(second, first);
}

int main() {
	int arr[] = { 10, 22, 9, 30, 27, 45, 41, 62, 87 };
	int size = sizeof(arr) / sizeof(int);
	// mảng lưu kết quả tạm thời
	int** dp = new int* [size + 1];
	for (int i = 0; i < size + 1; i++) {
		dp[i] = new int[size + 1]();
	}
	int result = findMax(0, -1, size, arr, dp);
	cout << "Do dai chuoi tang: " << result << endl;
	// thu hồi bộ nhớ
	for (int i = 0; i < size + 1; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}