#include <iostream>
#include <array>
using namespace std;
const int MAX_SIZE = 200;

bool checkSymmetry(array<int, MAX_SIZE> arr, int n) {
    for (int i = 0; i <= n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }
    return true;
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
        cout << (checkSymmetry(numbers, n) ? "YES" : "NO") << endl;
    }
}
