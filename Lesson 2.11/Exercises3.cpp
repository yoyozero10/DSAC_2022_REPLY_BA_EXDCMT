/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <iomanip>
using namespace std;

// khai báo hàm nguyên mẫu
void output(int* arr, int n);
bool nextCombination(int* arr, int n, int k);
void generate(int* arr, int n, int k);

int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k; // đọc n, k
        int* arr = new int[k]; // tạo mảng 
        for (int i = 0; i < k; i++) { // đọc các phần tử của cấu hình cho trước
            cin >> arr[i];
        }
        cout << "Test " << count++ << ": \n";
        generate(arr, n, k);
        delete[] arr;
    }
}

// sinh tổ hợp kế tiếp
bool nextCombination(int* arr, int n, int k) {
    int i = k - 1;
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

// thuật toán sinh toàn bộ các tổ hợp kế tiếp
void generate(int* arr, int n, int k) {
    bool isFinalConfig = nextCombination(arr, n, k);
    if (!isFinalConfig) {
        while (!isFinalConfig) {
            output(arr, k);
            isFinalConfig = nextCombination(arr, n, k);
        }
    }
    else {
        cout << "UNAVAILABLE\n";
    }
}

void output(int* arr, int n) { // hiển thị kết quả
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}