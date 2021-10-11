/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

int firstDigit(long long n) {
    if (n < 10) { // điểm dừng
        return n;
    }
    else { // bước đệ quy
        return firstDigit(n / 10);
    }
}

int main() {
    long long n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n > 0) {
        cout << firstDigit(n) << endl;
    }
    else {
        cout << "Nhap n > 0.\n";
    }
    return 0;
}