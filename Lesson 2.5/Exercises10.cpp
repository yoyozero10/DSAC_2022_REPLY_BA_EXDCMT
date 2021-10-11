#include <iostream>
using namespace std;

double add(int n) {
    if (n == 1) { // điểm dừng
        return 1;
    }
    else { // bước đệ quy
        return 1.0 / n + add(n - 1);
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