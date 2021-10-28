/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
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

void infixToPostfix(string input) {
	stack<char> stack;
	int size = input.length();
	for (int i = 0; i < size; i++)
	{
		if (input[i] == ' ') {
			continue;
		}
		else {
			if (input[i] == '+' || input[i] == '-' || 
				input[i] == '*' || input[i] == '/' || input[i] == '^') {
				while (!stack.empty() && 
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
	while (!stack.empty()) {
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