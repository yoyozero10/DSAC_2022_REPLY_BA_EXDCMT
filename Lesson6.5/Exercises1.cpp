/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
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
	
	bool search(T data) {
		return search(root, data);
	}

	bool search(Node<T>* r, T data) {
		if (r != nullptr) {
			if (r->data == data) { // nếu tìm thấy
				return true;
			}
			else if (r->data > data) { // tìm bên cây con trái
				return search(r->left, data);
			}
			else {
				return search(r->right, data); // tìm bên cây con phải
			}
		}
		return false; // không tìm thấy
	}
};

int main() {
	BinarySearchTree<int> tree;
	int choice;
	do {
		cout << "<=============== MENU ===============>\n";
		cout << "1. Them moi mot node vao cay.\n";
		cout << "2. Duyet cay in-order.\n";
		cout << "3. Tim x co trong cay khong.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Xin moi chon: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== CAM ON BAN DA SU DUNG DICH VU ==>\n";
			break;
		case 1:
		{
			int value;
			cout << "Nhap gia tri can them moi: ";
			cin >> value;
			tree.add(value);
			break;
		}
		case 2: 
		{
			cout << "\n--------------------------------------\n";
			cout << "Cac phan tu trong cay: \n";
			tree.inOrder();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "\n--------------------------------------\n";
			cout << "Nhap x = ";
			int x;
			cin >> x;
			if (tree.search(x)) {
				cout << x << " ton tai trong cay.\n";
			}
			else {
				cout << x << " khong ton tai trong cay.\n";
			}
			break;
		}
		default:
			cout << "Nhap sai chuc nang. Vui long thu lai!\n";
			break;
		}
	} while (choice != 0);
	
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