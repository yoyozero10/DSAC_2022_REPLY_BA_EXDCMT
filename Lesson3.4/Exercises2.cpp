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

	// hàm cập nhật thông tin của một node
	bool update(T data, T x) {
		if (isEmpty()) { // nếu danh sách rỗng
			return 0;
		}
		else { // ngược lại
			int counter = 0;
			Node<T>* nodeX = head; // bắt đầu từ node head
			while (nodeX != nullptr) { // tìm nodeX
				if (nodeX->data == x) { // nếu tìm thấy
					nodeX->data = data; // update node
					counter++; // kết thúc việc tìm kiếm
				}
				nodeX = nodeX->next; // chuyển tới node kế tiếp
			}
			return counter;
		}
	}

	// tìm node ở giữa danh sách liên kết
	// nếu cho 2 người cùng đi từ đầu đường đến cuối đường,
	// người thứ 1 mỗi lần đi chỉ bước 1 bước, người thứ 2 bước 2 bước.
	// khi người thứ 2 đến đích, người thứ 1 sẽ đến giữa đường.
	// giả định bước đi là như nhau.
	Node<T>* middle() {
		Node<T>* first = head;
		Node<T>* second = head;
		while (second != nullptr && second->next != nullptr && second->next != tail) {
			second = second->next->next; // đi 2 bước
			first = first->next; // đi 1 bước
		}
		return first; // node giữa danh sách
	}

	// thêm node vào sau node giữa danh sách
	void addAfterMid(T data) {
		if (isEmpty()) {
			add(data);
		}
		else {
			Node<T>* p = new Node<T>(data);
			Node<T>* mid = head;
			Node<T>* second = head;
			while (second != nullptr && second->next != nullptr && second->next != tail) {
				second = second->next->next; // đi 2 bước
				mid = mid->next; // đi 1 bước
			}
			p->next = mid->next;
			mid->next = p;
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
};

int main() {
	LinkedList<string> list;
	list.add("Mai");
	list.addTail("Khanh");
	list.addTail("Hai");
	list.addTail("Mai");
	list.addTail("Nga");
	list.addTail("Oanh");
	list.addTail("Huong");
	list.addTail("Mai");
	cout << "Danh sach goc: ";
	list.showList();
	list.update("Hoa", "Mai");
	cout << "Sau khi update tat ca node \"Mai\"->\"Hoa\": ";
	list.showList();
}