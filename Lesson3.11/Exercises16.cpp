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

template<class T> T findMiddle(forward_list<T> l) {
	auto i = l.begin();
	auto j = l.begin();
	while (i != l.end() && (++i) != l.end()) {
		i++;
		j++;
	}
	return *j;
}

int main() {
	forward_list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu trong danh sach:\n";
	printList(numbers);
	cout << "Gia tri phan tu giua danh sach: ";
	cout << findMiddle(numbers) << endl;
	return 0;
}