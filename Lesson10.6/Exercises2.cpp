/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countX(vector<int>& arr, int x);
int leftMostX(vector<int>& arr, int left, int right, int x);
int rightMostX(vector<int>& arr, int n, int left, int right, int x);

template<class T> void readData(vector<T>& v, int size) {
	for (int i = 0; i < size; i++)
	{
		T x;
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<int> v;
		int n;
		int x;
		cin >> n >> x;
		readData(v, n);
		cout << "Test " << i << ":\n";
		cout << countX(v, x) << endl;
	}
	return 0;
}

int countX(vector<int>& arr, int x) {
	int counter = 0;
	int n = arr.size();
	// tìm vị trí trái cùng xuất hiện x
	int startPos = leftMostX(arr, 0, n - 1, x);
	if (startPos == -1) { // không tìm thấy x
		return counter;
	}
	// tìm vị trí phải củng xuất hiện x
	int endPos = rightMostX(arr, n, 0, n - 1, x);
	return endPos - startPos + 1;
}

int leftMostX(vector<int>& arr, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) { // tìm phía bên phải
			return leftMostX(arr, mid + 1, right, x);
		}
		else { // tìm phía trái
			return leftMostX(arr, left, mid - 1, x);
		}
	}
	return -1;
}

int rightMostX(vector<int>& arr, int n, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid] <= x) { // tìm phía bên phải
			return rightMostX(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostX(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}