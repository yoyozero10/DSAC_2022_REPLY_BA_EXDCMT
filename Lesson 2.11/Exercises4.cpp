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
void generate(int* arr, int n, int k);
int sum(int* arr, int* combines, int size);

int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k; // đọc n, k
        int* arr = new int[n]; // tạo mảng 
        for (int i = 0; i < n; i++) { // đọc các phần tử của cấu hình cho trước
            cin >> arr[i];
        }
        cout << "Test " << count++ << ": \n";
        generate(arr, n, k);
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

// thuật toán sinh toàn bộ các tổ hợp kế tiếp
void generate(int* arr, int n, int k) {
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int* combines = new int[i]();
        for (int j = 0; j < i; j++)
        {
            combines[j] = j + 1;
        }
        bool isFinalConfig = false;
            while (!isFinalConfig) {
                if (sum(arr, combines, i) == k) {
                    output(arr, combines, n, i);
                    count++;
                }
                isFinalConfig = nextCombination(combines, i, n);
            }
    }
    if(count == 0) {
        cout << "NO RESULT\n";
    }
}

// hàm tính tổng các phần tử trong tổ hợp
int sum(int* arr, int* combines, int size) {
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += arr[combines[i] - 1];
    }
    return result;
}

void output(int* arr, int* combines, int m, int n) { // hiển thị kết quả
    for (int i = 0; i < n; i++) {
        cout << arr[combines[i] - 1] << ' ';
    }
    cout << endl;
}