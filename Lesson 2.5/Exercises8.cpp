#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) { // đk dừng
        return a;
    }
    else { // bước đệ quy
        return gcd(b, a % b);
    }
}

int main() {
    int a, b;
    cout << "Nhap hai so nguyen duong a, b: ";
    cin >> a >> b;
    if (a > 0 && b > 0) {
        cout << "UCLN = " << gcd(a, b) << endl;
    }
    else {
        cout << "Nhap vao hai so nguyen duong.\n";
    }
    
    return 0;
}