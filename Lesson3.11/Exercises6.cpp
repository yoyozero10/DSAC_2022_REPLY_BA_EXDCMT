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

template<class T> void sortDESC(forward_list<T>& l) {
	l.sort(greater<T>());
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu truoc khi sap xep:\n";
	printList(numbers);
	cout << "Cac phan tu sau khi sap xep giam dan: \n";
	sortDESC(numbers);
	printList(numbers);

	return 0;
}