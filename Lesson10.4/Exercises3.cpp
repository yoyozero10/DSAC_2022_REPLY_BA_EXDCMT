/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

template<class T> class Node {
public:
	Node<T>* left;
	Node<T>* right;
	T data;

	Node(T data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

template<class T> class BinarySearchTree {
	Node<T>* root;
public:
	BinarySearchTree() {
		root = nullptr;
	}

	void add(T value) {
		root = add(root, value);
	}

	Node<T>* add(Node<T>* r, T value) {
		if (r == nullptr) {
			return new Node<T>(value);
		}
		if (value >= r->data) {
			r->right = add(r->right, value);
		}
		else {
			r->left = add(r->left, value);
		}
		return r;
	}
	// duyệt theo thứ tự in-order
	void inOrder() {
		inOrder(root);
	}

	void inOrder(Node<T>* r) {
		if (r != nullptr) {			// node hiện thời còn khác null
			inOrder(r->left);		// duyệt cây con trái
			cout << r->data << " "; // hiển thị data node cha
			inOrder(r->right);		// duyệt cây con phải
		}
	}
	// duyệt theo thứ tự pre-order
	void preOrder() {
		preOrder(root);
	}

	void preOrder(Node<T>* r) {
		if (r != nullptr) {			// node hiện thời còn khác null
			cout << r->data << ' ';	// hiển thị data node cha
			preOrder(r->left);		// duyệt cây con trái
			preOrder(r->right);		// duyệt cây con phải
		}
	}
	// duyệt theo thứ tự post-order
	void postOrder() {
		postOrder(root);
	}

	void postOrder(Node<T>* r) {
		if (r != nullptr) {			// node hiện thời còn khác null
			postOrder(r->left);		// duyệt cây con trái
			postOrder(r->right);	// duyệt cây con phải
			cout << r->data << ' ';	// hiển thị data node cha
		}
	}
	// tìm kiếm
	bool search(T key) {
		return search(root, key);
	}

	bool search(Node<T>* r, T key) {
		if (r == nullptr) {
			return false;
		}
		if (r->data == key) {
			return true;
		}
		if (r->data < key) {
			return search(r->right, key);
		}
		else {
			return search(r->left, key);
		}
		return false;
	}

	int countX(T x) {
		return countX(root, x);
	}

	int countX(Node<T>* r, T x) {
		if (r == nullptr) {
			return 0;
		}
		if (r->data == x) {
			return 1 + countX(r->left, x) + countX(r->right, x);
		}
		else if (r->data < x) {
			return countX(r->right, x);
		}
		else {
			return countX(r->left, x);
		}
	}
};

// hàm tách từ trong chuỗi string
void split(string str, BinarySearchTree<string>& tree) {
	stringstream ss(str);
	string s;
	while (ss >> s) {
		tree.add(s);
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore(); // loại bỏ bộ đệm
	for (int i = 1; i <= t; i++) {
		BinarySearchTree<string> tree;
		string inputStr;
		string x;
		cin >> x;
		cin.ignore(); // loại bỏ bộ nhớ đệm
		getline(cin, inputStr);
		transform(inputStr.begin(), inputStr.end(), inputStr.begin(),
			[](unsigned char c) { return tolower(c); });
		transform(x.begin(), x.end(), x.begin(),
			[](unsigned char c) { return tolower(c); });
		split(inputStr, tree);
		cout << tree.countX(x) << endl;
	}
	return 0;
}