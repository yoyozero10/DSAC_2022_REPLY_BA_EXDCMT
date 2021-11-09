﻿/**
*	@author:	Branium Academy
*	@version:	2021.11
*	@see:		https://braniumacademy.net
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// hàm sàng xuống
template<class T> void siftDown(T* arr, int n, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != index) {
		swap(arr[index], arr[largest]);
		siftDown(arr, n, largest);
	}
}

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

// sắp xếp bubble sort tối ưu
template<class T> void bubbleSortOpt(T* arr, size_t size) {
	bool isSwapped;
	size_t i = size - 1;
	while (i > 0) {
		isSwapped = false;
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			break;
		}
		else {
			i--;
		}
	}
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

	bool operator > (const Employee& emp) {
		if (salary > emp.salary) {
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
		bubbleSortOpt(arr, t); // sắp xếp 
		showElements(arr, t);
		delete[] arr; // thu hồi bộ nhớ cấp phát động
	}
	else {
		cout << "<== Khong mo duoc file. Vui long kiem tra lai! ==>\n";
	}

	return 0;
}
