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

	void sort(bool isReversed = false) {
		if (isReversed) {
			sortDESC();
		}
		else {
			sortASC();
		}
	}

	void sortASC() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data < p->data) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}

	void sortDESC() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data > p->data) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
};

int main() {
	LinkedList<string> friends;
	friends.addTail("Mai");
	friends.addTail("Lan");
	friends.addTail("Huong");
	friends.addTail("Hoa");
	friends.addTail("Ha");
	friends.addTail("Hoan");
	friends.addTail("Duyen");
	friends.addTail("Khanh");
	friends.addTail("Thuy");
	cout << "<== Truoc khi sap xep ==>\n";
	friends.showList();
	friends.sort();
	cout << "<== Sau khi sap xep danh sach a-z ==>\n";
	friends.showList();
	friends.sort(true);
	cout << "<== Sau khi sap xep danh sach z-a ==>\n";
	friends.showList();
}