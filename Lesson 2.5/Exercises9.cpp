#include <iostream>
using namespace std;

int add(int n) {
    if (n <= 0) { // điểm dừng
        return 0;
    }
    else { // bước đệ quy
        return n + add(n - 1);
    }
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n > 0) {
        cout << "SUM = " << add(n) << endl;
    }
    else {
        cout << "Nhap vao hai so nguyen duong.\n";
    }
    return 0;
}