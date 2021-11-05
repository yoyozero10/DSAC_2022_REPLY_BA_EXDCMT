/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// class mô tả thông tin student
class Student {
	friend ostream& operator << (ostream&, const Student&);
	friend istream& operator >> (istream&, Student&);
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

	bool operator < (const Student& other) const {
		return id.compare(other.id) < 0;
	}

	bool operator > (const Student& other) const {
		return id.compare(other.id) > 0;
	}

	bool operator == (const Student& other) const {
		return id.compare(other.id) == 0;
	}
};

// min heap Student
class PriorityQueue {
	Student* data;
	int currentSize;
	int capacity;
public:
	PriorityQueue(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new Student[capacity];
		currentSize = 0;
	}

	bool push(Student value) {
		if (currentSize < capacity) {
			data[currentSize] = value;
			siftUp(currentSize);
			currentSize++;
			return true;
		}
		else {
			return false;
		}
	}

	void siftUp(int index) {
		int parentIndex = (index - 1) / 2;
		if (data[index] < data[parentIndex]) { // điều kiện tạo thành min heap
			swap(data[index], data[parentIndex]);
			siftUp(parentIndex);
		}
	}

	void showElements() {
		if (isEmpty()) {
			cout << "Queue rong.\n";
		}
		else {
			for (int i = 0; i < currentSize; i++)
			{
				cout << data[i];
			}
			cout << endl;
		}
	}

	int size() {
		return currentSize;
	}
	// hàm kiểm tra rỗng
	bool isEmpty() {
		return currentSize == 0;
	}
	// hàm kiểm tra đầy
	bool isFull() {
		return currentSize == capacity;
	}
	// hàm xóa node khỏi Queue
	bool pop() {
		if (!isEmpty()) {
			data[0] = data[currentSize - 1];
			currentSize--;
			siftDown(0);
			return true;
		}
		else {
			return false;
		}
	}
	// hàm tìm node
	int findNodeIndex(Student value) {
		for (int i = 0; i < currentSize; i++)
		{
			if (data[i] == value) {
				return i;
			}
		}
		return -1;
	}
	// hàm sàng xuống
	void siftDown(int index) {
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left < currentSize && data[left] < data[largest]) {
			largest = left;
		}
		if (right < currentSize && data[right] < data[largest]) {
			largest = right;
		}
		if (largest != index) {
			swap(data[index], data[largest]);
			siftDown(largest);
		}
	}
	// hàm trả về phần tử lớn nhất trong Queue
	Student front() {
		if (currentSize > 0) {
			return data[0];
		}
		else {
			return Student();
		}
	}

	// hàm hủy
	~PriorityQueue() {
		delete[] data;
	}
};

istream& operator >> (istream& is, Student& s) {
	cout << "Ma sv: ";
	is >> s.id;
	cout << "Ho: ";
	is >> s.lastName;
	cout << "Dem: ";
	is.ignore();
	getline(is, s.midName);
	cout << "Ten: ";
	is >> s.firstName;
	cout << "Diem tb: ";
	is >> s.gpa;
	return is;
}

ostream& operator << (ostream& os, const Student& s) {
	os << left << setw(10) << s.id << setw(25)
		<< s.getFullName() << setw(10) << s.gpa << endl;
	return os;
}

int main() {
	PriorityQueue queue;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot sinh vien vao queue.\n";
		cout << "2. Hien thi cac sinh vien trong queue.\n";
		cout << "3. Tim sinh vien co ma x trong queue.\n";
		cout << "4. Lay sinh vien dau hang doi.\n";
		cout << "5. Xoa sinh vien dau hang doi.\n";
		cout << "6. Kiem tra hang doi rong.\n";
		cout << "7. Kiem tra hang doi day.\n";
		cout << "8. Cho biet kich thuoc cua hang doi.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== The End ==>\n";
			break;
		case 1:
		{
			Student x;
			cout << "==== Nhap thong tin sinh vien ====\n";
			cin >> x;
			queue.push(x);
			break;
		}
		case 2:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				cout << "==== Cac sinh vien co trong queue ====\n";
				queue.showElements();
			}
			break;
		case 3:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				string x;
				cout << "Nhap ma sinh vien can tim: ";
				cin >> x;
				if (queue.findNodeIndex(x) >= 0) {
					cout << "SV ma \"" << x << "\" ton tai trong queue.\n";
				}
				else {
					cout << "SV ma \"" << x << "\" khong ton tai trong queue.\n";
				}
			}
			break;
		case 4:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				cout << "Sinh vien dau hang doi: \n";
				queue.front();
			}
			break;
		case 5:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				if (queue.pop()) {
					cout << "Xoa thanh cong.\n";
				}
				else {
					cout << "Xoa that bai.\n";
				}
			}
			break;
		case 6:
			if (!queue.isEmpty()) {
				cout << "Queue khong rong.\n" << endl;
			}
			else {
				cout << "Queue rong.\n";
			}
			break;
		case 7:
			if (queue.isFull()) {
				cout << "Hang doi day.\n";
			}
			else {
				cout << "Hang doi chua day.\n";
			}
			break;
		case 8:
			cout << "So sinh vien hien co trong queue: " << queue.size() << endl;
			break;
		default:
			cout << "<=== Sai lua chon. Vui long chon lai! ===>\n";
			break;
		}
	} while (choice != 0);
	return 0;
}