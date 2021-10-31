/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <exception>
using namespace std;

template<class T> class Node {
public:
	T data;
	int priority; // thứ tự ưu tiên
	Node<T>* next;

	Node(T data, int priority) {
		this->priority = priority;
		this->data = data;
		this->next = nullptr;
	}
};


template<class T> class PriorityQueue {
private:
	Node<T>* head;
	Node<T>* tail;
	int currentSize;
public:
	PriorityQueue() {
		currentSize = 0;
		head = nullptr;
		tail = nullptr;
	}
	// kiểm tra hàng đợi rỗng
	bool isEmpty() {
		return head == nullptr;
	}
	// thêm phần tử vào cuối hàng đợi
	bool push(T data, int priority) {
		Node<T>* p = new Node<T>(data, priority);
		if (p == nullptr) {
			return false;
		}
		if (isEmpty()) {
			head = tail = p;
		}
		else if (priority > head->priority) {
			p->next = head;
			head = p;
		}
		else {
			Node<T>* r = head;
			for (Node<T>* q = head->next; q != nullptr; q = q->next)
			{
				if (q->priority < priority) {
					break;
				}
				r = q;
			}
			p->next = r->next;
			r->next = p;
			if (r == tail) {
				tail = p;
			}
		}
		currentSize++;
		return true;
	}
	// lấy phần tử đầu hàng đợi
	Node<T> front() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			return *head;
		}
	}
	// lấy phần tử cuối hàng đợi
	Node<T> back() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			return *tail;
		}
	}
	// xóa và trả về phần tử đầu hàng đợi
	Node<T> pop() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			Node<T>* r = head;
			head = head->next;
			currentSize--;
			Node<T> p = *r;
			delete r;
			return p;
		}
	}
	// trả về số phần tử hiện thời trong hàng đợi
	int size() {
		return currentSize;
	}
	// liệt kê các phần tử có mức ưu tiên nhỏ nhất
	void minPriorityElements() {
		if (isEmpty()) {
			cout << "Queue rong.\n";
		}
		else {
			int minPriority = tail->priority;
			cout << "Muc uu tien: " << minPriority << endl;
			cout << "Danh sach phan tu co muc uu tien nho nhat: \n";
			for (Node<T>* p = head; p != nullptr; p = p->next)
			{
				if (p->priority == minPriority) {
					cout << p->data << " ";
				}
			}
			cout << endl;
		}
	}
	// hiển thị các phần tử cùng với mức ưu tiên của nó
	void printElements() {
		for (Node<T>* p = head; p != nullptr; p = p->next)
		{
			cout << "[" << p->data << " - " << p->priority << "]\n";
		}
	}
};

int main() {
	PriorityQueue<int> queue;
	int choice;
	do
	{
		cout << "<=============== MENU ===============>\n";
		cout << "1. Them moi phan tu vao hang doi.\n";
		cout << "2. Xoa va tra ve phan tu dau hang doi.\n";
		cout << "3. Lay phan tu dau hang doi.\n";
		cout << "4. Lay phan tu cuoi hang doi.\n";
		cout << "5. Lay so phan tu hien co trong hang doi.\n";
		cout << "6. Hien thi cac phan tu cua hang doi.\n";
		cout << "7. Kiem tra queue rong khong.\n";
		cout << "8. Liet ke cac phan tu co muc uu tien nho nhat.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Xin chao va cam on quy vi da su dung dich vu ==>\n";
			break;
		case 1:
		{
			int x, priority;
			cout << "Nhap gia tri can them moi: ";
			cin >> x;
			cout << "Nhap thu tu uu tien: ";
			cin >> priority;
			queue.push(x, priority);
			break;
		}
		case 2: 
		{
			try {
				cout << "Phan tu vua xoa: " << queue.pop().data << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 3:
		{
			try {
				cout << "Phan tu dau hang doi: " << queue.front().data << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 4:
		{
			try {
				cout << "Phan tu cuoi hang doi: " << queue.back().data << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 5:
			cout << "So phan tu hien co trong hang doi: " << queue.size() << endl;
			break;
		case 6:
			cout << "Cac phan tu trong hang doi: \n";
			queue.printElements();
			break;
		case 7:
			cout << "Queue rong? " << boolalpha << queue.isEmpty() << endl;
			break;
		case 8:
			queue.minPriorityElements();
			break;
		default:
			cout << "Sai chuc nang. Vui long chon lai.\n";
			break;
		}
	} while (choice != 0);
	return 0;
}