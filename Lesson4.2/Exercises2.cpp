/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
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

void splitWord(Stack<string>& stack, string str) {
	char data[500]; // new char[str.length() + 1];
	strcpy(data, str.c_str());
	char* p = strtok(data, " ");
	while (p != NULL) {
		stack.push(string(p));
		p = strtok(NULL, " ");
	}
	//delete[] data;
}

template<class T> void printResult(Stack<T>& s) {
	while (!s.isEmpty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	string str;
	getline(cin, str);
	Stack<string> stack(100);
	splitWord(stack, str);
	printResult(stack);
	return 0;
}