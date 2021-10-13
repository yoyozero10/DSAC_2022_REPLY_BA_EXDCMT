/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
using namespace std;

// khai báo nguyên mẫu hàm
void generate(int* arr, int n); 
bool nextBinaryString(int* arr, int n); 
void output(int* arr, int n); 

void generate(int* arr, int n) { // thuật toán sinh tất cả các xâu
	bool isFinal = false;
	while (!isFinal) {
		output(arr, n);
		isFinal = nextBinaryString(arr, n);
	}
}

bool nextBinaryString(int* arr, int n) { // thuật toán sinh xâu kế tiếp
	int i = n - 1;
	while (i >= 0 && arr[i] != 0) {
		arr[i] = 0;
		i--;
	}
	if (i >= 0) {
		arr[i] = 1;
		return false;
	}
	else {
		return true;
	}
}

void output(int* arr, int n) { // hiển thị kết quả
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main()
{
	int t;
	int count = 1;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		cout << "Test " << count++ << ": \n";
		int* arr = new int[n]();
		generate(arr, n);
		delete[] arr;
	}
}
