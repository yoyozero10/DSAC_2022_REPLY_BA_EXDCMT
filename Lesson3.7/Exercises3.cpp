/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
	friend ostream& operator << (ostream&, const Student&);
	string id;
	string firstName;
	string lastName;
	string midName;
	string address;
	string email;
	int age;
	float gpa;
public:
	Student(string id = "", string first = "", string last = "", string mid = "",
		string address = "", string email = "", int age = 0, float gpa = 0) {
		this->email = email;
		this->id = id;
		this->firstName = first;
		this->lastName = last;
		this->midName = mid;
		this->address = address;
		this->age = age;
		this->gpa = gpa;
	}

	void setId(string id) {
		this->id = id;
	}

	void setFirstName(string first) {
		this->firstName = first;
	}

	void setLastName(string last) {
		this->lastName = last;
	}

	void setMidName(string mid) {
		this->midName = mid;
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

	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	string getMidName() {
		return midName;
	}

	int getAge() {
		return age;
	}

	float getAvg() {
		return gpa;
	}

	string getFullName() const {
		return lastName + " " + midName + " " + firstName;
	}
};

ostream& operator << (ostream& os, const Student& s) {
	os << left << setw(10) << s.id << setw(25) << s.getFullName() << setw(20) << s.email
		<< setw(12) << s.address << setw(10) << s.age << setw(10) << s.gpa << endl;
	return os;
}

class Node { // sử dụng lớp template
public:
	Student data; // dữ liệu của node hiện tại
	Node* next; // con trỏ trỏ tới node kế tiếp
	Node* prev; // con trỏ trỏ tới node liền trước

	Node(Student data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->prev = nullptr;
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
		cout << left << setw(10) << "Ma SV" << setw(25) << "Ho ten" << setw(20) << "Email"
			<< setw(12) << "Dia chi" << setw(10) << "Tuoi" << setw(10) << "Diem TB" << endl;
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

	// hàm sắp xếp danh sách sinh viên theo mã tăng dần
	void sortById() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getId().compare(p->data.getId()) < 0) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// hàm sắp xếp danh sách sinh viên theo tên tăng dần
	void sortByName() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getFirstName().compare(p->data.getFirstName()) < 0) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// hàm sắp xếp danh sách sinh viên theo tuổi tăng dần
	void sortByAge() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getAge() < p->data.getAge()) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// hàm sắp xếp danh sách sinh viên theo điểm tăng dần
	void sortByGPA() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getAvg() < p->data.getAvg()) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// hàm sắp xếp danh sách sinh viên theo điểm giảm dần
	void sortByGPADESC() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getAvg() > p->data.getAvg()) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
				else if (q->data.getAvg() == p->data.getAvg()) {
					if (q->data.getFirstName() < p->data.getFirstName()) {
						auto tmp = p->data;
						p->data = q->data;
						q->data = tmp;
					}
					else if (q->data.getFirstName() == p->data.getFirstName()) {
						if (q->data.getLastName() < p->data.getLastName()) {
							auto tmp = p->data;
							p->data = q->data;
							q->data = tmp;
						}
					}
				}
			}
		}
	}
};

int main() {
	LinkedList students;
	// thêm vào đầu
	students.add(Student("SV006", "Nam", "Tran", "Hoang", "Ha Noi", "hoangnam@xmail.com", 25, 3.28f));
	students.add(Student("SV001", "Nam", "Tran", "Hoai", "Ha Noi", "hoainam@xmail.com", 20, 3.25f));
	students.add(Student("SV003", "Khanh", "Le", "Van", "Ha Noi", "khanhle@xmail.com", 20, 3.75f));
	students.add(Student("SV002", "Dai", "Nguyen", "Van", "Ha Noi", "hoahoa@xmail.com", 20, 3.15f));
	students.add(Student("SV007", "Dai", "Hoang", "Trong", "Ha Noi", "congchat@xmail.com", 19, 3.15f));
	students.add(Student("SV008", "Hoa", "Hua", "Thanh", "Ha Noi", "thanhhoa@xmail.com", 19, 3.15f));
	students.add(Student("SV009", "Chat", "Hoang", "Cong", "Ha Noi", "congchat@xmail.com", 19, 3.45f));
	students.add(Student("SV012", "Quy", "Le", "Dinh", "Ha Noi", "dinhquy@xmail.com", 19, 3.45f));
	students.add(Student("SV005", "Dai", "Ngo", "Thua", "Ha Noi", "daingo@xmail.com", 20, 3.85f));
	students.add(Student("SV004", "Dai", "Le", "Ba", "Ha Noi", "badai@xmail.com", 21, 3.15f));
	students.add(Student("SV013", "Hoa", "Le", "Thi", "Ha Noi", "lehoa@xmail.com", 21, 3.15f));
	// hiển thị
	cout << ">> Danh sach ban dau: \n";
	students.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo ma SV: \n";
	students.sortById();
	students.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo ten SV: \n";
	students.sortByName();
	students.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo tuoi SV: \n";
	students.sortByAge();
	students.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo diem SV: \n";
	students.sortByGPA();
	students.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo diem SV giam dan: \n";
	students.sortByGPADESC();
	students.showList();

	return 0;
}