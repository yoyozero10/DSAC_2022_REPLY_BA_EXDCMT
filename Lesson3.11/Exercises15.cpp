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

template<class T> bool addAfterValueK(forward_list<T>& l, T x, T k) {
	bool found = false;
	auto i = l.begin();
	while (i != l.end()) {
		if (*i == k) {
			found = true;
			break;
		}
		i++;
	}
	if (found) {
		l.insert_after(i, x);
		return true;
	}
	else {
		return false;
	}
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu trong danh sach:\n";
	printList(numbers);
	int x;
	cout << "Nhap x can chen: ";
	cin >> x;
	int k;
	cout << "Nhap gia tri k: ";
	cin >> k;
	if (addAfterValueK(numbers, x, k)) {
		cout << "Danh sach cac phan tu sau khi chen x sau gia tri k: \n";
		printList(numbers);
	}
	else {
		cout << "Chen that bai.\n";
	}
	return 0;
}