/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <fstream>
#include <string>
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
	// duyệt in-order
	void inOrder() {
		inOrder(root);
		cout << "\n";
	}

	void inOrder(Node<T>* r) {
		if (r != nullptr) {
			inOrder(r->left);
			cout << r->data << ' ';
			inOrder(r->right);
		}
	}

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
		else if (r->data > key) {
			return search(r->left, key);
		}
		else {
			return search(r->right, key);
		}
	}
	// đếm tổng số node
	int totalNode() {
		return totalNode(root);
	}

	int totalNode(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		return 1 + totalNode(r->left) + totalNode(r->right);
	}
	// đếm node lá
	int leafNodes() {
		return leafNodes(root);
	}

	int leafNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right == nullptr) {
			return 1;
		}
		return leafNodes(r->left) + leafNodes(r->right);
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
	int choice;
	BinarySearchTree<int> tree;
	do
	{
		cout << "================== OPTIONS ==================\n";
		cout << "1. Doc file.\n";
		cout << "2. Hien thi cac phan tu trong cay.\n";
		cout << "3. Tim node x xem co xuat hien trong cay hay khong.\n";
		cout << "4. Cho biet so luong node tren cay.\n";
		cout << "5. Cho biet so luong node la tren cay.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "=== Ket thuc chuong trinh ===\n";
			break;
		case 1:
		{
			string fileName;
			cout << "Nhap ten file(vi du: input.txt): ";
			cin >> fileName;
			readData(tree, fileName);
			break;
		}
		case 2:
			cout << "Cac phan tu trong cay: ";
			tree.inOrder();
			break;
		case 3: {
			int x;
			cout << "Nhap x = ";
			cin >> x;
			cout << x << " co ton tai trong cay?" << boolalpha << tree.search(x) << endl;
			break;
		}
		case 4:
			cout << "Tong so node tren cay: " << tree.totalNode() << endl;
			break;
		case 5:
			cout << "Tong so node la tren cay: " << tree.leafNodes() << endl;
			break;
		default:
			cout << "Sai tuy chon. Vui long nhap lai!\n";
			break;
		}
	} while (choice != 0);

}
// Hinh anh cay nhi phan tim kiem trong file input.txt
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