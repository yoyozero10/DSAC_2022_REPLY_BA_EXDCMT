/*
 * @author Branium Academy
 * @version 2021.10
 * @see https://braniumacademy.net
*/
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

	string getId() {
		return id;
	}

	string getFullName() {
		return fullName;
	}

	int getAge() {
		return age;
	}

	float getAvg() {
		return gpa;
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

	Node(Student data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->data = data; // gán giá trị của data cho node
	}
};

class LinkedList {
private:
	Node* head; // con trỏ trỏ đến node đầu tiên trong danh sách
	Node* tail; // con trỏ trỏ tới node cuối danh sách
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	// thêm vào đầu danh sách
	void add(Student data) {
		Node* p = new Node(data); // tạo node mới p
		p->next = head; // cập nhật node next của p
		head = p; // cập nhật lại node head
		if (isEmpty()) {
			tail = head;
		}
	}

	void addTail(Student data) { // chèn node vào cuối danh sách liên kết
		if (isEmpty()) {
			add(data);
		}
		else {
			Node* p = new Node(data); // tạo node mới p
			tail->next = p; // cập nhật node next của tail
			tail = p;
		}
	}

	void showList() { // hàm hiển thị danh sách liên kết
		Node* p = head; // khởi đầu từ node head
		while (p != nullptr) // lặp chừng nào p chưa null
		{
			cout << p->data; // hiển thị data của p
			p = p->next; // cập nhật p
		}
		cout << endl;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	bool removeById(string id) {
		Node* p = head;
		Node* prevP = head;
		while (p != nullptr)
		{
			if (p->data.getId().compare(id) == 0) {
				if (p == head) {
					Node* oldHead = head;
					head = head->next;
					delete oldHead;
				}
				else {
					Node* r = p;
					prevP->next = p->next;
					p = p->next;
					delete r;
				}
				return true; // xóa thành công
			}
			prevP = p;
			p = p->next;
		}
		return false; // xóa thất bại
	}

	int namePosition(string fullName) {
		for (int i = fullName.size() - 1; i >= 0; i--) {
			if (fullName.at(i) == ' ') {
				return i + 1;
			}
		}
		return -1;
	}

	void removeByName(string name) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getFullName().substr(namePosition(x->data.getFullName())).compare(name) == 0) {
				if (x == head) {
					removeHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					removeTail(prevX);
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					delete r;
					continue;
				}
			}
			prevX = x;
			x = x->next;
		}
	}

	void removeByAge(int age) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getAge() == age) {
				if (x == head) {
					removeHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					removeTail(prevX);
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					delete r;
					continue;
				}
			}
			prevX = x;
			x = x->next;
		}
	}

	void removeByGPA(float gpa, int max) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		int count = 0;
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getAvg() == gpa && count < max) {
				if (x == head) {
					removeHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					removeTail(prevX);
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					delete r;
					continue;
				}
				count++;
			}
			prevX = x;
			x = x->next;
		}
	}


	bool removeHead() {
		Node* r = head;
		head = head->next;
		delete r;
		return true;
	}

	bool removeTail(Node* prevX) {
		Node* r = tail;
		prevX->next = nullptr;
		tail = prevX;
		delete r;
		return true;
	}
};
int main() {
	LinkedList students;
	// thêm vào đầu
	students.add(Student("SV006", "Tran Thuy Lan", "Ha Noi", "lan@xmail.com", 20, 3.85f));
	students.add(Student("SV001", "Tran Hoai Nam", "Ha Noi", "hoainam@xmail.com", 20, 3.25f));
	students.add(Student("SV003", "Le Van Khanh", "Ha Noi", "khanhle@xmail.com", 20, 3.75f));
	students.add(Student("SV002", "Nguyen Thi Dai", "Ha Noi", "hoahoa@xmail.com", 20, 3.15f));
	students.add(Student("SV007", "Hoang Cong Chat", "Ha Noi", "congchat@xmail.com", 19, 3.15f));
	students.add(Student("SV005", "Ngo Van Dai", "Ha Noi", "daingo@xmail.com", 20, 3.85f));
	students.add(Student("SV004", "Khuc Van Dai", "Ha Noi", "banhkhuc@xmail.com", 21, 3.15f));
	students.add(Student("SV008", "Le Thanh Dat", "Ha Noi", "dat@xmail.com", 21, 3.55f));
	students.add(Student("SV009", "Mai Anh Nhu", "Ha Noi", "nhu@xmail.com", 21, 3.15f));
	cout << "Danh sach truoc update: \n";
	students.showList();
	// xóa theo id
	students.removeById("SV006");
	cout << "Danh sach sau xoa sinh vien ma \"SV006\": \n";
	students.showList();
	// xóa tất cả sv có tên Dai
	students.removeByName("Dai");
	cout << "Danh sach sau xoa cac sinh vien ten \"Dai\": \n";
	students.showList();
	// xóa tất cả sv 20 tuổi
	students.removeByAge(20);
	cout << "Danh sach sau xoa cac sinh vien tuoi = 20: \n";
	students.showList();
	// xóa tối đa n sv điểm tb = 3.15
	students.removeByGPA(3.15f, 2);
	cout << "Danh sach sau xoa toi da 2 sinh vien diem TB = 3.15: \n";
	students.showList();
}