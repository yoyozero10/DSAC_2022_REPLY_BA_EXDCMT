/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
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
};

template<class T> void readData(BinarySearchTree<T>& tree, int size) {
	T x;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		tree.add(x);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		BinarySearchTree<float> tree;
		int n;
		float x;
		cin >> n >> x;
		readData(tree, n);
		cout << "Test " << i << ":\n";
		if (tree.search(x)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}