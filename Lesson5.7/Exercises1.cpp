/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
	friend istream& operator >> (istream&, Employee&);
	friend ostream& operator << (ostream&, const Employee&);
private:
	string id;
	string first;
	string last;
	string mid;
	string major;
	long salary;
	float experience;
public:
	Employee(string id = "", string first = "", string last = "", string mid = "",
		string major = "", long salary = 0, float exp = 0) {
		setId(id);
		setFirstName(first);
		setLastName(last);
		setMidName(mid);
		setSalary(salary);
		setExperience(exp);
		setMajor(major);
	}

	void setId(string id) {
		this->id = id;
	}

	void setFirstName(string first) {
		this->first = first;
	}

	void setLastName(string last) {
		this->last = last;
	}

	void setMidName(string mid) {
		this->mid = mid;
	}

	void setMajor(string major) {
		this->major = major;
	}

	void setSalary(long salary) {
		this->salary = salary;
	}

	void setExperience(float exp) {
		this->experience = exp;
	}

	string getId() const {
		return id;
	}

	string getFirstName() const {
		return first;
	}

	string getLastName() const {
		return id;
	}

	string getMidName() const {
		return mid;
	}

	string getMajor() const {
		return major;
	}

	long getSalary() const {
		return salary;
	}

	float getExperience() const {
		return experience;
	}

	bool operator < (const Employee& e) const {
		return id.compare(e.id) < 0;
	}

	bool operator > (const Employee& e) const {
		return id.compare(e.id) > 0;
	}
};

istream& operator >> (istream& is, Employee& e) {
	cout << "Ma NV: ";
	is >> e.id;
	cout << "Ho: ";
	is >> e.last;
	cout << "Ten dem: ";
	is.ignore();
	getline(is, e.mid);
	cout << "Ten: ";
	is >> e.first;
	cout << "Chuyen mon: ";
	is.ignore();
	getline(is, e.major);
	cout << "Muc luong: ";
	is >> e.salary;
	cout << "So nam kinh nghiem: ";
	is >> e.experience;
	return is;
}

ostream& operator << (ostream& os, const Employee& e) {
	os << left << setw(10) << e.id << setw(10) << e.last
		<< setw(15) << e.mid << setw(10) << e.first
		<< setw(15) << e.major << setw(10) << e.salary
		<< setw(6) << e.experience << endl;
	return os;
}

int main()
{
	int choice;
	priority_queue<Employee, vector<Employee>, greater<Employee>> queue;
	do {
		cout << "<================== OPTIONS ==================>\n";
		cout << "1. Them moi mot nhan vien.\n";
		cout << "2. Xoa va tra ve nhan vien dau hang doi.\n";
		cout << "3. Lay nhan vien dau hang doi.\n";
		cout << "4. Cho biet so luong nhan vien hien co.\n";
		cout << "5. Hien thi danh sach nhan vien hien co.\n";
		cout << "6. Kiem tra hang doi rong.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Cam on quy vi da su dung dich vu ==>\n";
			break;
		case 1:
		{
			Employee e;
			cin >> e;
			queue.push(e);
			break;
		}
		case 2: 
		{
			if (!queue.empty()) {
				Employee top = queue.top();
				queue.pop();
				cout << "<== Thong tin nhan vien vua xoa ==>\n";
				cout << top;
			}
			else {
				cout << "Queu rong.\n";
			}
			break;
		}
		case 3:
			if (!queue.empty()) {
				cout << "<== Thong tin nhan vien dau hang doi ==>\n";
				cout << queue.top();
			}
			else {
				cout << "Queu rong.\n";
			}
			break;
		case 4:
			cout << "So luong nhan vien hien co trong queue: " << queue.size() << endl;
			break;
		case 5:
			if (!queue.empty()) {
				cout << "<== Danh sach nhan vien hien co trong hang doi ==>\n";
				while (!queue.empty()) {
					cout << queue.top();
					queue.pop();
				}
			}
			else {
				cout << "Queu rong.\n";
			}
			break;
		case 6:
			cout << boolalpha << "hang doi rong ? " << queue.empty() << endl;
			break;
		default:
			cout << "Sai chuc nang. Vui long chon lai.\n";
			break;
		}
	} while (choice != 0);
}