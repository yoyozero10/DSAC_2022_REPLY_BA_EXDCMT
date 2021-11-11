/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

class Student {
	friend ostream& operator << (ostream&, const Student&);
	string id;
	string firstName;
	string lastName;
	string midName;
	float gpa;
public:
	Student(string id = "", string first = "", 
		string last = "", string mid = "", float gpa = 0) {
		this->id = id;
		this->firstName = first;
		this->lastName = last;
		this->midName = mid;
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

	void setGpa(float gpa) {
		this->gpa = gpa;
	}

	bool operator == (const Student& other) {
		return id.compare(other.id) == 0;
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

	float getAvg() {
		return gpa;
	}

	string getFullName() const {
		return lastName + " " + midName + " " + firstName;
	}

	bool operator <= (const Student& other) {
		int nameCompare = firstName.compare(other.firstName);
		if (nameCompare == 0) {
			return lastName.compare(other.lastName) < 0;
		}
		else {
			return nameCompare < 0;
		}
	}
};

ostream& operator << (ostream& os, const Student& s) {
	os << left << setw(10) << s.id << setw(25) << s.getFullName()
		<< setw(10) << s.gpa << endl;
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

	Node* getHead() {
		return head;
	}

	Node* getTail() {
		return tail;
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
		showTableHeader();
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

	void showTableHeader() {
		cout << left << setw(10) << "Ma SV" << setw(25) << "Ho ten" << "Diem TB" << endl;
	}

	// hàm tìm sinh viên theo mã sinh viên
	void findStudentById(string id) {
		bool existed = false;
		Node* p = head;
		while (p != nullptr) {
			if (p->data.getId().compare(id) == 0) { // nếu tìm thấy
				cout << "<== Tim thay sinh vien ma \"" << id << "\" ==>\n";
				showTableHeader();
				cout << p->data << endl;
				existed = true;
			}
			p = p->next;
		}
		if (!existed) {
			cout << "Khong ton tai sinh vien can tim.\n";
		}
	}
	// tìm kiếm sinh viên theo tên
	int findByName(string firstName) {
		int count = 0;
		// viết thường tất cả chữ cái trong tên truyền vào
		transform(firstName.begin(), firstName.end(), firstName.begin(),
			[](unsigned char c) { return std::tolower(c); });
		for (Node* p = head; p != nullptr; p = p->next)
		{
			string name = p->data.getFirstName();
			// viết thường tất cả chữ cái trong tên
			transform(name.begin(), name.end(), name.begin(),
				[](unsigned char c) { return std::tolower(c); });
			if (name.compare(firstName) == 0) {
				count++;
			}
		}
		return count;
	}
	// tìm sinh viên có điểm tb >= x nhập vào từ bàn phím
	int findByGPA(float gpa) {
		Node* p = head;
		int count = 0;
		while (p != nullptr) {
			if (p->data.getAvg() >= gpa) { // nếu tìm thấy
				count++;
			}
			p = p->next;
		}
		return count;
	}
	// hàm chia đôi danh sách liên kết
	void split(Node* source, Node** front, Node** back) {
		Node* p = source->next;
		Node* mid = source;
		while (p != nullptr) {
			p = p->next;
			if (p != nullptr) {
				mid = mid->next;
				p = p->next;
			}
		}
		*front = source;
		*back = mid->next;
		mid->next = nullptr; // chia đôi danh sách
	}
	// hàm trộn hai danh sách lại với nhau
	Node* merge(Node* front, Node* back) {
		Node* result = nullptr;
		if (front == nullptr) {
			return back;
		}
		else if (back == nullptr) {
			return front;
		}
		if (front->data <= back->data) {
			result = front;
			result->next = merge(front->next, back);
		}
		else {
			result = back;
			result->next = merge(front, back->next);
		}
		return result;
	}
	// hàm sắp xếp trộn
	void mergeSort() {
		mergeSort(&head);
	}

	void mergeSort(Node** r) {
		Node* first = *r;
		Node* a;
		Node* b;
		if (first == nullptr || first->next == nullptr) {
			return;
		}
		split(first, &a, &b);
		mergeSort(&a);
		mergeSort(&b);
		*r = merge(a, b);
	}
};

// hàm đọc dữ liệu đầu vào
void createStudent(string str, Student& e) {
	stringstream ss(str);
	string data[10];
	string s;
	int size = 0; // biến đếm số từ tách được từ string
	while (ss >> s) {
		data[size++] = s;
	}
	string id = data[0];
	string first = data[size - 2], last = data[1], mid;
	for (int j = 2; j < size - 2; j++)
	{
		mid.append(data[j]);
		if (j < size - 3) {
			mid.append(" ");
		}
	}
	float gpa = stof(data[size - 1]);
	e.setFirstName(first);
	e.setLastName(last);
	e.setMidName(mid);
	e.setId(id);
	e.setGpa(gpa);
}

int main() {
	LinkedList students;
	int t = 0; // số bộ test
	ifstream ifs("students.txt");
	if (ifs) {
		while (true) {
			string str;
			getline(ifs, str);
			Student s;
			createStudent(str, s);
			students.add(s);
			if (ifs.eof()) {
				break;
			}
		}
		ifs.close();
		students.mergeSort();
		students.showList();
	}
	else {
		cout << "<== Khong mo duoc file. Vui long kiem tra lai! ==>\n";
	}
	return 0;
}