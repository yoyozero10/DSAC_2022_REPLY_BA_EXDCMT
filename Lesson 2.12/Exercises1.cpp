#include <iostream>
#include <array>
using namespace std;
const int MAX_SIZE = 200;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimeNumbers(array<int, MAX_SIZE> arr, int n) {
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i])) {
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}

int main()
{
    int t;
    int n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        array<int, MAX_SIZE> numbers;
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        findPrimeNumbers(numbers, n);
    }
}
