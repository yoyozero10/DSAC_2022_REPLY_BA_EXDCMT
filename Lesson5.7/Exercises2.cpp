/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max = n;
	priority_queue<int, vector<int>, less<int>> queue;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		queue.push(x);
		while (!queue.empty() && queue.top() == max) {
			cout << queue.top() << ' ';
			queue.pop();
			--max;
		}
		cout << endl;
	}
	return 0;
}