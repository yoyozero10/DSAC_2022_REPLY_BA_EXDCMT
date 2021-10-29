/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

template<class T> class Node {
public:
	T data;
	Node<T>* next;

	Node(T data) {
		next = nullptr;
		this->data = data;
	}
};

template<class T> class CircularQueue {
	int currentSize;
	Node<T>* head;
	Node<T>* tail;
public:
	CircularQueue() {
		head = tail = nullptr;
		currentSize = 0;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	int size() {
		return currentSize;
	}

	bool push(T e) {
		Node<T>* p = new Node<T>(e);
		if (isEmpty()) {
			head = tail = p;
		}
		else {
			tail->next = p;
			p->next = head; 
			tail = p; // update tail
		}
		currentSize++;
		return true;
	}

	T* pop() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			Node<T>* r = head;
			head = head->next;
			tail->next = head;
			currentSize--;
			return &(r->data);
		}
	}

	T* front() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			return &(head->data);
		}
	}

	T* back() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			return &(tail->data);
		}
	}

	void showNodes() {
		if (isEmpty()) {
			cout << "Queue rong." << endl;
		}
		else {
			Node<T>* p = head;
			while (p->next != head) {
				cout << p->data << "->";
				p = p->next;
			}
			cout << p->data << "->null\n";
		}
	}
};


int main()
{
	CircularQueue<long> queue;
	int choice;
	do
	{
		cout << "<=================== OPTIONS ===================>\n";
		cout << "1. Them moi phan tu vao hang doi.\n";
		cout << "2. Xoa va tra ve phan tu dau hang doi.\n";
		cout << "3. Lay phan tu dau hang doi.\n";
		cout << "4. Lay so phan tu hien co trong hang doi.\n";
		cout << "5. Hien thi cac phan tu trong hang doi.\n";
		cout << "6. Kiem tra hang doi co rong khong.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Cam on ban da su dung dich vu ==>\n";
			break;
		case 1:
		{
			int x;
			cout << "Nhap gia tri cua phan tu moi: ";
			cin >> x;
			queue.push(x);
			break;
		}
		case 2:
			if (!queue.isEmpty()) {
				cout << "Phan tu bi xoa khoi queue: " << *(queue.pop()) << endl;
			}
			else {
				cout << "Hang doi rong.\n";
			}
			break;
		case 3:
			if (!queue.isEmpty()) {
				cout << "Phan tu dau hang doi: " << *(queue.front()) << endl;
			}
			else {
				cout << "Hang doi rong.\n";
			}
			break;
		case 4:
			cout << "So phan tu hien co trong hang doi: " << queue.size() << endl;
			break;
		case 5:
			queue.showNodes();
			break;
		case 6:
			cout << boolalpha << "Hang doi rong? " << queue.isEmpty() << endl;
			break;
		default:
			cout << "Sai chuc nang. Vui long chon lai!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}