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

	void addBeforeX(T data, T x) {
		if (isEmpty()) {
			add(data);
		}
		else {
			Node<T>* nodeX = head; // bắt đầu từ node head
			Node<T>* prevX = head;
			while (nodeX != nullptr) { // tìm nodeX
				if (nodeX->data == x) { // nếu tìm thấy
					break; // kết thúc việc tìm kiếm
				}
				prevX = nodeX;
				nodeX = nodeX->next; // chuyển tới node kế tiếp
			}
			if (nodeX != nullptr) { // nếu tìm thấy
				Node<T>* p = new Node<T>(data); // tạo node mới p
				if (nodeX == head) { // kiểm tra xem nodeX có phải head không
					p->next = head;
					head = p; // update node head
				}
				else {
					prevX->next = p; // cập nhật next của p
					p->next = nodeX; // cập nhật next của nodeX
				}
			}
			else { // nếu không tìm thấy
				cout << "Khong tim thay node muc tieu\n";
			}
		}
	}

	// thêm node vào sau vị trí k trong danh sách liên kết đơn
	void addAfterK(T data, int k) {
		if (isEmpty()) {
			add(data);
		}
		else {
			int count = 1;
			Node<T>* p = new Node<T>(data); // tạo node mới p
			Node<T>* nodeX = head; // bắt đầu từ node head
			while (nodeX != nullptr) { // tìm nodeX
				if (count == k) { // nếu tìm thấy
					break; // kết thúc việc tìm kiếm
				}
				count++;
				nodeX = nodeX->next; // chuyển tới node kế tiếp
			}
			if (nodeX != nullptr) { // nếu tìm thấy
				p->next = nodeX->next; // cập nhật next của nodeX
				nodeX->next = p;
			}
			else { // nếu không tìm thấy
				tail->next = p; // cập nhật next của tail cũ
				tail = p; // gán lại tail mới
			}
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
	list.addTail("Khanh");
	list.addTail("Hai");
	list.addTail("Mai");
	list.addTail("Nga");
	list.addTail("Oanh");
	list.addTail("Huong");
	cout << "Danh sach goc: ";
	list.showList();
	list.addBeforeX("Loan", "Mai");
	cout << "Sau khi chen truoc node 'Mai': ";
	list.showList();
	list.addAfterK("Hoang", 3);
	cout << "Sau khi them node sau vi tri 3: ";
	list.showList();
	cout << "Phan tu giua: " << list.middle()->data << endl;
	list.addAfterMid("Nhung");
	cout << "Sau khi them node sau node giua: ";
	list.showList();
}