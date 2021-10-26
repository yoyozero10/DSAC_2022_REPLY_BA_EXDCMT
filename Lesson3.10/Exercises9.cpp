/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <list>
#include <exception>
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

template<class T> T findMax(list<T> l) {
	T max = l.front();
	for (auto i = l.begin(); i != l.end(); i++)
	{
		if (*i > max) {
			max = *i;
		}
	}
	return max;
}

template<class T> int removeDuplicate(list<T>& l) {
	int before = distance(l.begin(), l.end());
	l.sort();
	l.unique();
	int after = distance(l.begin(), l.end());
	return before - after;
}

template<class T> T maxK(list<T> l, int k) {
	if (k < 0 || k > distance(l.begin(), l.end())) {
		throw exception("Gia tri k khong hop le.");
	}
	else {
		int count = 0;
		for (auto i = l.rbegin(); i != l.rend(); i++)
		{
			count++;
			if (count == k) {
				return *i;
			}
		}
	}
}

int main() {
	list<int> numbers;
	getInput(numbers);
	cout << "Cac phan tu trong danh sach:\n";
	printList(numbers);
	cout << "Danh sach sau khi loai bo cac phan tu trung lap: \n";
	int removedItems = removeDuplicate(numbers);
	printList(numbers);
	cout << "Nhap k: ";
	int k;
	cin >> k;
	try {
		cout << "Gia tri lon thu " << k << ": " << maxK(numbers, k) << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}