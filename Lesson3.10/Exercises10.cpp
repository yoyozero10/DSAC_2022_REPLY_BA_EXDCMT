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

template<class T> int countX(list<T> l, T x) {
	int occ = 0;
	for (auto i = l.begin(); i != l.end(); i++)
	{
		if (x == *i) {
			occ++;
		}
	}
	return occ;
}

template<class T> void statistic(list<T> l) {
	for (auto i = l.begin(); i != l.end(); i++)
	{
		bool existed = false;
		for (auto j = l.begin(); j != i; j++)
		{
			if (*i == *j) {
				existed = true;
				break;
			}
		}
		if (!existed) {
			cout << *i << " - " << countX(l, *i) << endl;
		}
	}
}

int main() {
	list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu truoc khi sap xep:\n";
	printList(numbers);
	cout << "Danh sach cac phan tu va so lan xuat hien: \n";
	statistic(numbers);
	return 0;
}