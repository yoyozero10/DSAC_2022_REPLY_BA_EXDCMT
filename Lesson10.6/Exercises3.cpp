/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int countX(vector<string> arr, string x);
int leftMostX(vector<string> arr, int left, int right, string x);
int rightMostX(vector<string> arr, int n, int left, int right, string x);

// hàm tách từ trong chuỗi string
void split(string str, vector<string>& data) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		data.push_back(s);
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		vector<string> arr;
		string inputStr;
		string x;
		cin >> x;
		cin.ignore(); // loại bỏ bộ nhớ đệm
		getline(cin, inputStr);
		transform(inputStr.begin(), inputStr.end(), inputStr.begin(),
			[](unsigned char c) { return tolower(c); });
		transform(x.begin(), x.end(), x.begin(),
			[](unsigned char c) { return tolower(c); });
		split(inputStr, arr);
		sort(arr.begin(), arr.end());
		cout << countX(arr, x) << endl;
	}
	return 0;
}

int countX(vector<string> arr, string x) {
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

int leftMostX(vector<string> arr, int left, int right, string x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == 0 || arr[mid - 1].compare(x) < 0) && arr[mid].compare(x) == 0) {
			return mid;
		}
		if (arr[mid].compare(x) <= 0) { // tìm phía bên phải
			return leftMostX(arr, mid + 1, right, x);
		}
		else { // tìm phía trái
			return leftMostX(arr, left, mid - 1, x);
		}
	}
	return -1;
}

int rightMostX(vector<string> arr, int n, int left, int right, string x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == n - 1 || arr[mid + 1].compare(x) > 0) && arr[mid] == x) {
			return mid;
		}
		if (arr[mid].compare(x) <= 0) { // tìm phía bên phải
			return rightMostX(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostX(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}