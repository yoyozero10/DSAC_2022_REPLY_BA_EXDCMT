/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int priorityLevel(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '/' || c == '*') {
		return 2;
	}
	else if (c == '^') {
		return 3;
	}
	else {
		return 0;
	}
}

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

void infixToPostfix(string input) {
	Stack<char> stack;
	int size = input.length();
	for (int i = 0; i < size; i++)
	{
		if (input[i] == ' ') {
			continue;
		}
		else {
			if (input[i] == '+' || input[i] == '-' || 
				input[i] == '*' || input[i] == '/' || input[i] == '^') {
				while (!stack.isEmpty() && 
					priorityLevel(input[i]) <= priorityLevel(stack.top())) {
					cout << stack.top() << ' ';
					stack.pop();
				}
				stack.push(input[i]);
			}
			else if (input[i] == ')') {
				char op = stack.top();
				stack.pop();
				while (!(op == '(')) {
					cout << op << ' ';
					op = stack.top();
					stack.pop();
				}
			}
			else if (input[i] == '(') {
				stack.push(input[i]);
			}
			else {
				int number = 0;
				int c = input[i] - 48;
				while (c >= 0 && c <= 9) {
					i++;
					number = number * 10 + c;
					c = input[i] - 48;
				}
				i--;
				cout << number << " ";
			}
		}
	}
	// pop cac phan tu con lai cua stack
	while (!stack.isEmpty()) {
		char op = stack.top();
		stack.pop();
		if (op != '(') {
			cout << op << ' ';
		}
	}
}

int main() {
	int t;
	ifstream ifs("input4.txt");
	if (ifs) {
		ifs >> t;
		ifs.ignore();
		while (t--) {
			string str;
			getline(ifs, str);
			infixToPostfix(str);
			cout << endl;
		}
		ifs.close();
	}
	return 0;
}