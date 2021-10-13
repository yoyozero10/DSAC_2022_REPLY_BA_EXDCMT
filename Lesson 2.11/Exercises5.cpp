/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <iomanip>
using namespace std;

// khai báo hàm nguyên mẫu
void output(int* arr, int* combines, int m, int n);
bool nextCombination(int* arr, int n, int k);
void generate(int* arr, int n, int k, int s);
int sum(int* arr, int* combines, int n, int m);

int main() {
	int t;
	cin >> t;
	int count = 1;
	while (t-- > 0) {
		int n, k, s;
		cin >> n >> k >> s; 
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "Test " << count++ << ": \n";
		generate(arr, n, k, s);
		delete[] arr;
	}
}

// sinh tổ hợp kế tiếp
bool nextCombination(int* arr, int size, int n) {
	int i = size - 1;
	int k = size;
	while (i >= 0 && arr[i] == n - k + i + 1) {
		i--;
	}
	if (i >= 0) {
		arr[i] = arr[i] + 1;
		for (int j = i + 1; j < k; j++) {
			arr[j] = arr[i] + j - i;
		}
		return false; // chưa phải cấu hình cuối cùng
	}
	else {
		return true; // đã là cấu hình cuối cùng
	}
}

// thuật toán sinh toàn bộ các tổ hợp chập k của n
void generate(int* arr, int n, int k, int s) {
	int* combines = new int[k]();
	for (int j = 0; j < k; j++)
	{
		combines[j] = j + 1;
	}
	int count = 0;
	bool isFinalConfig = false;
	while (!isFinalConfig) {
		if (sum(arr, combines, n, k) == s) {
			output(arr, combines, n, k);
			count++;
		}
		isFinalConfig = nextCombination(combines, k, n);
	}
	if (count == 0) {
		cout << "NO RESULT\n";
	}
}

// tính tổng các phần tử trong tập sinh đc
int sum(int* arr, int* combines, int n, int k) {
	int result = 0;
	for (int i = 0; i < k; i++)
	{
		result += arr[combines[i] - 1];
	}
	return result;
}

// hiện kết quả
void output(int* arr, int* combines, int m, int n) { // hiển thị kết quả
	for (int i = 0; i < n; i++) {
		cout << arr[combines[i] - 1] << ' ';
	}
	cout << endl;
}