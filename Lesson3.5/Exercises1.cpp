/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

template<class T> class Node { // sử dụng lớp template
public:
	T data; // dữ liệu của node hiện tại
	Node<T>* next; // con trỏ trỏ tới node kế tiếp

	Node(T data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
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

	void add(T data) {
		Node<T>* p = new Node<T>(data); // tạo node mới p
		if (isEmpty()) { // kiểm tra xem danh sách rỗng không
			head = tail = p; // gán giá trị cho head, tail
		}
		else { // nếu danh sách không rỗng
			p->next = head; // cập nhật node next của p
			head = p; // cập nhật lại node head
		}
	}

	// hàm xóa node và trả về true
	bool remove(T data) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return false;
		}
		Node<T>* x = head;
		Node<T>* prevX = head;
		while (x != nullptr) {
			if (x->data == data) {
				if (x == head) {
					return removeHead();
				}
				else if (x == tail) {
					return removeTail(prevX);
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node<T>* r = x;
					x = x->next;
					delete r;
					return true;
				}
			}
			prevX = x;
			x = x->next;
		}
		return false;
	}

	bool removeHead() {
		Node<T>* r = head;
		head = head->next;
		delete r;
		return true;
	}

	bool removeTail(Node<T>* prevX) {
		Node<T>* r = tail;
		prevX->next = nullptr;
		tail = prevX;
		delete r;
		return true;
	}

	void addTail(T data) { // chèn node vào cuối danh sách liên kết
		Node<T>* p = new Node<T>(data); // tạo node mới p
		if (!isEmpty()) {
			tail->next = p; // cập nhật node next của tail
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
};

int main() {
	LinkedList<string> list;
	// thêm vào đầu
	list.add("Thanh");

	// thêm vào cuối
	list.addTail("Khanh");
	list.addTail("Hai");
	list.addTail("Mai");
	list.addTail("Nga");
	list.addTail("Oanh");
	list.addTail("Huong");

	// hiển thị danh sách
	cout << "Danh sach goc: ";
	list.showList();

	// sau khi xóa
	cout << "Danh sach sau khi xoa: ";
	string key = "Khanh";
	list.remove(key);
	list.showList();
}