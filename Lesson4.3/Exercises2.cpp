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
	Stack<string> stack;
	splitWord(stack, str);
	printResult(stack);
	return 0;
}