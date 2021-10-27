/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <forward_list>
using namespace std;

template<class T> void getInput(forward_list<T>& list) {
	int n;
	cout << "Nhap so phan tu cua list: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			cout << "Phan tu thu " << i + 1 << ": ";
			T value;
			cin >> value;
			list.push_front(value);
		}
	}
	else {
		cout << "Nhap n > 0 de tiep tuc.\n";
	}
}

template<class T> void printList(forward_list<T> l) {
	for (auto i = l.begin(); i != l.end(); i++) {
		cout << *i << "->";
	}
	cout << "null\n";
}

template<class T> bool removeKth(forward_list<T>& l, int k) {
	if (l.empty() || k < 1 || k > distance(l.begin(), l.end())) {
		return false;
	}
	else {
		int count = 0;
		for (auto i = l.before_begin(); i != l.end(); i++)
		{
			if (count == k - 1) {
				l.erase_after(i);
				return true;
			}
			count++;
		}
		return false;
	}
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu truoc khi xoa:\n";
	printList(numbers);
	int k;
	cout << "Nhap k = ";
	cin >> k;
	bool removeResult = removeKth(numbers, k);
	if (removeResult) {
		cout << "Danh sach cac phan tu sau khi xoa phan tu thu k: \n";
		printList(numbers);
	}
	else {
		cout << "Xoa that bai.\n";
	}

	return 0;
}