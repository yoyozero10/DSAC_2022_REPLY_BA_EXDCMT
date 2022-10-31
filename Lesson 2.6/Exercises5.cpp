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

// giải pháp:
// từ phần tử đầu, gọi đệ quy tới tất cả các phần tử có thể đi tới từ phần tử đầu tiên.
// Số lượng tối thiểu các bước nhảy từ đầu tới cuối mảng có thể được tính toán sử dụng giá trị tối thiểu
// từ các lời gọi đệ quy.
// tức là: minJump(start, end) = min(minJump(k, end)) với mọi k có thể tới được từ đầu mảng.

#include <iostream>
using namespace std;

// tìm giá trị nhỏ nhất trong hai số
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// tìm số bước nhảy nhỏ nhất có thể
int minJump(int* arr, int n) {
	int* jumps = new int[n]();
	const int MAX_INT = 2100000000;
	if (n == 0 || arr[0] == 0) {
		return MAX_INT;
	}
	jumps[0] = 0;
	for (int i = 1; i < n; i++) {
		jumps[i] = MAX_INT;
		for (int j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != MAX_INT) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

int main() {
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "So lan nhay toi thieu: " << minJump(arr, size);
	cout << endl;
}