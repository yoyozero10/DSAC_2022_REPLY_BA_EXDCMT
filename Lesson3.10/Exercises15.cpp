/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <list>
using namespace std;

template<class T> void getInput(list<T>& list) {
	int n;
	cout << "Nhap so phan tu cua list: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			cout << "Phan tu thu " << i + 1 << ": ";
			T value;
			cin >> value;
			list.push_back(value);
		}
	}
	else {
		cout << "Nhap n > 0 de tiep tuc.\n";
	}
}

template<class T> void printList(list<T> l) {
	for (auto i = l.begin(); i != l.end(); i++) {
		cout << *i << "->";
	}
	cout << "null\n";
}

template<class T> bool addAfterKth(list<T>& l, T x, int k) {
	if (k < 1 || k > distance(l.begin(), l.end())) {
		return false;
	}
	else {
		int count = 1;
		auto i = l.begin();
		while (count < k) {
			count++;
			i++;
		}
		l.insert(++i, x);
		return true;
	}
}

int main() {
	list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu trong danh sach:\n";
	printList(numbers);
	int x;
	cout << "Nhap x can chen: ";
	cin >> x;
	int k;
	cout << "Nhap vi tri: ";
	cin >> k;
	if (addAfterKth(numbers, x, k)) {
		cout << "Danh sach cac phan tu sau khi chen x vao vi tri k: \n";
		printList(numbers);
	}
	else {
		cout << "Chen that bai.\n";
	}
	return 0;
}