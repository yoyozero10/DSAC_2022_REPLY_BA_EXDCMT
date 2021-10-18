#include <iostream>
#include <string>
using namespace std;

class Student {
	friend ostream& operator << (ostream&, const Student&);
	string id;
	string fullName;
	string address;
	string email;
	int age;
	float gpa;
public:
	Student(string id = "", string fullName = "", 
		string address = "", string email = "", int age = 0, float gpa = 0) {
		this->email = email;
		this->id = id;
		this->fullName = fullName;
		this->address = address;
		this->age = age;
		this->gpa = gpa;
	}

	void setId(string id) {
		this->id = id;
	}

	void setFullName(string fullName) {
		this->fullName = fullName;
	}

	void setEmail(string email) {
		this->email = email;
	}

	void setAddress(string address) {
		this->address = address;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setGpa(float gpa) {
		this->gpa = gpa;
	}

	bool operator == (const Student& other) {
		return id.compare(other.id) == 0;
	}

	void update(const Student& other) {
		email = other.email;
		gpa = other.gpa;
	}
};

ostream& operator << (ostream& os, const Student& s) {
	os << "[" << s.id << ", " << s.fullName << ", " << s.email
		<< ", " << s.address << ", " << s.age << ", " << s.gpa << "]\n";
	return os;
}

class Node { // sử dụng lớp template
public:
	Student data; // dữ liệu của node hiện tại
	Node* next; // con trỏ trỏ tới node kế tiếp
	Node* prev; // con trỏ trỏ tới node liền trước

	Node(Student data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->data = data; // gán giá trị của data cho node
	}
};

class LinkedList {
private:
	Node* head; // con trỏ trỏ đến node đầu tiên trong danh sách
	Node* tail; // con trỏ trỏ tới node cuối của danh sách
public:
	// hàm khởi tạo
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	// chèn vào đầu danh sách liên kết
	void add(Student data) {
		Node* p = new Node(data); // tạo node mới p
		if (isEmpty()) { // kiểm tra xem danh sách rỗng không
			head = tail = p; // gán giá trị cho head, tail
		}
		else { // nếu danh sách không rỗng
			p->next = head; // cập nhật node next của p
			head->prev = p; // cập nhật prev của node head cũ
			head = p; // cập nhật lại node head mới
		}
	}

	// hàm cập nhật điểm và email theo mã sinh viên
	bool update(Student data) {
		Node* p = head;
		while (p != nullptr) {
			if (p->data == data) {
				p->data.update(data);
				return true; // update success
			}
			p = p->next;
		}
		return false;
	}

	// chèn vào cuối danh sách liên kết
	void addTail(Student data) { // chèn node vào cuối danh sách liên kết
		Node* p = new Node(data); // tạo node mới p
		if (!isEmpty()) {
			tail->next = p; // cập nhật node next của tail
			p->prev = tail; // cập nhật node prev của p
			tail = p; // cập nhật lại tail
		}
		else {
			head = tail = p; // gán head, tail cùng bằng p
		}
	}

	// hiển thị danh sách liên kết
	void showList() { // hàm hiển thị danh sách liên kết
		Node* p = head; // khởi đầu từ node head
		while (p != nullptr) // lặp chừng nào p chưa null
		{
			cout << p->data; // hiển thị data của p
			p = p->next; // cập nhật p
		}
	}

	// kiểm tra danh sách rỗng
	bool isEmpty() {
		return head == nullptr;
	}
};

int main() {
	LinkedList students;
	// thêm vào đầu
	students.add(Student("SV001", "Tran Hoai Nam", "Ha Noi", "hoainam@xmail.com", 20, 3.25f));
	students.add(Student("SV003", "Le Van Khanh", "Ha Noi", "khanhle@xmail.com", 20, 3.75f));
	students.add(Student("SV002", "Nguyen Thi Hoa", "Ha Noi", "hoahoa@xmail.com", 20, 3.15f));
	students.add(Student("SV007", "Hoang Cong Chat", "Ha Noi", "congchat@xmail.com", 19, 3.45f));
	students.add(Student("SV005", "Ngo Van Dai", "Ha Noi", "daingo@xmail.com", 20, 3.85f));
	students.add(Student("SV004", "Khuc Van Banh", "Ha Noi", "banhkhuc@xmail.com", 21, 3.15f));
	cout << "Danh sach truoc update: \n";
	students.showList();
	// update info
	students.update(Student("SV002", "", "", "hoalily@xmail.com", 0, 3.35f));
	cout << "Danh sach sau update sinh vien ma \"SV002\": \n";
	students.showList();

	return 0;
}