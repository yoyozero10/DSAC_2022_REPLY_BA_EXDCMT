#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false; // k phai so nguyen to
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false; // k phai so nguyen to
        }
    }
    return true; // n la so nguyen to
}

void readData(int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void showResult(int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t; // so bo test
    int n; // so phan tu mang
    cin >> t;
    while (t--) {
        cin >> n;
        int* numbers = new int[n];
        readData(numbers, n);
        showResult(numbers, n);
        delete[] numbers;
    }

    return 0;
}