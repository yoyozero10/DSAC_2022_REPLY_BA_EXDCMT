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
#include <stack>
using namespace std;

void splitWord(stack<string>& stack, string str) {
	char data[500]; // new char[str.length() + 1];
	strcpy(data, str.c_str());
	char* p = strtok(data, " ");
	while (p != NULL) {
		stack.push(string(p));
		p = strtok(NULL, " ");
	}
	//delete[] data;
}

template<class T> void printResult(stack<T>& s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	string str;
	getline(cin, str);
	stack<string> stack;
	splitWord(stack, str);
	printResult(stack);
	return 0;
}