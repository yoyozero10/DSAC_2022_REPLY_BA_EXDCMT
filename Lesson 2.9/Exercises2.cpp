/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
using namespace std;

void output(int* arr, int n);
void generate(int* arr, int n);
bool nextBinaryString(int* arr, int n);

void generate(int* arr, int n) { // thuật toán sinh tất cả các xâu
    bool isFinal = nextBinaryString(arr, n);
    if (!isFinal) { // nếu đây chưa phải là cấu hình cuối cùng
        output(arr, n); // hiển thị cấu hình kế tiếp
    }
    else { // nếu đây là cấu hình cuối
        cout << "UNAVAILABLE\n";
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

int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t-- > 0) {
        int n;
        cin >> n; // đọc n
        int* arr = new int[n](); // tạo mảng với các giá trị mặc định
        for (int i = 0; i < n; i++) { // đọc các phần tử của cấu hình cho trước
            cin >> arr[i];
        }
        cout << "Test " << count++ << ": ";
        generate(arr, n);
    }
	return 0;
}