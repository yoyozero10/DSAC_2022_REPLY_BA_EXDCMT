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

template<class T> void removeAllX(forward_list<T>& l, T x) {
	l.remove(x);
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu truoc khi xoa:\n";
	printList(numbers);
	int x;
	cout << "Nhap x = ";
	cin >> x;
	cout << "Danh sach cac phan tu sau khi xoa tat ca cac phan tu x: \n";
	removeAllX(numbers, x);
	printList(numbers);
	return 0;
}