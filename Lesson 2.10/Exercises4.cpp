/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
// khai báo hàm nguyên mẫu
void output(string* names, int* arr, int n);
bool nextPermutation(int* arr, int n);
void generatePermutation(string* names, int n);

int main() {
	int t;
	ifstream ifs("CONTEST.INP");
	ifs >> t;
	ifs.ignore();
	int count = 1;
	while (t-- > 0) {
		int n = 0;
		string testCase;
		getline(ifs, testCase);
		stringstream ss(testCase);
		string names[100];
		string str;
		while (ss >> str) {
			names[n++] = str;
		}
		cout << "Test " << count++ << ": \n";
		generatePermutation(names, n); // sinh các cấu hình kế tiếp
	}
}

// sinh hoán vị kế tiếp
bool nextPermutation(int* arr, int n) {
	int i = n - 2;
	while (i >= 0 && arr[i] > arr[i + 1]) {
		i--;
	}
	if (i >= 0) {
		int k = n - 1;
		while (arr[i] > arr[k]) {
			k--;
		}
		int tmp = arr[i];
		arr[i] = arr[k];
		arr[k] = tmp;
		int r = i + 1;
		int s = n - 1;
		while (r < s) {
			int t = arr[r];
			arr[r] = arr[s];
			arr[s] = t;
			r++;
			s--;
		}
		return false;
	}
	else {
		return true;
	}
}

// thuật toán sinh hoán vị chính tắc
void generatePermutation(string* names, int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	bool isFinalConfig = false;
	while (!isFinalConfig) {
		output(names, arr, n);
		isFinalConfig = nextPermutation(arr, n);
	}
}

void output(string* names, int* arr, int n) { // hiển thị kết quả
	for (int i = 0; i < n; i++) {
		cout << names[arr[i] - 1] << ' ';
	}
	cout << endl;
}