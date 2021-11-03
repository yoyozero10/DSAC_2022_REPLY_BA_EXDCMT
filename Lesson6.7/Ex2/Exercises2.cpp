/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

	// hàm thêm một node mới vào cây BST
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
	// duyệt in-order
	void inOrder() {
		if (root != nullptr) {
			inOrder(root);
			cout << "\n";
		}
		else {
			cout << "Cay rong!\n";
		}
	}

	void inOrder(Node<T>* r) {
		if (r != nullptr) {
			inOrder(r->left);
			cout << r->data << ' ';
			inOrder(r->right);
		}
	}

	void remove(T x) {
		root = remove(root, x);
	}

	Node<T>* remove(Node<T>* r, T x) {
		if (r == nullptr) {
			cout << "Gia tri can xoa khong ton tai.\n";
			return nullptr;
		}
		if (x < r->data) {
			r->left = remove(r->left, x);
		}
		else if (x > r->data) {
			r->right = remove(r->right, x);
		}
		else {
			if (r->left == nullptr) {
				r = r->right;
			}
			else if (r->right == nullptr) {
				r = r->left;
			}
			else {
				r->data = findMinNode(r->right);
				r->right = remove(r->right, r->data);
			}
		}
		return r;
	}

	// tìm node nhỏ nhất của cây con phải
	T findMinNode(Node<T>* r) {
		while (r->left != nullptr) {
			r = r->left;
		}
		return r->data;
	}

	// tìm các node lá
	void findLeafNodes(vector<T>& v) {
		findLeafNodes(root, v);
	}

	void findLeafNodes(Node<T>* r, vector<T>& v) {
		if (r != nullptr) {
			findLeafNodes(r->left, v);
			if (r->left == nullptr && r->right == nullptr) {
				v.push_back(r->data);
			}
			findLeafNodes(r->right, v);
		}
	}
};

template<class T> void readData(BinarySearchTree<T>& tree, string fileName) {
	ifstream ifs(fileName);
	if (ifs) {
		int numberOfNode;
		ifs >> numberOfNode;
		int x;
		for (int i = 0; i < numberOfNode; i++)
		{
			ifs >> x;
			tree.add(x);
		}
		ifs.close();
		cout << "=== Doc file thanh cong! ===\n";
	}
	else {
		cout << "=== File khong ton tai. Vui long kiem tra lai. ===\n";
	}
}

int main() {
	BinarySearchTree<int> tree;
	string fileName;
	cout << "Nhap ten file(vi du: input.txt): ";
	cin >> fileName;
	readData(tree, fileName);
	cout << "Danh sach cac node truoc khi xoa: \n";
	tree.inOrder();
	cout << "========================================\n";
	vector<int> leafNodes;
	tree.findLeafNodes(leafNodes);
	cout << "Danh sach node la: ";
	for (auto e : leafNodes) {
		cout << e << ' ';
		tree.remove(e);
	}
	cout << "\n========================================\n";
	cout << "Danh sach cac node sau khi xoa: \n";

	tree.inOrder();

	return 0;
}
// Hinh anh cay nhi phan tim kiem trong file input2.txt
//				 150
//			  /      \
//			10       200
//		     \      /   \
//           23   180   255
//            \    /    / \
//		      54  160 234 500
//            / \
//			50	100
//          /    /
//        40    68
//               \
//               97