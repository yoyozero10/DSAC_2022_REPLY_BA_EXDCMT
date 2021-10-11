/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

int countDigits(long long n) {
    if (n < 10) { // điều kiện dừng
        return 1;
    }
    else { // bước đệ quy
        return 1 + countDigits(n / 10);
    }
}

int main() {
    long long n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n > 0) {
        cout << countDigits(n) << endl;
    }
    else {
        cout << "Nhap n > 0.\n";
    }
    return 0;
}