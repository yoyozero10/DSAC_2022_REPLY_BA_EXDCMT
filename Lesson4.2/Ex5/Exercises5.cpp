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
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			continue;
		} // nếu kí tự tại vị trí i là toán tử
		else if (str[i] > '9' || str[i] < '0') {
			double b = stack.pop();
			double a = stack.pop();
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
	return stack.pop();
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