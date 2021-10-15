#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

// khai báo nguyên mẫu hàm
int precedence(const char op);
vector<string> infixToPostfix(vector<string> str);
bool isOperator(string input);
double calculateResult(vector<string> words);
double makeResult(double a, double b, char e);

int main() {
	ifstream ifs("input3.txt");
	if (ifs) {
		int t;
		ifs >> t;
		ifs.ignore();
		int testCount = 1;
		while (t-- > 0) {
			string str;
			vector<string> words;
			int numOfWord = 0;
			getline(ifs, str);
			string word;
			stringstream ss(str);
			while (ss >> word) {
				words.push_back(word);
			}
			cout << "Test " << testCount++ << ": \n";
			auto postfix = infixToPostfix(words);
			auto result = calculateResult(postfix);
			cout << setprecision(2) << fixed << result << endl;
		}
		ifs.close();
	}
	return 0;
}

/**
	 * Phương thức kiểm tra thứ tự ưu tiên của toán tử.
	 *
	 * @param operator toán tử cần lấy thứ tự ưu tiên.
	 * @return thứ tự ưu tiên của toán tử đang xét trong đề bài.
	 */
int precedence(const char op) {
	int priority = 0;
	switch (op) {
	case '+':
	case '-':
		priority = 1;
		break;
	case '*':
	case '/':
		priority = 2;
		break;
	case '^':
		priority = 3;
		break;
	default:
		break;
	};
	return priority;
}

/**
 * Phương thức chuyển đổi từ trung tố sang hậu tố.
 *
 * @param str chuỗi chứa biểu thức trung tố.
 * @return biểu thức hậu tố tương ứng.
 */
vector<string> infixToPostfix(vector<string> str) {
	vector<string> result;
	stack<string> stack;
	for (string e : str) {
		if (precedence(e.at(0)) > 0) { // e là toán tử
			while (!stack.empty() && precedence(e.at(0)) <= precedence(stack.top().at(0))) {
				result.push_back(stack.top());
				stack.pop();
			}
			stack.push(e);
		}
		else if (e.compare(")") == 0) { // là dấu ngoặc đóng
			string op = stack.top();
			stack.pop();
			while (op.compare("(") != 0) {
				result.push_back(op);
				op = stack.top();
				stack.pop();
			}

		}
		else if (e.compare("(") == 0) { // là dấu ngoặc mở
			stack.push(e);
		}
		else { // nếu là toán hạng, push vào stack
			result.push_back(e);
		}
	}
	// pop các phần tử còn lại của stack
	while (!stack.empty()) {
		string op = stack.top();
		stack.pop();
		if (op.compare("(") != 0) {
			result.push_back(op);
		}
	}
	return result;
}

bool isOperator(string input) {
	return input.compare("+") == 0 || input.compare("-") == 0
		|| input.compare("*") == 0 || input.compare("/") == 0
		|| input.compare("^") == 0;
}

double calculateResult(vector<string> words) {
	double result;
	stack<string> s;
	for (string e : words) {
		if (isOperator(e)) {
			double b = stod(s.top());
			s.pop();
			double a = stod(s.top());
			s.pop();
			result = makeResult(a, b, e.at(0));
			s.push(to_string(result));
		}
		else {
			s.push(e);
		}
	}
	return stod(s.top());
}

/**
 * Phương thức tính toán kết quả a operator b.
 *
 * @param a toán hạng đầu
 * @param b toán hạng sau
 * @param e toán tử
 * @return giá trị đạt được
 */
double makeResult(double a, double b, char e) {
	double result = 0;
	switch (e) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '^':
		result = pow(a, b);
	default:
		break;
	};
	return result;
}