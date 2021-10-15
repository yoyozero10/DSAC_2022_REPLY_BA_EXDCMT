#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// khai báo hàm nguyên mẫu
bool isReversed(int i);
void showResult(int* result, int n);

int main() {
    ifstream ifs("input2.txt");
    if (ifs) {
        int t;
        ifs >> t;
        string str;
        ifs.ignore();
        while (t-- > 0) {
            int n = 0;
            int arr[500];
            int number;
            getline(ifs, str);
            stringstream ss(str);
            while (ss >> number) {
                arr[n++] = number;
            }
            showResult(arr, n);
        }
        ifs.close();
    }
}

void showResult(int* result, int n) {
    for (int i = 0; i < n; i++) {
        if (isReversed(result[i])) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

bool isReversed(int i) {
    int n = i;
    int rev = 0;
    while (i > 0) {
        rev = rev * 10 + i % 10;
        i /= 10;
    }
    return n == rev;
}