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
using namespace std;

// hàm hiển thị các phần tử mảng
template<class T> void showElements(T* arr, int n) {
	cout << left << setw(12) << "Ma NV" << setw(10) << "Ho"
		<< setw(12) << "Dem" << setw(10) << "Ten"
		<< setw(12) << "Luong" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
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

	string getId() {
		return id;
	}

	string getFirst() {
		return first;
	}

	string getLast() {
		return last;
	}

	string getMid() {
		return mid;
	}

	long getSalary() {
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
};

ostream& operator << (ostream& os, const Employee& e) {
	os << left << setw(12) << e.id << setw(10) << e.last
		<< setw(12) << e.mid << setw(10) << e.first
		<< setw(12) << e.salary << endl;
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

// thuật toán trộn
template<class T> void merge(T* arr, int first, int middle, int last) {
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
		if (leftArr[i] >= rightArr[j]) {
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
template<class T> void mergeSort(T* arr, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergeSort(arr, first, middle);
		mergeSort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
}

int main() {
	int t; // số bộ test
	ifstream ifs("INPUT.DAT");
	if (ifs) {
		ifs >> t; // đọc số bộ test
		ifs.ignore();
		Employee* arr = new Employee[t];
		for (int i = 0; i < t; i++) {
			string str;
			getline(ifs, str);
			createEmployee(str, arr[i]);
		}
		ifs.close();
		int choice = 0;
		do
		{
			cout << "================= OPTIONS =================\n";
			cout << "1. Tim nhan vien theo ma NV.\n";
			cout << "2. Tim nhan vien theo ten gan dung.\n";
			cout << "3. Tim nhan vien co muc luong x.\n";
			cout << "4. Tim nhan vien co muc luong trong doan [x, y].\n";
			cout << "5. Sap xep danh sach nhan vien theo luong.\n";
			cout << "6. Hien thi danh sach nhan vien hien co.\n";
			cout << "0. Thoat chuong trinh.\n";
			cout << "Lua chon cua ban? ";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "<=== CAM ON QUY KHACH ===>\n";
				break;
			case 1:
			{
				string id;
				cout << "Nhap ma nhan vien: ";
				cin >> id;
				bool found = false;
				for (int i = 0; i < t; i++) {
					if (arr[i].getId().compare(id) == 0) {
						cout << "=== TIM THAY ===\n";
						found = true;
						cout << arr[i] << endl;
						break;
					}
				}
				if (!found) {
					cout << "Khong tim thay nhan vien ma \"" << id << "\".\n";
				}
			}
				break;
			case 2:
			{
				string key;
				cout << "Nhap ten can tim: ";
				cin >> key;
				bool found = false;
				for (int i = 0; i < t; i++)
				{
					if (arr[i].getFirst().find(key) != string::npos ||
						arr[i].getMid().find(key) != string::npos ||
						arr[i].getLast().find(key) != string::npos) {
						found = true;
						cout << arr[i];
					}
				}
				if (!found) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
			}
				break;
			case 3:
			{
				int x;
				cout << "Nhap muc luong: ";
				cin >> x;
				bool found = false;
				for (int i = 0; i < t; i++)
				{
					if (arr[i].getSalary() == x) {
						found = true;
						cout << arr[i];
					}
				}
				if (!found) {
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
				bool found = false;
				for (int i = 0; i < t; i++)
				{
					if (arr[i].getSalary() >= x && arr[i].getSalary() <= y) {
						found = true;
						cout << arr[i];
					}
				}
				if (!found) {
					cout << "=== KHONG TIM THAY KET QUA ===\n";
				}
			}
			break;
			case 5:
				mergeSort(arr, 0, t - 1);
				break;
			case 6:
				cout << "====== Danh sach nhan vien ======\n";
				showElements(arr, t);
				break;
			default:
				cout << "Sai lua chon. Vui long chon lai!\n";
				break;
			}
		} while (choice != 0);
		delete[] arr; // thu hồi bộ nhớ cấp phát động
	}
	else {
		cout << "<== Khong mo duoc file. Vui long kiem tra lai! ==>\n";
	}

	return 0;
}
