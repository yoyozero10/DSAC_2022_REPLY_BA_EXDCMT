#include <iostream>
using namespace std;

template<class T> class Node { // sử dụng lớp template
public:
	T data; // dữ liệu của node hiện tại
	Node<T>* next; // con trỏ trỏ tới node kế tiếp
	Node<T>* prev; // con trỏ trỏ tới node liền trước
	Node(T data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->prev = nullptr; // khởi tạo mặc định khi tạo node
		this->data = data; // gán giá trị của data cho node
	}
};

template<class T> class LinkedList {
private:
	Node<T>* head; // con trỏ trỏ đến node đầu tiên trong danh sách
	Node<T>* tail; // con trỏ trỏ tới node cuối của danh sách
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	// thêm node vào đầu danh sách liên kết đôi
	void add(T data) {
		Node<T>* p = new Node<T>(data); // tạo node mới p
		if (isEmpty()) { // kiểm tra xem danh sách rỗng không
			head = tail = p; // gán giá trị cho head, tail
		}
		else { // nếu danh sách không rỗng
			p->next = head; // cập nhật node next của p
			head->prev = p; // cập nhật prev của head cũ
			head = p; // cập nhật lại node head
		}
	}
	// thêm node vào cuối danh sách liên kết đôi
	void addTail(T data) { // chèn node vào cuối danh sách liên kết
		Node<T>* p = new Node<T>(data); // tạo node mới p
		if (!isEmpty()) {
			tail->next = p; // cập nhật node next của tail
			p->prev = tail; // cập nhật node prev của p
			tail = p; // cập nhật lại tail
		}
		else {
			head = tail = p; // gán head, tail cùng bằng p
		}
	}

	void showList() { // hàm hiển thị danh sách liên kết
		Node<T>* p = head; // khởi đầu từ node head
		while (p != nullptr) // lặp chừng nào p chưa null
		{
			cout << p->data << "->"; // hiển thị data của p
			p = p->next; // cập nhật p
		}
		cout << "null" << endl;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	bool remove(T data) {
		if (isEmpty()) {
			return false;
		}
		Node<T>* x = head;
		Node<T>* prevX = head;
		while (x != nullptr) {
			if (x->data == data) {
				break;
			}
			prevX = x;
			x = x->next;
		}
		if (x == head) {
			return removeHead();
		}
		else if (x == tail) {
			return removeTail(prevX);
		}
		else if (x != nullptr) {
			Node<T>* r = x;
			prevX->next = x->next;
			x = x->next;
			if (x != nullptr) {
				x->prev = prevX;
			}
			delete r;
			return true;
		}
		else {
			return false;
		}
	}

	bool removeHead() {
		Node<T>* r = head;
		if (head->next != nullptr) {
			head->next->prev = nullptr;
		}
		head = head->next;
		delete r;
		return true;
	}

	bool removeTail(Node<T>* prevX) {
		Node<T>* r = tail;
		if (prevX != nullptr) {
			prevX->next = nullptr;
		}
		tail = prevX;
		delete r;
		return true;
	}
};

int main() {
	LinkedList<string> list;
	list.addTail("Khanh");
	list.addTail("Hi");
	list.addTail("Mai");
	list.addTail("Nga");
	list.addTail("Oanh");
	list.addTail("Huong");
	cout << "Danh sach goc: \n";
	list.showList();
	cout << "Sau khi xoa node dau dslk: \n";
	list.remove("Khanh");
	list.showList();
	cout << "Sau khi xoa node cuoi dslk: \n";
	list.remove("Huong");
	list.showList();
	cout << "Sau khi xoa node \"Nga\" dslk: \n";
	list.remove("Nga");
	list.showList();
}