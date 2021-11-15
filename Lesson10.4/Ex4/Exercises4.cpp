/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

// hàm hiển thị các phần tử mảng
template<class T> void showElements(T* arr, int n) {
	cout << left << setw(12) << "Ma NV" << setw(10) << "Ho"
		<< setw(12) << "Dem" << setw(10) << "Ten"
		<< setw(12) << "Luong" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}

class Employee {
	friend ostream& operator << (ostream&, const Employee&);
private:
	string id;
	string first;
	string last;
	string mid;
	long salary;
public:
	Employee(string id = "", string first = "", string last = "",
		string mid = "", long salary = 0) {
		setId(id);
		setFirst(first);
		setLast(last);
		setMid(mid);
		setSalary(salary);
	}

	void setId(string id) {
		this->id = id;
	}

	void setFirst(string first) {
		this->first = first;
	}

	void setMid(string mid) {
		this->mid = mid;
	}

	void setLast(string last) {
		this->last = last;
	}

	void setSalary(long salary) {
		this->salary = salary;
	}

	string getId() const {
		return id;
	}

	string getFirst() const {
		return first;
	}

	string getLast() {
		return last;
	}

	string getMid() {
		return mid;
	}

	long getSalary() const {
		return salary;
	}

	bool operator >= (const Employee& emp) const {
		if (salary > emp.salary) {
			return true;
		}
		else if (salary == emp.salary) {
			if (first.compare(emp.first) < 0) {
				return true;
			}
			else if (first.compare(emp.first) == 0) {
				if (last.compare(emp.last) < 0) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator <= (const Employee& emp) {
		if (salary < emp.salary) {
			return true;
		}
		else if (salary == emp.salary) {
			if (first.compare(emp.first) > 0) {
				return true;
			}
			else if (first.compare(emp.first) == 0) {
				if (last.compare(emp.last) > 0) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator == (const Employee& e) {
		return id.compare(e.getId()) == 0;
	}
};

ostream& operator << (ostream& os, const Employee& e) {
	os << left << setw(12) << e.id << setw(10) << e.last
		<< setw(12) << e.mid << setw(10) << e.first
		<< setw(12) << e.salary;
	return os;
}

// hàm đọc dữ liệu đầu vào
void createEmployee(string str, Employee& e) {
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
	long salary = stol(data[size - 1]);
	e.setFirst(first);
	e.setLast(last);
	e.setMid(mid);
	e.setId(id);
	e.setSalary(salary);
}

class Node {
public:
	Node* left;
	Node* right;
	Employee data;

	Node(Employee data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BinarySearchTree {
	Node* root;
public:
	BinarySearchTree() {
		root = nullptr;
	}

	void add(Employee value) {
		root = add(root, value);
	}

	Node* add(Node* r, Employee value) {
		if (r == nullptr) {
			return new Node(value);
		}
		if (value >= r->data) {
			r->right = add(r->right, value);
		}
		else {
			r->left = add(r->left, value);
		}
		return r;
	}
	// duyệt theo thứ tự in-order
	void inOrderReverse() {
		inOrderReverse(root);
	}

	void inOrderReverse(Node* r) {
		if (r != nullptr) {
			inOrderReverse(r->right);
			cout << r->data << "\n"; 
			inOrderReverse(r->left);
		}
	}

	bool findById(string id) {
		int count = 0;
		findById(root, id, count);
		return count != 0;
	}

	void findById(Node* r, string id, int& count) {
		if (r != nullptr) {
			findById(r->left, id, count);
			if (r->data.getId().compare(id) == 0) {
				cout << "=== Tim thay ===\n";
				cout << r->data << endl;
				count++;
			}
			findById(r->right, id, count);
		}
	}

	bool findByName(string name) {
		int count = 0;
		findByName(root, name, count);
		return count == 0;
	}

	void findByName(Node* r, string name, int& count) {
		if (r != nullptr) {
			findByName(r->left, name, count);
			if (r->data.getFirst().find(name) != string::npos) {
				cout << r->data << endl;
				count++;
			}
			findByName(r->right, name, count);
		}
	}

	bool findBySalary(long salary) {
		int count = 0;
		cout << "================ KET QUA TIM KIEM ================\n";
		findBySalary(root, salary, count);
		return count != 0;
	}

	void findBySalary(Node* r, long salary , int& count) {
		if (r != nullptr) {
			findBySalary(r->left, salary, count);
			if (r->data.getSalary() == salary) {
				cout << r->data << endl;
				count++;
			}
			findBySalary(r->right, salary, count);
		}
	}

	bool findBySalaryInRange(long from, long to) {
		int count = 0;
		cout << "================ KET QUA TIM KIEM ================\n";
		findBySalaryInRange(root, from, to, count);
		return count != 0;
	}

	void findBySalaryInRange(Node* r, long from, long to, int& count) {
		if (r != nullptr) {
			findBySalaryInRange(r->left, from, to, count);
			if (r->data.getSalary() >= from && r->data.getSalary() <= to) {
				cout << r->data << endl;
				count++;
			}
			findBySalaryInRange(r->right, from, to, count);
		}
	}
};

int main() {
	int t; // số bộ test
	ifstream ifs("INPUT.DAT");
	if (ifs) {
		ifs >> t; // đọc số bộ test
		ifs.ignore();
		BinarySearchTree tree;
		for (int i = 0; i < t; i++) {
			string str;
			getline(ifs, str);
			Employee e;
			createEmployee(str, e);
			tree.add(e);
		}
		ifs.close();
		int choice = 0;
		do
		{
			cout << "===================== OPTIONS =====================\n";
			cout << "1. Tim nhan vien theo ma NV.\n";
			cout << "2. Tim nhan vien theo ten gan dung.\n";
			cout << "3. Tim nhan vien co muc luong x.\n";
			cout << "4. Tim nhan vien co muc luong trong doan [x, y].\n";
			cout << "5. Hien thi danh sach nhan vien hien co.\n";
			cout << "0. Thoat chuong trinh.\n";
			cout << "Lua chon cua ban? ";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "<=== CHUONG TRINH DA KET THUC ===>\n";
				break;
			case 1:
			{
				string id;
				cout << "Nhap ma nhan vien: ";
				cin >> id;
				if (!tree.findById(id)) {
					cout << "Khong tim thay nhan vien ma \"" << id << "\".\n";
				}
			}
			break;
			case 2:
			{
				string key;
				cout << "Nhap ten can tim: ";
				cin >> key;
				if (!tree.findByName(key)) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
			}
			break;
			case 3:
			{
				int x;
				cout << "Nhap muc luong: ";
				cin >> x;
				vector<Employee> employees;
				if (!tree.findBySalary(x)) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
			}
			break;
			case 4:
			{
				int x, y;
				cout << "Nhap muc luong toi thieu: ";
				cin >> x;
				cout << "Nhap muc luong toi da: ";
				cin >> y;
				vector<Employee> result;
				if (!tree.findBySalaryInRange(x, y)) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
			}
				break;
			case 5:
				cout << "====== Danh sach nhan vien ======\n";
				tree.inOrderReverse();
				break;
			default:
				cout << "Sai lua chon. Vui long chon lai!\n";
				break;
			}
		} while (choice != 0);
	}
	else {
		cout << "<== Khong mo duoc file. Vui long kiem tra lai! ==>\n";
	}

	return 0;
}
