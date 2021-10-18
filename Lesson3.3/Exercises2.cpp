#include <iostream>
using namespace std;

template<class T> class Node { // sử dụng lớp template
public:
	T data; // dữ liệu của node hiện tại
	Node<T>* next; // con trỏ trỏ tới node kế tiếp
	Node<T>* prev; // con trỏ trỏ tới node liền trước

	Node(T data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->data = data; // gán giá trị của data cho node
	}
};

template<class T> class LinkedList {
private:
	Node<T>* head; // con trỏ trỏ đến node đầu tiên trong danh sách
public:
	LinkedList() {
		head = nullptr;
	}
	// thêm vào đầu danh sách
	void add(T data) {
		Node<T>* p = new Node<T>(data); // tạo node mới p
		p->next = head; // cập nhật node next của p
		if (head != nullptr) {
			head->prev = p;
		}
		head = p; // cập nhật lại node head
	}

	// thêm trước node x
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
				if (nodeX == head) { // kiểm tra xem nodeX có phải head không
					add(data);
				}
				else {
					Node<T>* p = new Node<T>(data); // tạo node mới p
					prevX->next = p; // cập nhật next của p
					p->prev = prevX;
					p->next = nodeX; // cập nhật next của nodeX
					nodeX->prev = p;
				}
			}
			else { // nếu không tìm thấy
				cout << "Khong tim thay node muc tieu\n";
			}
		}
	}

	// thêm sau node có giá trị x
	void addAfterX(T data, T x) {
		if (isEmpty()) {
			add(data);
		}
		else {
			Node<T>* nodeX = head; // bắt đầu từ node head
			while (nodeX != nullptr) { // tìm nodeX
				if (nodeX->data == x) { // nếu tìm thấy
					break; // kết thúc việc tìm kiếm
				}
				nodeX = nodeX->next; // chuyển tới node kế tiếp
			}
			if (nodeX != nullptr) { // nếu tìm thấy
				Node<T>* p = new Node<T>(data); // tạo node mới p
				p->next = nodeX->next; // cập nhật next của p
				if (nodeX->next != nullptr) {
					nodeX->next->prev = p;
				}
				nodeX->next = p; // cập nhật next của nodeX
				p->prev = nodeX; // cập nhật prev của node p
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
			Node<T>* nodeX = head; // bắt đầu từ node head
			while (nodeX != nullptr) { // tìm nodeX
				if (count == k) { // nếu tìm thấy
					break; // kết thúc việc tìm kiếm
				}
				count++;
				nodeX = nodeX->next; // chuyển tới node kế tiếp
			}
			if (nodeX != nullptr) { // nếu tìm thấy node có giá trị x
				Node<T>* p = new Node<T>(data); // tạo node mới p
				p->next = nodeX->next; // cập nhật next của nodeX
				p->prev = nodeX;
				nodeX->next = p;
				if (p->next != nullptr) {
					p->next->prev = p; // cập nhật next của node sau p
				}
			}
			else { // nếu không tìm thấy
				cout << "Khong tim thay node muc tieu.\n";
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
		while (second != nullptr && second->next != nullptr) {
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
			while (second != nullptr && second->next != nullptr) {
				second = second->next->next; // đi 2 bước
				mid = mid->next; // đi 1 bước
			}
			p->next = mid->next;
			mid->next->prev = p;
			mid->next = p;
			p->prev = mid;
		}
	}

	void addTail(T data) { // chèn node vào cuối danh sách liên kết
		if (isEmpty()) {
			add(data);
		}
		else {
			Node<T>* p = new Node<T>(data); // tạo node mới p
			Node<T>* q = head;
			while (q->next != nullptr) {
				q = q->next;
			}
			q->next = p; // cập nhật node next của tail
			p->prev = q; // cập nhật node prev của p
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

	// hiển thị danh sách theo thứ tự đảo ngược
	void showListReverse() { // hàm hiển thị danh sách liên kết
		Node<T>* p = head; // khởi đầu từ node head
		// tìm node cuối trong danh sách
		while (p != nullptr && p->next != nullptr) {
			p = p->next;
		}

		while (p != nullptr) // lặp chừng nào p chưa null
		{
			cout << p->data << "->"; // hiển thị data của p
			p = p->prev; // cập nhật p
		}
		cout << "null" << endl;
	}

	bool isEmpty() {
		return head == nullptr;
	}
};

int main() {
	LinkedList<string> list;
	// thêm vào đầu:
	list.add("Binh");

	// thêm vào cuối:
	list.addTail("Khanh");
	list.addTail("Hai");
	list.addTail("Mai");
	list.addTail("Nga");
	list.addTail("Oanh");
	list.addTail("Huong");

	// hiển thị danh sách:
	cout << "Danh sach goc: ";
	list.showList();

	// thêm vào trước node có giá trị "Mai"
	list.addBeforeX("Loan", "Mai");
	cout << "Sau khi chen truoc node 'Mai': ";
	list.showList();

	// thêm vào sau node có giá trị "Mai"
	cout << "Sau khi chen sau node 'Mai': ";
	list.addAfterX("Trang", "Mai");
	list.showList();

	// thêm node sau vị trí k
	list.addAfterK("Hoang", 3);
	cout << "Sau khi them node sau vi tri 3: ";
	list.showList();

	// thêm node sau phần tử giữa
	cout << "Phan tu giua: " << list.middle()->data << endl;
	list.addAfterMid("Nhung");
	cout << "Sau khi them node sau node giua: ";
	list.showList();

	// hiển thị danh sách đảo ngược
	cout << "Danh sach dao nguoc: ";
	list.showListReverse();

	return 0;
}