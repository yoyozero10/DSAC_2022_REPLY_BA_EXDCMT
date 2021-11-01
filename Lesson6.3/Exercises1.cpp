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
	// duyệt pre-order
	void preOrder() {
		preOrder(root);
	}

	void preOrder(Node<T>* r) {
		if (r != nullptr) {
			cout << r->data << ' ';
			preOrder(r->left);
			preOrder(r->right);
		}
	}
	// duyệt in-order
	void inOrder() {
		inOrder(root);
	}

	void inOrder(Node<T>* r) {
		if (r != nullptr) {
			inOrder(r->left);
			cout << r->data << ' ';
			inOrder(r->right);
		}
	}
	// duyệt theo thứ tự giảm dần giá trị
	void inOrderRevert() {
		inOrderRevert(root);
	}
	// duyệt theo thứ tự giảm dần
	void inOrderRevert(Node<T>* r) {
		if (r != nullptr) {
			inOrderRevert(r->right);
			cout << r->data << ' ';
			inOrderRevert(r->left);
		}
	}
	
	void LRN() {
		LRN(root);
	}

	void LRN(Node<T>* r) {
		if (r) {
			LRN(r->left);
			LRN(r->right);
			cout << r->data << ' ';
		}
	}

	void NLR() {
		NLR(root);
	}

	void NLR(Node<T>* r) {
		if (r) {
			cout << r->data << ' ';
			NLR(r->left);
			NLR(r->right);
		}
	}

	void RLN() {
		RLN(root);
	}

	void RLN(Node<T>* r) {
		if (r) {
			RLN(r->right);
			RLN(r->left);
			cout << r->data << ' ';
		}
	}

	void NRL() {
		NRL(root);
	}

	void NRL(Node<T>* r) {
		if (r) {
			cout << r->data << ' ';
			NRL(r->right);
			NRL(r->left);
		}
	}
};

int main() {
	BinarySearchTree<int> tree;
	tree.add(80);
	tree.add(50);
	tree.add(100);
	tree.add(30);
	tree.add(40);
	tree.add(20);
	tree.add(90);
	tree.add(120);
	tree.add(95);
	tree.add(130);
	tree.add(110);
	
	cout << "Cac phan tu trong cay theo thu tu tang dan:\n";
	tree.inOrder();
	cout << "\n--------------------------------------\n";
	cout << "Cac phan tu trong cay theo thu tu giam dan:\n";
	tree.inOrderRevert();
	cout << "\n--------------------------------------\n";
	cout << "Duyet cay LRN: \n";
	tree.LRN();
	cout << "\n--------------------------------------\n";
	cout << "Duyet cay RLN:\n";
	tree.RLN();
	cout << "\n--------------------------------------\n";
	cout << "Duyet cay NLR:\n";
	tree.NLR();
	cout << "\n--------------------------------------\n";
	cout << "Duyet cay NRL:\n";
	tree.NRL();
	return 0;
}
// hình ảnh cây nhị phân tìm kiếm trong ví dụ trên
//			     80
//			   /   \
//           50    100
//          /     /   \
//        30     90    120
//       / \      \    / \
//      20  40    95 110 130