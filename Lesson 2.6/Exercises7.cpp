/**
 * @file Exercises7.cpp
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @brief Update exercises 7 lesson 2.6
 * @version 3.0
 * @date 2023-01-16
 *
 * @copyright Copyright (c) Branium Academy 2023
 *
 *
 --> Ý tưởng:
	Gọi LIS: độ dài chuỗi con tăng dài nhất
	Xét mảng arr[] = { 3, 10, 2, 11 }
	Gọi f(i) là hàm tính toán và trả về LIS của mảng con kết thúc tại chỉ số 'i'
	Giả định i tăng từ 0

	(LIS(0) = 1)

	    f(3)        với { f(3) = 1 + max(f(0), f(1), f(2)) }
	/    |    \
	f(0) f(1)  f(2) với { f(2) = 1, f(1) và f(0) cùng lớn hơn f(2) }
	|     |  \
	f(0) f(1) f(0)  với { f(1) = 1 + max(f(0) }
	|
	f(0)            với { f(0) = 1 }
*/

#include <iostream>
using namespace std;

// hàm tìm giá trị lớn nhất trong hai số đã cho
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// hàm tìm độ dài dãy tăng dài nhất
// sử dụng chiến lược bottom-up
int findMax(int index, int prevIndex, int n, int* arr, int** dp) {
	if (index == n) { // nếu tìm đến chỉ số n -> kết quả chưa được tính toán
		return 0;
	}
	// nếu phần tử trước đó đã được tính toán
	if (dp[index][prevIndex + 1] != 0) {
		return dp[index][prevIndex + 1]; // trả về giá trị đã đc tính toán
	}
	// tìm giá trị độ dài dãy tăng tối đa tính đến vị trí hàng kế tiếp
	int first = findMax(index + 1, prevIndex, n, arr, dp);
	int second = -1; 
	// nếu trước đó chưa xét phần tử nào hoặc phần tử mảng đang xét lớn hơn phần tử đã xét
	if (prevIndex == -1 || arr[index] > arr[prevIndex]) {
		// tìm giá trị lớn nhất của độ dài dãy tăng tính tới vị trí hàng kế tiếp
		second = 1 + findMax(index + 1, index, n, arr, dp);
	}
	// gán và trả về giá trị độ dài tối đa tính đến vị trí đang xét
	return dp[index][prevIndex + 1] = max(second, first);
}

int main() {
	int arr[] = { 10, 22, 9, 30, 27, 45, 41, 62, 87 };
	int size = sizeof(arr) / sizeof(int);

	// mảng lưu kết quả tạm thời, khởi tạo các phần tử của mảng ban đầu bằng 0
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

/* mảng kết quả tạm thời : tính toán từ dưới lên.
 * Kết hợp debug để xem quá trình tính toán cho dễ hiểu hơn.
 *
 *	6 0 0 0 0 0 0 0 0 0
 *	5 5 0 0 0 0 0 0 0 0
 *	5 4 4 0 0 0 0 0 0 0
 *	4 4 4 4 0 0 0 0 0 0
 *	4 4 4 4 3 0 0 0 0 0
 *	3 3 3 3 3 3 0 0 0 0
 *	3 3 3 3 3 3 2 0 0 0
 *	2 2 2 2 2 2 2 2 0 0
 *	1 1 1 1 1 1 1 1 1 0
 *	0 0 0 0 0 0 0 0 0 0
 */