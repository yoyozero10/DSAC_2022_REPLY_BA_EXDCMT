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
template<class T> void showElements(vector<T> arr) {
	cout << left << setw(12) << "Ma NV" << setw(10) << "Ho"
		<< setw(12) << "Dem" << setw(10) << "Ten"
		<< setw(12) << "Luong" << endl;
	int n = arr.size();
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

bool compareId(const Employee& e1, const Employee& e2) {
	return e1.getId().compare(e2.getId()) > 0;
}

bool compareSalary(const Employee& e1, const Employee& e2) {
	return e1.getSalary() < e2.getSalary();
}

bool compareTotal(const Employee& e1, const Employee& e2) {
	return e1 >= e2;
}

bool compareName(const Employee& e1, const Employee& e2) {
	return e1.getFirst().compare(e2.getFirst()) > 0;
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

// thuật toán trộn
template<class T> void merge(T* arr, int first, int middle,
	int last, bool (*compare)(const Employee&, const Employee&)) {
	int size1 = middle - first + 1;
	int size2 = last - middle;
	T* leftArr = new T[size1];
	T* rightArr = new T[size2];
	for (int i = 0; i < size1; i++)
	{
		leftArr[i] = arr[first + i];
	}
	for (int j = 0; j < size2; j++)
	{
		rightArr[j] = arr[middle + j + 1];
	}
	int i = 0, j = 0, k = first;
	while (i < size1 && j < size2) {
		if (compare(leftArr[i], rightArr[j])) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}
	while (i < size1) {
		arr[k++] = leftArr[i++];
	}
	while (j < size2)
	{
		arr[k++] = rightArr[j++];
	}
}

// thuật toán sắp xếp trộn
template<class T> void mergeSort(T* arr, int first, int last,
	bool (*compare)(const Employee&, const Employee&)) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergeSort(arr, first, middle, (*compare));
		mergeSort(arr, middle + 1, last, (*compare));
		merge(arr, first, middle, last, (*compare));
	}
}

// thuật toán tìm kiếm nhị phân
int findById(vector<Employee>& arr, int left, int right, string x) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid].getId().compare(x) == 0) {
			return mid;
		}
		else if (arr[mid].getId().compare(x) < 0) {
			return findById(arr, mid + 1, right, x);
		}
		else {
			return findById(arr, left, mid - 1, x);
		}
	}
	return -1; // không tìm thấy
}

void findByName(vector<Employee>& arr, int n, string x, vector<Employee>& v) {
	transform(x.begin(), x.end(), x.begin(),
		[](unsigned char c) { return tolower(c); });
	for (int i = 0; i < n; i++)
	{
		string name = arr[i].getFirst();
		transform(name.begin(), name.end(), name.begin(),
			[](unsigned char c) { return tolower(c); });
		if (name.find(x) != string::npos) {
			v.push_back(arr[i]);
		}
	}
}

int leftMostX(vector<Employee>& arr, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == 0 || arr[mid - 1].getSalary() < x) && arr[mid].getSalary() == x) {
			return mid;
		}
		if (arr[mid].getSalary() < x) { // tìm phía bên phải
			return leftMostX(arr, mid + 1, right, x);
		}
		else { // tìm phía trái
			return leftMostX(arr, left, mid - 1, x);
		}
	}
	return -1;
}

int rightMostX(vector<Employee>& arr, int n, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == n - 1 || arr[mid + 1].getSalary() > x) && arr[mid].getSalary() == x) {
			return mid;
		}
		if (arr[mid].getSalary() <= x) { // tìm phía bên phải
			return rightMostX(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostX(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}

void findBySalary(vector<Employee>& arr, int n, int x, vector<Employee>& v) {
	int counter = 0;
	// tìm vị trí trái cùng xuất hiện x
	int startPos = leftMostX(arr, 0, n - 1, x);
	if (startPos == -1) { // không tìm thấy x
		return;
	}
	// tìm vị trí phải củng xuất hiện x
	int endPos = rightMostX(arr, n, 0, n - 1, x);
	for (int i = startPos; i <= endPos; i++)
	{
		v.push_back(arr[i]);
	}
}

int leftMostXInRange(vector<Employee>& arr, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == 0 || (arr[mid - 1].getSalary() < x)) && arr[mid].getSalary() >= x) {
			return mid;
		}
		if (arr[mid].getSalary() < x) { // tìm phía bên phải
			return leftMostXInRange(arr, mid + 1, right, x);
		}
		else { // tìm phía trái
			return leftMostXInRange(arr, left, mid - 1, x);
		}
	}
	return -1;
}

int rightMostXInRange(vector<Employee>& arr, int n, int left, int right, int x) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if ((mid == n - 1 || arr[mid + 1].getSalary() > x) && arr[mid].getSalary() <= x) {
			return mid;
		}
		if (arr[mid].getSalary() <= x) { // tìm phía bên phải
			return rightMostXInRange(arr, n, mid + 1, right, x);
		}
		else { // tìm phía trái
			return rightMostXInRange(arr, n, left, mid - 1, x);
		}
	}
	return -1;
}

void findBySalaryInRange(vector<Employee>& arr, int n, int x, int y, vector<Employee>& v) {
	int counter = 0;
	// tìm vị trí trái cùng xuất hiện x
	int startPos = leftMostXInRange(arr, 0, n - 1, x);
	if (startPos == -1) { // không tìm thấy x
		return;
	}
	// tìm vị trí phải củng xuất hiện x
	int endPos = rightMostXInRange(arr, n, 0, n - 1, y);
	for (int i = startPos; i <= endPos; i++)
	{
		v.push_back(arr[i]);
	}
}

int main() {
	int t; // số bộ test
	ifstream ifs("INPUT.DAT");
	if (ifs) {
		ifs >> t; // đọc số bộ test
		ifs.ignore();
		vector<Employee> arr;
		for (int i = 0; i < t; i++) {
			string str;
			getline(ifs, str);
			Employee e;
			createEmployee(str, e);
			arr.push_back(e);
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
				sort(arr.begin(), arr.end(), compareId);
				int index = findById(arr, 0, t - 1, id);
				if (index != -1) {
					cout << "=== TIM THAY ===\n";
					cout << arr[index] << endl;
					break;
				}
				if (index == -1) {
					cout << "Khong tim thay nhan vien ma \"" << id << "\".\n";
				}
			}
			break;
			case 2:
			{
				string key;
				cout << "Nhap ten can tim: ";
				cin >> key;
				vector<Employee> vectorEmp;
				findByName(arr, t, key, vectorEmp);
				if (vectorEmp.size() == 0) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
				else {
					for (int i = 0; i < vectorEmp.size(); i++)
					{
						cout << vectorEmp[i] << endl;
					}
				}
			}
			break;
			case 3:
			{
				int x;
				cout << "Nhap muc luong: ";
				cin >> x;
				vector<Employee> employees;
				findBySalary(arr, t, x, employees);
				if (employees.size() == 0) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
				else {
					for (int i = 0; i < employees.size(); i++)
					{
						cout << employees[i] << endl;
					}
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
				findBySalaryInRange(arr, t, x, y, result);
				if (result.size() == 0) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
				else {
					for (int i = 0; i < result.size(); i++)
					{
						cout << result[i] << endl;
					}
				}
			}
				break;
			case 5:
				sort(arr.begin(), arr.end(), compareTotal);
			case 6:
				cout << "====== Danh sach nhan vien ======\n";
				showElements(arr);
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
