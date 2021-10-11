/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

// top-down
unsigned long long fibonacciTopDown(unsigned long long* fibo, int n) {
    if (n < 2) {
        return fibo[n] = n;
    }
    if (fibo[n] == 0) {
        fibo[n] = fibonacciTopDown(fibo, n - 1) + fibonacciTopDown(fibo, n - 2);
    }
    return fibo[n];
}

// bottom-up
unsigned long long fibonacciBottomUp(int n) {
    unsigned long long f0 = 0;
    unsigned long long f1 = 1;
    unsigned long long fn = n < 2 ? n : 0;
    for (int i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int main()
{
    const int MAX = 90;
    int n;
    unsigned long long* fibo = new unsigned long long[MAX + 1]();
    cout << "Nhap n trong doan [0-90]: ";
    cin >> n;
    if (n >= 0 && n <= 90) {
        cout << "Top down: F(" << n << ") = " << fibonacciTopDown(fibo, n) << endl;
        cout << "Bottom up: F(" << n << ") = " << fibonacciBottomUp(n) << endl;
    }
    else {
        cout << "Nhap n trong doan 0-90.\n";
    }
}
