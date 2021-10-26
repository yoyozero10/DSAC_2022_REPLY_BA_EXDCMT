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

template<class T> void merge(list<T> l1, list<T> l2, list<T>& target) {
	auto i = l1.begin();
	auto j = l2.begin();
	// khi hai danh sách cùng chưa kết thúc
	while (i != l1.end() && j != l2.end()) {
		if (*i < *j) {
			target.push_back(*i);
			i++;
		}
		else {
			target.push_back(*j);
			j++;
		}
	}
	// thêm các phần tử còn lại trong danh sách l1 vào danh sách đích
	while (i != l1.end()) {
		target.push_back(*i);
		i++;
	}
	// thêm các phần tử còn lại trong danh sách l2 vào danh sách đích
	while (j != l2.end()) {
		target.push_back(*j);
		j++;
	}
}

int main() {
	list<int> l1;
	list<int> l2;

	getInput(l1);
	getInput(l2);

	cout << "Cac phan tu trong danh sach l1:\n";
	printList(l1);

	cout << "Cac phan tu trong danh sach l2:\n";
	printList(l2);

	cout << "Danh sach sau khi tron: ";
	l1.sort();
	l2.sort();

	list<int> l3;
	merge(l1, l2, l3);
	printList(l3);

	return 0;
}