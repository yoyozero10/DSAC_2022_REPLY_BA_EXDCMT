/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

// top-down
unsigned long long factorialTD(unsigned long long* fa, int n) {
    if (n == 0) {
        return 1;
    }
    if (fa[n] == 0) {
        fa[n] = n * factorialTD(fa, n - 1);
    }
    return fa[n];
}

// bottom-up
unsigned long long factorialBT(int n) {
    unsigned long long fn = 1;
    for (int i = 1; i <= n; i++) {
        fn *= i; // tính lần lượt các k! với 0 < k <= n
    }
    return fn; // kết quả
}

int main()
{
    const int MAX = 20;
    int n;
    unsigned long long* fibo = new unsigned long long[MAX + 1]();
    cout << "Nhap n trong doan [0-20]: ";
    cin >> n;
    if (n >= 0 && n <= 20) {
        cout << "Top down: " << n << "! = " << factorialTD(fibo, n) << endl;
        cout << "Bottom up: " << n << "! = " << factorialBT(n) << endl;
    }
    else {
        cout << "Nhap n trong doan 0-20.\n";
    }
}