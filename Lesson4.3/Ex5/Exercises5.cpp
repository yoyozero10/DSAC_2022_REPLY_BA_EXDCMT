/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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

double calculateResult(double a, double b, char c) {
	double result = 0;
	if (c == '+') {
		result = a + b;
	}
	else if (c == '-') {
		result = a - b;
	}
	else if (c == '*') {
		result = a * b;
	}
	else if (c == '/') {
		result = a / b;
	}
	else if (c == '^') {
		result = pow(a, b);
	}
	return result;
}

double executePostfix(string str) {
	double result = 0;
	Stack<double> stack;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == ' ') {
			continue;
		} // nếu kí tự tại vị trí i là toán tử
		else if (str[i] > '9' || str[i] < '0') {
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			result = calculateResult(a, b, str[i]);
			stack.push(result);
		}
		else { // trường hợp còn lại, kí tự tại vị trí i là toán hạng
			double number = 0;
			char c = str[i] - '0';
			while (c >= 0 && c <= 9) {
				number = number * 10 + c;
				i++;
				c = str[i] - '0';
			}
			i--;
			stack.push(number);
		}
	}
	return stack.top();
}

int main() {
	int t;
	ifstream ifs("input5.txt");
	if (ifs) {
		ifs >> t;
		ifs.ignore(); // bỏ qua các kí tự thừa trước khi đọc dòng mới
		while (t--) {
			string str;
			getline(ifs, str);
			cout << executePostfix(str) << endl;
		}
		ifs.close();
	}
	return 0;
}