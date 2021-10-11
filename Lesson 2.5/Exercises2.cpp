/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

unsigned long long fiboN(int n) {
    if (n < 2) { // điểm dừng
        return n;
    }
    else { // bước đệ quy
        return fiboN(n - 1) + fiboN(n - 2);
    }
}

int main() {
    int n;
    cout << "Nhap n <= 90: ";
    cin >> n;
    if (n >= 0 && n <= 90) {
        cout << "F(" << n << ") = " << fiboN(n) << endl;
    }
    else {
        cout << "Nhap n <= 90.\n";
    }
    return 0;
}