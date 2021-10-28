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