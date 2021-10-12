/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

long coin(long* result, long n) {
    if (n == 0) { // trường hợp cơ sở
        return 0;
    }
    else if (n < 12) { // trường hợp cơ sở
        return n;
    }
    else {
        if (n < 1000000) {
            if (result[(int)n] > 0) return result[(int)n];
        }
        long tmp = max(n, coin(result, n / 2) + coin(result, n / 3) + coin(result, n / 4));
        if (n < 1000000) {
            result[(int)n] = tmp;
        }
        return tmp;
    }
}

int main() {
	long* result = new long[1000000](); // tối đa 100k phần tử
    long n;
    cin >> n;
    cout << coin(result, n) << endl;
	delete[] result;
	return 0;
}