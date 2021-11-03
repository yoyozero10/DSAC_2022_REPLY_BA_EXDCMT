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

	// đếm node cành trên cây
	int branchNodes() {
		return branchNodes(root);
	}

	int branchNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right == nullptr) {
			return 0;
		}
		return 1 + branchNodes(r->left) + branchNodes(r->right);
	}

	// đếm các node có 2 cây con
	int twoSubTreeNodes() {
		return twoSubTreeNodes(root);
	}

	int twoSubTreeNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left != nullptr && r->right != nullptr) {
			return 1 + twoSubTreeNodes(r->left) + twoSubTreeNodes(r->right);
		}
		return twoSubTreeNodes(r->left) + twoSubTreeNodes(r->right);
	}

	// đếm các node có 1 cây con
	int oneSubTreeNodes() {
		return oneSubTreeNodes(root);
	}

	int oneSubTreeNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if ((r->left != nullptr && r->right == nullptr) 
			|| (r->right != nullptr && r->left == nullptr)) {
			return 1 + oneSubTreeNodes(r->left) + oneSubTreeNodes(r->right);
		}
		return oneSubTreeNodes(r->left) + oneSubTreeNodes(r->right);
	}

	// đếm các node chỉ có 1 cây con trái
	int onlyOneLeftSubTreeNodes() {
		return onlyOneLeftSubTreeNodes(root);
	}

	int onlyOneLeftSubTreeNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left != nullptr && r->right == nullptr) {
			return 1 + onlyOneLeftSubTreeNodes(r->left) + onlyOneLeftSubTreeNodes(r->right);
		}
		return onlyOneLeftSubTreeNodes(r->left) + onlyOneLeftSubTreeNodes(r->right);
	}

	// đếm các node chỉ có 1 cây con phải
	int onlyOneRightSubTreeNodes() {
		return onlyOneRightSubTreeNodes(root);
	}

	int onlyOneRightSubTreeNodes(Node<T>* r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->left == nullptr && r->right != nullptr) {
			return 1 + onlyOneRightSubTreeNodes(r->left) + onlyOneRightSubTreeNodes(r->right);
		}
		return onlyOneRightSubTreeNodes(r->left) + onlyOneRightSubTreeNodes(r->right);
	}

	// xác định độ sâu của một node
	int deepOfX(T x) { 
		return levelOfNode(root, x, 0);
	}

	int levelOfNode(Node<T>* r, T x, int level) {
		if (r == nullptr) {
			return 0;
		}
		if (r->data == x) {
			return level;
		}
		if (r->data > x) {
			return levelOfNode(r->left, x, level + 1);
		}
		else {
			return levelOfNode(r->right, x, level + 1);
		}
	}

	// xác định độ cao của một node
	int height() {
		return height(root);
	}

	int height(Node<T>* r) {
		// cây rỗng hoặc node lá có chiều cao bằng 0
		if (r == nullptr || (r->left == NULL && r->right == nullptr)) {
			return 0;
		}
		else {
			int leftHeight = height(r->left); // xác định chiều cao cây con trái
			int rightHeight = height(r->right); // xác định chiều cao cây con phải
			return 1 + max(leftHeight, rightHeight); // trả về kết quả
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
		cout << "03. Tim node x xem co xuat hien trong cay hay khong.\n";
		cout << "04. Cho biet so luong node tren cay.\n";
		cout << "05. Cho biet so luong node la tren cay.\n";
		cout << "06. Cho biet so luong node canh tren cay.\n";
		cout << "07. Cho biet so luong node co 2 cay con.\n";
		cout << "08. Cho biet so luong node co 1 cay con.\n";
		cout << "09. Cho biet so luong node chi co 1 cay con trai.\n";
		cout << "10. Cho biet so luong node chi co 1 cay con phai.\n";
		cout << "11. Xac dinh do sau cua 1 node.\n";
		cout << "12. Xac dinh chieu cao cua cay.\n";
		cout << "13. Xac dinh bac cua mot node.\n";
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
		case 6:
			cout << "Tong so node canh tren cay: " << tree.branchNodes() << endl;
			break;
		case 7:
			cout << "Tong so node co 2 cay con: " << tree.twoSubTreeNodes() << endl;
			break;
		case 8:
			cout << "Tong so node co 1 cay con: " << tree.oneSubTreeNodes() << endl;
			break;
		case 9:
			cout << "Tong so node chi co 1 cay con trai: " << tree.onlyOneLeftSubTreeNodes() << endl;
			break;
		case 10:
			cout << "Tong so node chi co 1 cay con phai: " << tree.onlyOneRightSubTreeNodes() << endl;
			break;
		case 11: 
		{
			int x;
			cout << "Nhap node can xac dinh do sau: ";
			cin >> x;
			cout << "Do sau cua node '" << x << "' = " << tree.deepOfX(x) << endl;
			break;
		}
		case 12:
			cout << "Chieu cao cua cay: " << tree.height() << "\n";
			break;
		case 13:
		{
			int x;
			cout << "Nhap gia tri cua x: ";
			cin >> x;
			cout << "Bac cua node '" << x << "' = " << tree.levelOfNode(x) << endl;
			break;
		}
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