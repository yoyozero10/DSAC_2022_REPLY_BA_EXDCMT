/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T> class Node {
public:
	Node<T>* left;
	Node<T>* right;
	T data;
	int occ; // số lần xuất hiện

	Node(T data) {
		this->data = data;
		occ = 1;
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
		if (r->data == value) {
			r->occ++; // tăng biến đếm lên
		}
		else if (value > r->data) {
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

	void listedElements() {
		listedElements(root);
	}

	void listedElements(Node<T>* r) {
		if (r != nullptr) {
			listedElements(r->left);
			cout << r->data << '-' << r->occ << endl;
			listedElements(r->right);
		}
	}

	void search(int occurrent) {
		search(root, occurrent);
	}

	void search(Node<T>* r, int occurrent) {
		if (r != nullptr) {
			if (r->occ == occurrent) { // nếu tìm thấy
				cout << r->data << ' ';
			}
			search(r->left, occurrent); // tiếp tục tìm bên trái
			search(r->right, occurrent); // tìm bên phải
		}
	}

	int findMaxOcc() {
		int maxOcc = 1;
		findMaxOcc(root, maxOcc);
		return maxOcc;
	}

	void findMaxOcc(Node<T>* r, int& maxOcc) {
		if (r != nullptr) {
			findMaxOcc(r->left, maxOcc);
			if (r->occ > maxOcc) {
				maxOcc = r->occ;
			}
			findMaxOcc(r->right, maxOcc);
		}
	}

	int findMinOcc() {
		int minOcc = findMaxOcc();
		findMinOcc(root, minOcc);
		return minOcc;
	}

	void findMinOcc(Node<T>* r, int& minOcc) {
		if (r != nullptr) {
			findMinOcc(r->left, minOcc);
			if (r->occ < minOcc) {
				minOcc = r->occ;
			}
			findMinOcc(r->right, minOcc);
		}
	}
};

int main() {
	BinarySearchTree<string> tree;
	string str;
	cout << "Nhap vao chuoi ki tu: ";
	getline(cin, str);
	stringstream ss(str);
	string word;
	while (ss >> word) {
		tree.add(word);
	}
	cout << "------------------------------------\n";
	cout << "Danh sach cac tu: \n";
	tree.inOrder();
	cout << "\n------------------------------------\n";
	cout << "Danh sach tu va so lan xuat hien: \n";
	tree.listedElements();
	cout << "------------------------------------\n";
	cout << "Cac tu co so lan xuat hien nhieu nhat:\n";
	int max = tree.findMaxOcc();
	tree.search(max);
	cout << "\n------------------------------------\n";
	cout << "Cac tu co so lan xuat hien it nhat:\n";
	int min = tree.findMinOcc();
	tree.search(min);
	cout << "\n------------------------------------\n";
	cout << "Nhap k = ";
	int k;
	cin >> k;
	cout << "Cac tu co so lan xuat hien = " << k << ": \n";
	tree.search(k);
	return 0;
}