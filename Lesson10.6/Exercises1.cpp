/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<class T> void readData(vector<T>& v, int size) {
	for (int i = 0; i < size; i++)
	{
		T x;
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		float x;
		cin >> n >> x;
		vector<float> v;
		readData(v, n);
		cout << "Test " << i << ":\n";
		sort(v.begin(), v.end());
		if (binary_search(v.begin(), v.end(), x)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}