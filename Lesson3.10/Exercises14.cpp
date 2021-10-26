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

template<class T> void removeAllX(list<T>& l, T x) {
	l.remove(x);
}

int main() {
	list<int> numbers;
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