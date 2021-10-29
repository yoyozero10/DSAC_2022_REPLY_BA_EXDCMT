/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
using namespace std;

template<class T> class Node {
public:
	T data;
	Node<T>* next;

	Node(T data) {
		next = nullptr;
		this->data = data;
	}
};

template<class T> class Stack {
private:
	Node<T>* head;
	int currentSize;
public:
	Stack() {
		head = nullptr;
		currentSize = 0;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	int size() {
		return currentSize;
	}

	T top() {
		if (isEmpty()) {
			throw exception("Stack rong.");
		}
		else {
			return head->data;
		}
	}

	T pop() {
		if (isEmpty()) {
			throw exception("Stack rong.");
		}
		else {
			T t = head->data;
			head = head->next;
			currentSize--;
			return t;
		}
	}

	void push(T value) {
		Node<T>* p = new Node<T>(value);
		if (!isEmpty()) {
			p->next = head;
			head = p;
		}
		else {
			head = p;
		}
		currentSize++;
	}
};

bool symmetry(int* arr, int n) {
	int midIndex = (n % 2 == 0 ? n / 2 - 1 : n / 2);
	Stack<int> s;
	for (int i = 0; i <= midIndex; i++)
	{
		s.push(arr[i]);
	}
	for (int i = n / 2; i < n; i++)
	{
		if (s.top() != arr[i]) {
			return false;
		}
		s.pop();
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