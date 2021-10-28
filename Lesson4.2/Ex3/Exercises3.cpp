/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
using namespace std;

template<class T> class Stack {
	T* data;
	int capacity;
	int currentSize;
public:
	Stack(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new T[capacity];
		currentSize = 0;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	bool isFull() {
		return currentSize == capacity;
	}

	void push(T value) {
		if (isFull()) {
			cout << "Stack day. Khong the push.\n";
		}
		else {
			data[currentSize++] = value;
		}
	}

	T pop() {
		if (isEmpty()) {
			throw exception("Stack rong.");
		}
		else {
			currentSize--;
			return data[currentSize];
		}
	}

	T top() {
		if (isEmpty()) {
			throw exception("Stack rong.");
		}
		else {
			return data[currentSize - 1];
		}
	}

	int size() {
		return currentSize;
	}

	~Stack() {
		delete[] data;
	}
};

bool symmetry(int* arr, int n) {
	int midIndex = (n % 2 == 0 ? n / 2 - 1 : n / 2);
	Stack<int> s(midIndex + 1);
	for (int i = 0; i <= midIndex; i++)
	{
		s.push(arr[i]);
	}
	for (int i = n / 2; i < n; i++)
	{
		if (s.pop() != arr[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	ifstream ifs("input3.txt");
	if (ifs) {
		ifs >> t;
		while (t--) {
			int n;
			ifs >> n;
			int* arr = new int[n];
			for (int i = 0; i < n; i++) {
				ifs >> arr[i];
			}
			if (symmetry(arr, n)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		ifs.close();
	}
}