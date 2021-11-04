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
class Heap {
	Student* data;
	int currentSize;
	int capacity;
public:
	Heap(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new Student[capacity];
		currentSize = 0;
	}

	bool add(Student value) {
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
			cout << "Heap rong.\n";
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

	bool isEmpty() {
		return currentSize == 0;
	}
	// hàm xóa node khỏi heap
	bool remove(Student value) {
		int index = findNodeIndex(value);
		if (index >= 0) {
			data[index] = data[currentSize - 1];
			currentSize--;
			siftDown(index);
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
	// hàm trả về phần tử lớn nhất trong heap
	Student front() {
		if (currentSize > 0) {
			return data[0];
		}
		else {
			return Student();
		}
	}
	// hàm hủy
	~Heap() {
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
	Heap heap;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot sinh vien vao heap.\n";
		cout << "2. Hien thi cac sinh vien trong heap.\n";
		cout << "3. Tim sinh vien co ma x trong heap.\n";
		cout << "4. Xoa sinh vien co ma x.\n";
		cout << "5. Cho biet sinh vien co ma nho nhat trong heap.\n";
		cout << "6. Cho biet so luong sv hien co trong heap.\n";
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
			heap.add(x);
			break;
		}
		case 2:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "==== Cac sinh vien co trong heap ====\n";
				heap.showElements();
			}
			break;
		case 3:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				string x;
				cout << "Nhap ma sinh vien can tim: ";
				cin >> x;
				if (heap.findNodeIndex(x) >= 0) {
					cout << "SV ma \"" << x << "\" ton tai trong heap.\n";
				}
				else {
					cout << "SV ma \"" << x << "\" khong ton tai trong heap.\n";
				}
			}
			break;
		case 4:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				string x;
				cout << "Nhap ma sinh vien can xoa: ";
				cin >> x;
				Student s(x);
				if (heap.remove(s)) {
					cout << "Xoa thanh cong.\n";
				}
				else {
					cout << "Xoa that bai.\n";
				}
			}
			break;
		case 5:
			cout << "SV co ma sv nho nhat trong heap: " << heap.front() << endl;
			break;
		case 6:
			cout << "So SV hien co trong heap: " << heap.size() << endl;
			break;
		default:
			cout << "<=== Sai lua chon. Vui long chon lai! ===>\n";
			break;
		}
	} while (choice != 0);
	return 0;
}