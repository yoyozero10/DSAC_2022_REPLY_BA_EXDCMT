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
bool nextPermutation(int* arr, int n);
void generatePermutation(int* arr, int n);

int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t-- > 0) {
        int n;
        cin >> n;
        int* arr = new int[n]();
        for (int i = 0; i < n; i++) { // đọc các phần tử từ mảng cho trước
            cin >> arr[i];
        }
        cout << "Test " << count++ << ": \n";
        generatePermutation(arr, n); // sinh các cấu hình kế tiếp
        delete[] arr;
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
void generatePermutation(int* arr, int n) {
    bool isFinalConfig = nextPermutation(arr, n);
    if (!isFinalConfig) {
        while (!isFinalConfig) {
            output(arr, n);
            isFinalConfig = nextPermutation(arr, n);
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