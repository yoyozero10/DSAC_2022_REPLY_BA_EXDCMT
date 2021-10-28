/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool symmetry(int* arr, int n) {
	int midIndex = (n % 2 == 0 ? n / 2 - 1 : n / 2);
	stack<int> s;
	for (int i = 0; i <= midIndex; i++)
	{
		s.push(arr[i]);
	}
	for (int i = n / 2; i < n; i++)
	{
		if (s.top() != arr[i]) {
			return false;
		}
		s.pop();
	}
	return true;
}

int main() {
	int t;
	ifstream ifs("input3.txt");
	if (ifs) {
		ifs >> t;
		while (t--) {
			int n;
			ifs >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++) {
				ifs >> arr[i];
			}
			if (symmetry(arr, n)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		ifs.close();
	}
}