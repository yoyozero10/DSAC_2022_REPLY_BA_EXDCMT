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

template<class T> void addTail(forward_list<T>& list, T value) {
	if (list.empty()) {
		list.push_front(value);
	}
	else {
		auto i = list.begin();
		auto j = i;
		while (i != list.end()) {
			j = i;
			i++;
		}

		list.insert_after(j, value);
	}

}

template<class T> void merge(forward_list<T> l1, forward_list<T> l2, forward_list<T>& target) {
	auto i = l1.begin();
	auto j = l2.begin();
	// khi hai danh sách cùng chưa kết thúc
	while (i != l1.end() && j != l2.end()) {
		if (*i < *j) {
			addTail(target, *i);
			i++;
		}
		else {
			addTail(target, *j);
			j++;
		}
	}
	// thêm các phần tử còn lại trong danh sách l1 vào danh sách đích
	while (i != l1.end()) {
		addTail(target, *i);
		i++;
	}
	// thêm các phần tử còn lại trong danh sách l2 vào danh sách đích
	while (j != l2.end()) {
		addTail(target, *j);
		j++;
	}
}

int main() {
	forward_list<int> l1;
	forward_list<int> l2;

	getInput(l1);
	getInput(l2);

	cout << "Cac phan tu trong danh sach l1:\n";
	printList(l1);

	cout << "Cac phan tu trong danh sach l2:\n";
	printList(l2);

	cout << "Danh sach sau khi tron: ";
	l1.sort();
	l2.sort();

	forward_list<int> l3;
	merge(l1, l2, l3);
	printList(l3);

	return 0;
}