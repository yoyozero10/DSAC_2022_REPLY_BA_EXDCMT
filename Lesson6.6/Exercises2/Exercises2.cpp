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

	// liệt kê node lá
	void printLeafNodes() {
		printLeafNodes(root);
		cout << endl;
	}

	void printLeafNodes(Node<T>* r) {
		if (r != nullptr) {
			printLeafNodes(r->left);
			if (r->left == nullptr && r->right == nullptr) {
				cout << r->data << ' ';
			}
			printLeafNodes(r->right);
		}
	}

	// liệt kê node cành trên cây
	void printBranchNodes() {
		printBranchNodes(root);
		cout << endl;
	}

	void printBranchNodes(Node<T>* r) {
		if (r != nullptr) {
			printBranchNodes(r->left);
			if (r->left != nullptr || r->right != nullptr) {
				cout << r->data << ' ';
			}
			printBranchNodes(r->right);
		}
	}

	// liệt kê các node có 2 cây con
	void printTwoSubTreeNodes() {
		printTwoSubTreeNodes(root);
		cout << endl;
	}

	void printTwoSubTreeNodes(Node<T>* r) {
		if (r != nullptr) {
			printTwoSubTreeNodes(r->left);
			if (r->left != nullptr && r->right != nullptr) {
				cout << r->data << ' ';
			}
			printTwoSubTreeNodes(r->right);
		}
	}

	// liệt kê các node có 1 cây con
	void printOneSubTreeNodes() {
		printOneSubTreeNodes(root);
		cout << endl;
	}

	void printOneSubTreeNodes(Node<T>* r) {
		if (r != nullptr) {
			printOneSubTreeNodes(r->left);
			if ((r->left != nullptr && r->right == nullptr)
				|| (r->right != nullptr && r->left == nullptr)) {
				cout << r->data << ' ';
			}
			printOneSubTreeNodes(r->right);
		}
	}

	// Liệt kê các node chỉ có 1 cây con trái
	void printOnlyOneLeftSubTreeNodes() {
		printOnlyOneLeftSubTreeNodes(root);
		cout << endl;
	}

	void printOnlyOneLeftSubTreeNodes(Node<T>* r) {
		if (r != nullptr) {
			printOnlyOneLeftSubTreeNodes(r->left);
			if (r->left != nullptr && r->right == nullptr) {
				cout << r->data << ' ';
			}
			printOnlyOneLeftSubTreeNodes(r->right);
		}
	}

	// Liệt kê các node chỉ có 1 cây con phải
	void printOnlyOneRightSubTreeNodes() {
		printOnlyOneRightSubTreeNodes(root);
		cout << endl;
	}

	void printOnlyOneRightSubTreeNodes(Node<T>* r) {
		if (r != nullptr) {
			printOnlyOneRightSubTreeNodes(r->left);
			if (r->left == nullptr && r->right != nullptr) {
				cout << r->data << ' ';
			}
			printOnlyOneRightSubTreeNodes(r->right);
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
	int choice;
	BinarySearchTree<int> tree;
	do
	{
		cout << "================== OPTIONS ==================\n";
		cout << "01. Doc file.\n";
		cout << "02. Hien thi cac phan tu trong cay.\n";
		cout << "03. Liet ke cac node la tren cay.\n";
		cout << "04. Liet ke cac node canh tren cay.\n";
		cout << "05. Liet ke cac node co 2 cay con.\n";
		cout << "06. Liet ke cac node co 1 cay con.\n";
		cout << "07. Liet ke cac node chi co 1 cay con trai.\n";
		cout << "08. Liet ke cac node chi co 1 cay con phai.\n";
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
		case 3:
			cout << "Danh sach cac node la tren cay: " << endl;
			tree.printLeafNodes();
			break;
		case 4:
			cout << "Danh sach cac node canh tren cay: "<< endl;
			tree.printBranchNodes();
			break;
		case 5:
			cout << "Danh sach cac node co 2 cay con: " << endl;
			tree.printTwoSubTreeNodes();
			break;
		case 6:
			cout << "Danh sach cac node co 1 cay con: " << endl;
			tree.printOneSubTreeNodes();
			break;
		case 7:
			cout << "Danh sach cac node chi co 1 cay con trai: " << endl;
			tree.printOnlyOneLeftSubTreeNodes();
			break;
		case 8:
			cout << "Danh sach cac node chi co 1 cay con phai: " << endl;
			tree.printOnlyOneRightSubTreeNodes();
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