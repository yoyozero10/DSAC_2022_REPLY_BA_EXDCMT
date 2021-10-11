/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

// hàm tính giai thừa bằng đệ quy
unsigned long long factorial(int n) {
    if (n < 2) { // điểm dừng
        return 1;
    }
    else { // bước đệ quy
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    cout << "Nhap n khong qua 22: ";
    cin >> n;
    if (n > 0 && n <= 22) {
        cout << factorial(n) << endl;
    }
    else {
        cout << "Gia tri n khong hop le.\n";
    }
}
