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

template<class T> int removeDuplicate(forward_list<T>& l) {
	int before = distance(l.begin(), l.end());
	l.sort();
	l.unique();
	int after = distance(l.begin(), l.end());
	return before - after;
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu trong danh sach:\n";
	printList(numbers);
	cout << "Danh sach sau khi loai bo cac phan tu trung lap: \n";
	int removedItems = removeDuplicate(numbers);
	printList(numbers);
	cout << "Da loai bo " << removedItems << " phan tu trung lap.\n";
	return 0;
}