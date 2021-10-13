/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * Phương thức chuyển đổi chuỗi nhị phân sang giá trị số ở hệ 10
 *
 * @param arr mảng chứa chuỗi nhị phân
 * @return giá trị số tính được từ chuỗi nhị phân cho trước ở hệ 10
 */
int convertBinaryToDecimal(int* arr, int n) {
    int number = 0;
    for (int i = 0; i < n; i++) {
        number += arr[i] * (int)pow(2, n - 1 - i);
    }
    return number;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    int count = 1;
    while (t-- > 0) {
        string testCase;
        getline(cin, testCase);
        stringstream ss(testCase);
        int n = 0;
        int arr[100];
        int x;
        while (ss >> x) {
            arr[n++] = x;
        }
        int result = convertBinaryToDecimal(arr, n);
        cout << result << endl;
    }
	return 0;
}